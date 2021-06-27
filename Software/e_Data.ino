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

#ifdef ADC_IS_ADS1115             //Sensing with much better dedicated ADC (highly recommended)
  adc.setVoltageRange_mV(ADS1115_RANGE_2048);
  adc.setCompareChannels(FB_Vout_PIN);
  adc.startSingleMeasurement();
  while (adc.isBusy()) {
    yield();
  }
  ADC_VoutRaw = adc.getResult_mV();

  adc.setVoltageRange_mV(ADS1115_RANGE_4096);
  adc.setCompareChannels(FB_Iout_PIN);
  adc.startSingleMeasurement();
  while (adc.isBusy()) {
    yield();
  }
  ADC_IoutRaw = adc.getResult_mV();

  adc.setVoltageRange_mV(ADS1115_RANGE_2048);
  adc.setCompareChannels(FB_Vin_PIN);
  adc.startSingleMeasurement();
  while (adc.isBusy()) {
    yield();
  }
  ADC_VinRaw = adc.getResult_mV();

  adc.setVoltageRange_mV(ADS1115_RANGE_0256);
  adc.setCompareChannels(FB_Iin_PIN);
  adc.startSingleMeasurement();
  while (adc.isBusy()) {
    yield();
  }
  ADC_IinRaw =  adc.getResult_mV() * -10;

#endif


#ifdef ADC_IS_SIMULATED          // Simulation of a solar operation on a battery to test displays/dashboards wo special hardware
  converted_VoutRaw += (dashboard.SetVout - converted_VoutRaw) / 10000;   // 1st order low pass filter on Vout
  converted_IoutRaw += (dashboard.SetIout - converted_IoutRaw ) / 50;    // 1st order low pass filter on Iout
  float mem = dashboard.Iout;
  dashboard.Iout = min( converted_IoutRaw, max(float(-0.05), (dashboard.SetVout - dashboard.Vout))) ;      // Current is voltage difference limited by Setpoint
  delta_current = dashboard.Iout - mem;
  mem = dashboard.Vout;
  dashboard.Vout = converted_VoutRaw + (dashboard.Iout - dashboard.SetIout) / 20 + dashboard.Iout / 100;   // Voltage gets a small influence from current
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
  dashboard.Iout +=  (converted_IoutRaw  / 1000 - dashboard.Iout) / 8 ;   // 1rst order low pass filter
  converted_VinRaw = (float(ADC_VinRaw) - FB_Vin_BIAS) * FB_Vin_RES  ;
  dashboard.Vin +=  (converted_VinRaw  / 1000 - dashboard.Vin) / 8 ;      // 1rst order low pass filter
  converted_IinRaw = (float(ADC_IinRaw) - FB_Iin_BIAS) * FB_Iin_RES  ;
  dashboard.Iin +=  (converted_IinRaw  / 1000 - dashboard.Iin) / 8 ;      // 1rst order low pass filter
#endif

  dashboard.ConVout = dashboard.SetVout;
  switch (dashboard.CtrlMode)
  {
    case MANU:  // fix voltage Fix current
      dashboard.ConIout = dashboard.SetIout;
      dashboard.ConVin  = dashboard.SetVin;
      break;
    case PVFX:  // fix panel voltage No break: continuing with case MPPT!
      MPPT_voc = VinSlow = dashboard.ConVin = dashboard.SetVin;
    case MPPT:  // maximum power point tracking Perturb and Observe
      dashboard.ConIout -= (dashboard.ConVin - dashboard.Vin) *  I_value / 1000;   // Integrative input voltage controller
      dashboard.ConIout = constrain(dashboard.ConIout, 0.03, dashboard.SetIout);
      break;
  }

  // === ( Fast PWM Control )  ====
  PWM_SetVout = dashboard.ConVout  * PWM_Vout_STEP + PWM_Vout_BIAS ;
  PWM_SetIout = dashboard.ConIout  * 10 * PWM_Iout_STEP + PWM_Iout_BIAS ;
  ledcWrite(4, PWM_Fan );      // PWM to fan control
  ledcWrite(0, PWM_SetVout);   // PWM to voltage control
  ledcWrite(3, PWM_SetIout);   // PWM to current control

#endif  //not defined (UDP_SLAVE)
} // end 125msRun


