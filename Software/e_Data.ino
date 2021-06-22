void data125mSRun()
{
#if not defined (UDP_SLAVE) //else skip the whole 125mS processing


  // === ( Measures)  ====
#ifdef ADC_IS_ESP                //Sensing with own crappy ADCs (not recommended)
  ADC_VoutRaw = ADC_IoutRaw = ADC_VinRaw = 0;
  for  (byte n = 0; n < 5; n++)   // Vout measure
  {
    int m = analogRead(ADC_VOUT);
    ADC_VoutRaw += constrain( m, lastADC_Vout - 2, lastADC_Vout + 2); // eliminate spikes
    delay (2);
  }
  ADC_VoutRaw = ADC_VoutRaw / 5;
  for  (byte n = 0; n < 5; n++)   // Iout measure
  {
    int m = analogRead(ADC_IOUT);
    ADC_IoutRaw += constrain( m, lastADC_Iout - 3, lastADC_Iout + 2); // eliminate spikes
    delay (2);
  }
  ADC_IoutRaw = ADC_IoutRaw / 5;

  for  (byte n = 0; n < 5; n++)   // Vin measure
  {
    int m = analogRead(ADC_VOUTin);
    ADC_VinRaw += constrain( m, lastADC_Voutin - 2, lastADC_Voutin + 2); // eliminate spikes
    delay (2);
  }
  ADC_VinRaw = ADC_VinRaw / 5;
#endif

#ifdef ADC_IS_ADS1115             //Sensing with much better deicated ADC (highly recommended)
  adc.setVoltageRange_mV(ADS1115_RANGE_2048);
  adc.setCompareChannels(FB_Vout_PIN);
  adc.startSingleMeasurement();
  while (adc.isBusy()) {}
  ADC_VoutRaw = adc.getResult_mV();

  adc.setVoltageRange_mV(ADS1115_RANGE_2048);
  adc.setCompareChannels(FB_Vin_PIN);
  adc.startSingleMeasurement();
  while (adc.isBusy()) {}
  ADC_VinRaw = adc.getResult_mV();

  adc.setVoltageRange_mV(ADS1115_RANGE_0256);
  delay(5);
  adc.setCompareChannels(FB_Iin_PIN);
  adc.startSingleMeasurement();
  while (adc.isBusy()) {}
  ADC_IinRaw =  adc.getResult_mV() * -10;

  adc.setVoltageRange_mV(ADS1115_RANGE_4096);
  //adc.setAutoRange();
  adc.setCompareChannels(FB_Iout_PIN);
  adc.startSingleMeasurement();
  while (adc.isBusy()) {}
  ADC_IoutRaw = adc.getResult_mV();
#endif

#ifdef ADC_IS_SIMULATED          // Simulation of a solar operation on a battery to test displays/dashboards wo special hardware
  converted_VoutRaw += (dashboard.SetVout - converted_VoutRaw) / 10000;   // 1st order low pass filter on Vout
  converted_IoutRaw += (dashboard.SetIout - converted_IoutRaw ) / 50;    // 1st order low pass filter on Iout
  float mem = dashboard.Iout;
  dashboard.Iout = min( converted_IoutRaw, max(float(-0.05), (dashboard.SetVout - dashboard.Vout))) ;   // Current is voltage difference limited by Setpoint
  delta_current = dashboard.Iout - mem;
  mem = dashboard.Vout;
  dashboard.Vout = converted_VoutRaw + (dashboard.Iout - dashboard.SetIout) / 20 + dashboard.Iout / 100;    // Voltage gets a small influence from current
  delta_voltage = dashboard.Vout - mem;
  dashboard.Vin = 1.5 * dashboard.Vout - 3 * dashboard.Iout;
  dashboard.Iin = 0.8 * dashboard.Iout;
#else
  float mem = converted_VoutRaw;
  converted_VoutRaw = (float(ADC_VoutRaw) - FB_Vout_BIAS) * FB_Vout_RES ;
  delta_voltage =   converted_VoutRaw - mem;
  dashboard.Vout +=  (converted_VoutRaw  / 1000  - dashboard.Vout) / 8 ;  // 1rst order low pass filter
  mem = converted_IoutRaw;
  converted_IoutRaw = (float(ADC_IoutRaw) - FB_Iout_BIAS) * FB_Iout_RES  ;
  delta_current =   converted_IoutRaw - mem;
  dashboard.Iout +=  (converted_IoutRaw  / 1000 - dashboard.Iout) / 8 ;  // 1rst order low pass filter
  converted_VinRaw = (float(ADC_VinRaw) - FB_Vin_BIAS) * FB_Vin_RES  ;
  dashboard.Vin +=  (converted_VinRaw  / 1000 - dashboard.Vin) / 8 ;  // 1rst order low pass filter
  converted_IinRaw = (float(ADC_IinRaw) - FB_Iin_BIAS) * FB_Iin_RES  ;
  dashboard.Iin +=  (converted_IinRaw  / 1000 - dashboard.Iin) / 8 ;  // 1rst order low pass filter
#endif

  dashboard.ConVout = dashboard.SetVout;
  switch (dashboard.CtrlMode)
  {
    case MANU:  // fix voltage Fix current
      dashboard.ConIout = dashboard.SetIout;
      dashboard.ConVin  = dashboard.SetVin;
      break;
    case PVFX:  // fix panel voltage No break: continuing with case MPPT!
      VinSlow = dashboard.ConVin = dashboard.SetVin;
    case MPPT:  // maximum power point tracking Perturb and Observe
      dashboard.ConIout -= (dashboard.ConVin - dashboard.Vin) *  I_value / 1000;   // Integrative input voltage controller
      dashboard.ConIout = constrain(dashboard.ConIout, 0.1, dashboard.SetIout);
      break;
  }

  // === ( Fast Actions)  ====
  PWM_SetVout = dashboard.ConVout  * PWM_Vout_STEP + PWM_Vout_BIAS ;
  PWM_SetIout = dashboard.ConIout  * 10 * PWM_Iout_STEP + PWM_Iout_BIAS ;
  ledcWrite(4, PWM_Fan );      // PWM to fan control
  ledcWrite(0, PWM_SetVout);   // PWM to voltage control
  ledcWrite(3, PWM_SetIout);   // PWM to current control

#endif  //not defined (UDP_SLAVE)
} // end 125msRun


