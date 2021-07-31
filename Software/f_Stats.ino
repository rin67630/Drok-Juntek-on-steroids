void statsRun()
{

  persistence.HourVSum += dashboard.Vout;
  persistence.HourISum += dashboard.Iout;
  persistence.HourWSum += dashboard.Wout;
  persistence.HourSamples ++;
  
  persistence.CycleVSum += dashboard.Vout;
  persistence.CycleISum += dashboard.Iout;
  persistence.CycleWSum += dashboard.Wout;
  persistence.CycleSamples ++;

  if (MinuteExpiring)
  {
    RunHour = persistence.CycleSamples / 3600;
    RunMin = (persistence.CycleSamples / 60) - (60 * RunHour);
    sprintf(charbuff, " %02ih%02i ", RunHour, RunMin); Runtime = charbuff;  //save runtime as text XXhYY

    Vavgout = persistence.HourVSum / persistence.HourSamples;
    Ahout   = persistence.HourISum / persistence.HourSamples;
    Whout   = persistence.HourWSum / persistence.HourSamples;
    
    if ( persistence.AhMode == STOP)
    {
      dashboard.VoutAvg = Vavgout;
      dashboard.Ahout   = Ahout;        // Ah is from the current Hour
      dashboard.Whout   = Whout;        // Wh is from the current Hour
      persistence.CycleSamples = persistence.CycleVSum = persistence.CycleISum = persistence.CycleWSum  = 0;
    } else {
      dashboard.VoutAvg = persistence.CycleVSum / persistence.CycleSamples;
      dashboard.Ahout   = persistence.CycleISum / persistence.CycleSamples;        // Ah is from the current cycle
      dashboard.Whout   = persistence.CycleWSum / persistence.CycleSamples;        // Wh is from the current cycle
    }
  }
  if (HourExpiring)
  {
    Ah[25] = Ah[Hour] = Ahout;
    Ah[26] = Ah[31] = 0;                    // today (0h->current hour)
    for  (byte n = 0; n < Hour; n++)
    {
      Ah[26] += Ah[n];              // integrating over the day
      Ah[31] = max(Ah[31], Ah[n]);          // max Ah harvested
    }

    VoutAvg[25] = VoutAvg[Hour] = Vavgout;
    VoutAvg[26] = 0;                         // today (0h->current hour)
    for  (byte n = 0; n < Hour; n++)
    {
      VoutAvg[26] += VoutAvg[n];
    }
    VoutAvg[26] = VoutAvg[26] / (Hour + 1) ;  //Averaging over the day.

    Wh[25] = Wh[Hour] = Whout;

    Wh[26] = Wh[31] = 0;                    // today (0h->current hour)
    for  (byte n = 0; n < Hour; n++)
    {
      Wh[26] = Wh[26] + Wh[n];              // integrating over the day
      Wh[31] = max(Wh[31], Wh[n]);          // max Wh harvested
    };
// resetting all values for the next hour cycle
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
  }
// Restting the cycle at the beginning of the new day.
  if (NewDay && persistence.AhMode == DAILY)  Ahout = Whout = persistence.CycleVSum = persistence.CycleISum = persistence.CycleWSum = persistence.CycleSamples = 0;
}
