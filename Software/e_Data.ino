void data125mSRun()
{
#if not defined (UDP_SLAVE)
  // === ( Measures)  ====

#ifdef ADC_IS_ESP
  ADC_VoutRaw = ADC_IoutRaw = ADC_VinRaw =0;
  for  (byte n = 0; n < 5; n++)   // Vout measure
  {
    int m = analogRead(ADC_V);
    ADC_VoutRaw += constrain( m, lastADC_Vout - 2, lastADC_Vout + 2); // eliminate spikes
    delay (2);
  }
  ADC_VoutRaw = ADC_VoutRaw / 5;
  lastADC_Vout = ADC_VoutRaw;
  dashboard.Vout +=  (adc2vout(ADC_VoutRaw) - dashboard.Vout) / 8 ;  // 1rst order low pass filter

  for  (byte n = 0; n < 5; n++)   // Iout measure
  {
    int m = analogRead(ADC_I);
    ADC_IoutRaw += constrain( m, lastADC_Iout - 3, lastADC_Iout + 2); // eliminate spikes
    delay (2);
  }
  ADC_IoutRaw = ADC_IoutRaw / 5;
  lastADC_Iout = ADC_IoutRaw;
  dashboard.Iout +=  (adc2amp(ADC_IoutRaw) - dashboard.Iout) / 8 ;   // 1rst order low pass filter

    for  (byte n = 0; n < 5; n++)   // Vin measure
  {
    int m = analogRead(ADC_Vin);
    ADC_VinRaw += constrain( m, lastADC_Voutin - 2, lastADC_Voutin + 2); // eliminate spikes
    delay (2);
  }
  ADC_VinRaw = ADC_VinRaw / 5;
  lastADC_Voutin = ADC_VinRaw;
  dashboard.Vin +=  (adc2vin(ADC_VinRaw) - dashboard.Vin) / 8 ;  // 1rst order low pass filter 
#endif


#ifdef ADC_IS_ADS1115
  adc.setVoltageRange_mV(ADS1115_RANGE_2048);
  adc.setCompareChannels(FB_Vout_PIN);
  adc.startSingleMeasurement();
  while(adc.isBusy()){}
  ADC_VoutRaw = adc.getResult_mV();
  converted_VoutRaw = (float(ADC_VoutRaw) - FB_Vout_BIAS) * FB_Vout_RES ;  
  dashboard.Vout +=  (converted_VoutRaw  / 1000  - dashboard.Vout) / 8 ;  // 1rst order low pass filter

  adc.setVoltageRange_mV(ADS1115_RANGE_2048);
  adc.setCompareChannels(FB_Iout_PIN);
  adc.startSingleMeasurement();
  while(adc.isBusy()){}
  ADC_IoutRaw = adc.getResult_mV();
  converted_IoutRaw = (float(ADC_IoutRaw) - FB_Iout_BIAS) * FB_Iout_RES / 10 ;     
  dashboard.Iout +=  (converted_IoutRaw  / 1000 - dashboard.Iout) / 8 ;  // 1rst order low pass filter

  adc.setVoltageRange_mV(ADS1115_RANGE_2048);
  adc.setCompareChannels(FB_Vin_PIN);
  adc.startSingleMeasurement();
  while(adc.isBusy()){}
  ADC_VinRaw = adc.getResult_mV();
  converted_VinRaw = (float(ADC_VinRaw) - FB_Vin_BIAS) * FB_Vin_RES  ;   
  dashboard.Vin +=  (converted_VinRaw  / 1000 - dashboard.Vin) / 8 ;  // 1rst order low pass filter
#endif

  // === ( Actions)  ====
  PWM_Vset = dashboard.Vset  * PWM_Vout_STEP + PWM_Vout_BIAS ;
  PWM_Cset = dashboard.Iset  * 10 * PWM_Iout_STEP + PWM_Iout_BIAS ;
  ledcWrite(0, PWM_Vset);
  ledcWrite(3, PWM_Cset);
#endif
} // end 125msRun

void data1SRun()
{

  // === (Getting measurment values from another ESP over UDP
#if defined (UDP_SLAVE)
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
#endif
  
  dashboard.Wout = dashboard.Vout * dashboard.Iout;
  persistance.Runseconds ++;
  RunHour = persistance.Runseconds / 3600;
  RunMin = persistance.Runseconds / 60 - 60 * RunHour;
  sprintf(charbuff, " %02ih%02i ", RunHour, RunMin); Runtime = charbuff;
  persistance.Ahout = CycleIInt / 3600;
  persistance.Whout = CycleWInt / 3600;
  

  currentInt += dashboard.Iout;
  nCurrent ++;

  CycleVInt += dashboard.Vout;
  CycleIInt += dashboard.Iout;
  CycleWInt += dashboard.Wout;
  nCycle ++;

  if (DayExpiring)
  {

  }

  if (HourExpiring)
  {
    Ah[Hour] = currentInt / nCurrent;
    nCurrent = 0;
    currentInt = 0;
    Ah[25] = Ah[Hour];   //last hour
    Ah[26] = 0;              // today (0h->current hour)
    for  (byte n = 0; n < Hour; n++)
    {
      Ah[26] = Ah[26] + Ah[n];
    }
    Vh[Hour] = dashboard.Vout;
    Vh[25] = dashboard.Vout;
    Vh[26] = 0;              // today (0h->current hour)
    for  (byte n = 0; n < Hour; n++)
    {
      Vh[26] = Vh[26] + Vh[n];
    }
    Vh[26] = Vh[26] / (Hour + 1) ;
  } // end hour expiring

  if (DayExpiring)
  {
    Ah[27] = Ah[26];
    Ah[28] = Ah[27];
    Ah[29] = Ah[28];
    Ah[30] = Ah[29];
    Vh[27] = Vh[26];
    Vh[28] = Vh[27];
    Vh[29] = Vh[28];
    Vh[30] = Vh[29];
  }
} // end of 1S run