void data1SRun()
{

  // === (Getting measurment values from another ESP over UDP
#if defined (UDP_SLAVE)                                    // System is remote display from another system
  if (WiFi.status() == WL_CONNECTED)
  {
    // I am using a quick and dirty method called 'type punning' copying the memory block of a structure into an array of chars,
    // transmitting this array, and copying back the memory block of the array into the same structure on the other side.
    // I dont use any header info, only the difference of size permits to assign the received packets to sound or dashboard.
    // it is quick and damn efficient, but NOT portable and YOU must take care to have the same structures on both systems
    // and different sizes for Battery and Sound...

    int packetSize = UDP.parsePacket();
    Console1.printf("Rxbytes:%06i Dashboard:%06i \n", packetSize, sizeof(dashboard));
    if (packetSize == sizeof(dashboard))
    {
      UDP.read(dashboard_punning, UDP_TX_PACKET_MAX_SIZE);
      memcpy(&dashboard, dashboard_punning, sizeof(dashboard));
      delay(5);
    }
  }
#else  // if not defined (UDP_SLAVE)
  // === ( Slow Actions)  ====
  PWM_Fan = (dashboard.Iout - FAN_AMPS_0) * 2000 / (FAN_AMPS_100 - FAN_AMPS_0); //Y= (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
  PWM_Fan = constrain(PWM_Fan, 11 , 2000);
  digitalWrite(ENA_PIN, (dashboard.Vin < dashboard.Vout) );   //Shutdown the DC-DC controller if Vin < Vout
 
  VinSlow += (dashboard.Vin - VinSlow) / 30;  // Strong Low-pass filter of Vin to get a memory of last good Vin upon collapses
  if (dashboard.CtrlMode == MPPT)  // Adaptive MPPT
  {
    if (VinSlow - dashboard.Vin > collapseTreshold) //Collapse Detection  // temporarily increase the Vin setpoint
    {
      dashboard.ConVin = VinSlow + 1;                             // Reposition Vin setpoint to last good + 1V
      dashboard.ConIout = dashboard.ConIout * currentReduction;   // Halve current to catch back from the bottom
     // Console1.printf("Collapse prevention SetVin:%06.3f ", dashboard.ConVin);
    }
    //MPPT  classical perturb and observe algorithm
    dP  = dashboard.Wout - MPPT_last_power;
    dV  = dashboard.Vin - MPPT_last_voltage;
    MPPT_last_power = dashboard.Wout ;
    MPPT_last_voltage = dashboard.Vin;
    if (dashboard.Vout < dashboard.SetVout && dashboard.Iout < dashboard.SetIout)
    {
      if (dP > 0)
      {
        if (dV > 0)
        {
          dashboard.ConVin += MPPT_perturbe;
        } else {
          dashboard.ConVin -= MPPT_perturbe;
        }
      } else {
        if (dV > 0)
        {
          dashboard.ConVin -= MPPT_perturbe;
        } else {
          dashboard.ConVin += MPPT_perturbe;
        }
      }
    } else {
      // throttling power
      dashboard.ConVin = dashboard.SetVin;
    }
    dashboard.ConVin = constrain(dashboard.ConVin, (PANEL_MPP * 0.95), (PANEL_MPP * 1.2));
  }
#endif

  // === (Handling of output managment unit) ===
  pcf8574.digitalWrite(P0, HIGH);       // here Work in progress...

  // === ( Dashboard and Reporting)  ====
  dashboard.Wout = dashboard.Vout * dashboard.Iout;
  persistence.HourVSum += dashboard.Vout;
  persistence.HourISum += dashboard.Iout;
  persistence.HourWSum += dashboard.Iout * dashboard.Vout;
  persistence.HourSamples ++;
  Ahout = persistence.HourISum / 3600;
  Whout = persistence.HourWSum / 3600;
  Vavgout = persistence.HourVSum / persistence.HourSamples;
  if (persistence.AhMode > 0)
  {
    persistence.CycleVSum += dashboard.Vout;
    persistence.CycleISum += dashboard.Iout;
    persistence.CycleWSum += dashboard.Iout * dashboard.Vout;
    persistence.CycleSamples ++;
  }

  if (fabs(delta_current) > 50) raw_internal_resistance = fabs(delta_voltage / delta_current); // Evaluate battery internal resistance (r = dv / di) if deltaCurrent > 50mA.
  dashboard.load_internal_resistance += (raw_internal_resistance - dashboard.load_internal_resistance) / 100;

  dashboard.VoutAvg = persistence.CycleVSum / persistence.CycleSamples;

  if (MinuteExpiring)
  {
    switch (persistence.AhMode)
    {
      case 1:
      case 2:
        RunHour = persistence.CycleSamples / 3600;
        RunMin = (persistence.CycleSamples / 60) - (60 * RunHour);
        sprintf(charbuff, " %02ih%02i ", RunHour, RunMin); Runtime = charbuff;  //save runtime as text XXhYY
        dashboard.Ahout = persistence.CycleISum / 3600;        // Ah is from the current cycle
        dashboard.Whout = persistence.CycleWSum / 3600;        // Wh is from the current cycle
        dashboard.VoutAvg = persistence.CycleVSum / persistence.CycleSamples;
        break;
      case 0:
        Runtime = "Stop ";
        dashboard.Ahout = dashboard.Whout = persistence.CycleSamples = persistence.CycleVSum = persistence.CycleISum = persistence.CycleWSum = 0;
        break;
    }
  }
  if (HourExpiring)
  {
    Ah[25] = Ah[Hour] = persistence.HourISum / persistence.HourSamples;
    Ah[26] = Ah[31] = 0;                    // today (0h->current hour)
    for  (byte n = 0; n < Hour; n++)
    {
      Ah[26] += Ah[n];              // integrating over the day
      Ah[31] = max(Ah[31], Ah[n]);          // max Ah harvested
    }

    VoutAvg[25] = VoutAvg[Hour] = persistence.HourVSum / persistence.HourSamples;
    VoutAvg[26] = 0;                         // today (0h->current hour)
    for  (byte n = 0; n < Hour; n++)
    {
      VoutAvg[26] += VoutAvg[n];
    }
    VoutAvg[26] = VoutAvg[26] / (Hour + 1) ;  //Averaging over the day.

    Wh[25] = Wh[Hour] = persistence.HourWSum / persistence.HourSamples;

    Wh[26] = Wh[31] = 0;                    // today (0h->current hour)
    for  (byte n = 0; n < Hour; n++)
    {
      Wh[26] = Wh[26] + Wh[n];              // integrating over the day
      Wh[31] = max(Wh[31], Wh[n]);          // max Wh harvested
    };
    persistence.HourVSum = persistence.HourISum = persistence.HourWSum = persistence.HourSamples = 0;
  } // end hour expiring

  if (DayExpiring)                          // trace of the last 4 days
  {
    //Keeping history of the last 5 days
    Ah[27] = Ah[26];
    Ah[28] = Ah[27];
    Ah[29] = Ah[28];
    Ah[30] = Ah[29];
    VoutAvg[27] = VoutAvg[26];
    VoutAvg[28] = VoutAvg[27];
    VoutAvg[29] = VoutAvg[28];
    VoutAvg[30] = VoutAvg[29];
    Wh[27] = Wh[26];
    Wh[28] = Wh[27];
    Wh[29] = Wh[28];
    Wh[30] = Wh[29];

    persistence.voltageDelta = dashboard.Vout - persistence.voltageAt0H; // set ranges at 33:53:59
    persistence.voltageAt0H  = dashboard.Vout;  // taking the voltage at 23:55 to evaluate if the battery gained/lost during the previous day

    if (persistence.AhMode == 2)  // Restting the cycle at the end of the day.
    {
      persistence.CycleVSum = persistence.CycleISum = persistence.CycleWSum = persistence.CycleSamples = 0;
    }
  }
} // end of 1S run
