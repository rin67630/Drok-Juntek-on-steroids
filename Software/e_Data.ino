void data125mSRun()
{
#if not defined (UDP_SLAVE)
  // === ( Measures)  ====

  ADC_VRaw = ADC_IRaw = ADC_PRaw =0;
  for  (byte n = 0; n < 5; n++)   // Vout measure
  {
    int m = analogRead(ADC_V);
    ADC_VRaw += constrain( m, lastADC_V - 2, lastADC_V + 2); // eliminate spikes
    delay (2);
  }
  ADC_VRaw = ADC_VRaw / 5;
  lastADC_V = ADC_VRaw;
  dashboard.Vout +=  (adc2vout(ADC_VRaw) - dashboard.Vout) / 8 ;  // 1rst order low pass filter

  for  (byte n = 0; n < 5; n++)   // Iout measure
  {
    int m = analogRead(ADC_I);
    ADC_IRaw += constrain( m, lastADC_I - 3, lastADC_I + 2); // eliminate spikes
    delay (2);
  }
  ADC_IRaw = ADC_IRaw / 5;
  lastADC_I = ADC_IRaw;
  dashboard.Iout +=  (adc2amp(ADC_IRaw) - dashboard.Iout) / 8 ;   // 1rst order low pass filter

    for  (byte n = 0; n < 5; n++)   // Vin measure
  {
    int m = analogRead(ADC_P);
    ADC_PRaw += constrain( m, lastADC_P - 2, lastADC_P + 2); // eliminate spikes
    delay (2);
  }
  ADC_PRaw = ADC_PRaw / 5;
  lastADC_P = ADC_PRaw;
  dashboard.Vin +=  (adc2vin(ADC_PRaw) - dashboard.Vin) / 8 ;  // 1rst order low pass filter


  // === ( Actions)  ====
  CVinj = volt2pwm(dashboard.Vset);
  CCinj = amp2pwm(dashboard.Iset);
  ledcWrite(0, CVinj);
  ledcWrite(3, CCinj);
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
