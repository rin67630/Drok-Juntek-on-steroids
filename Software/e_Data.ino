void data125mSRun()
{

  // === ( Measures)  ====


  A0Raw = A3Raw = 0;
  for  (byte n = 0; n < 5; n++)
  {
    int m = analogRead(A0);
    A0Raw += constrain( m, lastA0 - 3, lastA0 + 3); // eliminate spikes
    delay (2);
  }
  A0Raw = A0Raw / 5;
  lastA0 = A0Raw;
  dashboard.Vout +=  (adc2volt(A0Raw) - dashboard.Vout) / 8 ;  // 1rst order low pass filter


  for  (byte n = 0; n < 5; n++)
  {
    int m = analogRead(A3);
    A3Raw += constrain( m, lastA3 - 3, lastA3 + 3); // eliminate spikes
    delay (2);
  }
  A3Raw = A3Raw / 5;
  lastA3 = A3Raw;
  dashboard.Iout +=  (adc2amp(A3Raw) - dashboard.Iout) / 8 ;   // 1rst order low pass filter


  // === ( Actions)  ====
  CVinj = volt2pwm(dashboard.Vset);
  CCinj = amp2pwm(dashboard.Iset);
  ledcWrite(0, CVinj);
  ledcWrite(3, CCinj);

} // end 125msRun

void data1SRun()
{
  dashboard.Wout = dashboard.Vout * dashboard.Iout;
  persistance.Runtime ++;
  RunHour = persistance.Runtime / 3600;
  RunMin = persistance.Runtime / 60 - 60 * RunHour;

  currentInt += dashboard.Iout;
  nCurrent ++;

  CycleVInt += dashboard.Vout;
  CycleIInt += dashboard.Iout;
  CycleWInt += dashboard.Wout;
  nCycle ++;

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