void data1SRun()
{
  // === (Getting measurement values from another ESP over UDP  ===
#if defined (UDP_SLAVE)                                    // System is remote display from another system
  if (WiFi.status() == WL_CONNECTED)
  {
    // I am using a quick and dirty method called 'type punning' copying the memory block of a structure into an array of chars,
    // transmitting this array, and copying back the memory block of the array into the same structure on the other side.
    // I dont use any header info, only the difference of size permits to assign the received packets where they belong.
    // it is quick and damn efficient, but NOT portable and YOU must take care to have the same structures on both systems
    // and different sizes if you use several messages...

    int packetSize = UDP.parsePacket();
    Console1.printf("Rxbytes:%06i Dashboard:%06i \n", packetSize, sizeof(dashboard));
    if (packetSize == sizeof(dashboard))
    {
      UDP.read(dashboard_punning, UDP_TX_PACKET_MAX_SIZE);
      memcpy(&dashboard, dashboard_punning, sizeof(dashboard));
      delay(5);
    }
  }
#else


  // if not defined (UDP_SLAVE)
  // === ( Slower PWM Control )  ====
  PWM_Fan = (dashboard.Iout - FAN_AMPS_0) * 2000 / (FAN_AMPS_100 - FAN_AMPS_0); //Y= (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min
  PWM_Fan = constrain(PWM_Fan, 11 , 2000);
  digitalWrite(ENA_PIN, (dashboard.Vin < dashboard.Vout) );   //Shutdown the DC-DC controller if Vin < Vout

  //  === ( Repeated Collapse prevention and Initial Ramp-Up ) ===
  VinSlow  += (dashboard.Vin - VinSlow) / 30;    // Strong Low-pass filter of Vin to get a memory of last good Vin upon collapses
  IoutSlow += (dashboard.Iout - IoutSlow) / 30;  // Strong Low-pass filter of Iout to get a memory of last Iout before collapses
  if (dashboard.CtrlMode == MPPT)  // Adaptive MPPT
  {
    if (VinSlow - dashboard.Vin > collapseTreshold) //Collapse Detection  // temporarily increase the Vin setpoint
    {
      dashboard.ConIout = 0;   // Cut current to catch back from the bottom and measure Voc
      collapseTimer = 0;
    }
    if (collapseTimer < 64000) ++ collapseTimer;
    if (collapseTimer < 10) MPPT_voc = max(MPPT_voc, dashboard.Vin) ; // Compute Voc
    else if (collapseTimer < 12 ) dashboard.ConVin = MPPT_voc * fractionVoc; // VinSetpoint set to Fractional Voc
    else if (collapseTimer < 15 ) dashboard.ConIout = IoutSlow;              // Restore 90% of current before collapse
    // Stay 5 minutes with this settings before returning to classical MPPT
    else if (collapseTimer > 300 )
    { //  === ( MPPT  classical perturb and observe algorithm ) ===
      dP  = dashboard.Wout - MPPT_last_power;
      dV  = dashboard.Vin - MPPT_last_voltage;
      MPPT_voc = VinSlow;
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
          if (dV >= 0)
          {
            dashboard.ConVin -= MPPT_perturbe;
          } else {
            dashboard.ConVin += MPPT_perturbe;
          }
        }
      } else {
        // throttling power, no MPPT required.
        dashboard.ConVin = dashboard.SetVin;
      }
      if (NewMinute && dashboard.ConVin >= dashboard.SetVin * 1.10) dashboard.ConVin = dashboard.SetVin; // Preventing latchups at high Vin.
    }
    dashboard.ConVin = constrain(dashboard.ConVin, (dashboard.SetVin * 0.92), (dashboard.SetVin * 1.10));
  }

#endif

#ifdef FET_EXTENSION
  // === (Handling of output managment unit) ===
  pcf8574.digitalWrite(P0, Out_IExt0);       // here Work in progress...
  pcf8574.digitalWrite(P1, Out_IExt1);
  pcf8574.digitalWrite(P2, Out_IExt2);
  pcf8574.digitalWrite(P3, Out_IExt3);

  adc2.setVoltageRange_mV(ADS1115_RANGE_0256);
  adc2.setCompareChannels(ADS1115_COMP_0_GND);
  adc2.startSingleMeasurement();
  while (adc2.isBusy()) {}
  ADC_IExt0 = adc2.getResult_mV();

  adc2.setVoltageRange_mV(ADS1115_RANGE_0256);
  adc2.setCompareChannels(ADS1115_COMP_1_GND);
  adc2.startSingleMeasurement();
  while (adc2.isBusy()) {}
  ADC_IExt1 = adc2.getResult_mV();

  adc2.setVoltageRange_mV(ADS1115_RANGE_0256);
  delay(5);
  adc2.setCompareChannels(ADS1115_COMP_2_GND);
  adc2.startSingleMeasurement();
  while (adc2.isBusy()) {}
  ADC_IExt2 =  adc2.getResult_mV() * -10;

  adc2.setVoltageRange_mV(ADS1115_RANGE_0256);
  //adc2.setAutoRange();
  adc2.setCompareChannels(ADS1115_COMP_3_GND);
  adc2.startSingleMeasurement();
  while (adc2.isBusy()) {}
  ADC_IExt3 = adc2.getResult_mV();
#endif  //FET_EXTENSION

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
} // end of 1S run
