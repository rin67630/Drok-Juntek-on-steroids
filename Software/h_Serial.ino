void serialRun()
{
yield();
  if ((DayExpiring && (serialPeriodicity == 'd'))    ||
      (HourExpiring && (serialPeriodicity == 'h'))   ||
      (MinuteExpiring && (serialPeriodicity == 'm')) ||
      (serialPeriodicity == 's') || (serialPeriodicity == '!'))
  {
    switch (serialPage)
    {
      case 'E':   // Energy plot
        Console1.printf("SetVout:%06.3f Vout:%06.3f SetIout:%06.3f Iout:%06.3f Wout:%+07.3f\n", dashboard.SetVout, dashboard.Vout, dashboard.SetIout, dashboard.Iout, dashboard.Wout);
        if (serialPeriodicity == '!') serialPage = 0; // One shot reset serial page.
        break;
      case 'D':   // Debug Report
        // Console1.printf("ADC_VinRaw:%i Vin:%06.3f ADC_IinRaw:%i Iin:%06.3f \nADC_VoutRaw:%i Vout:%06.3f ADC_IoutRaw:%i Iout:%06.3f PWM_SetVout:%04i SetVout:%06.3f PWM_SetIout:%04i SetIout:%06.3f PWM_Fan:%04i \n" , ADC_VinRaw, dashboard.Vin, ADC_IinRaw, dashboard.Iin, ADC_VoutRaw, dashboard.Vout, ADC_IoutRaw, dashboard.Iout, PWM_SetVout, dashboard.SetVout, PWM_SetIout, dashboard.SetIout, PWM_Fan);
        // Console1.printf("Vin:%06.3f SetVin:%06.3f Iin:%06.3f Vout:%06.3f SetVout:%06.3f Iout:%06.3f SetIout:%06.3f ConIout:%06.3f I_Value %06.3f  CtrlMode:%02i\n" , dashboard.Vin, dashboard.SetVin, dashboard.Iin, dashboard.Vout, dashboard.SetVout, dashboard.Iout, dashboard.SetIout, dashboard.ConIout, I_value, dashboard.CtrlMode );
        Console1.printf("Vin:%06.3f SetVin:%06.3f ConVin:%06.3f Iout:%06.3f ConIout:%06.3f MPPT_voc:%06.3f  fractionVoc:%06.3f\n" , dashboard.Vin, dashboard.SetVin, dashboard.ConVin, dashboard.Iout, dashboard.ConIout, MPPT_voc,  fractionVoc);
        if (serialPeriodicity == '!') serialPage = 0; // One shot reset serial page.
        break;
      case 'J':   // Job Duration
         //Console1.printf("\nJob Durations(mS) Current - Max\nMenu:%03i - %03i\nFast:%03i - %03i\nSlow:%03i - %03i\nStat:%03i - %03i\nDisp:%03i - %03i\nSeri:%03i - %03i\nWifi:%03i - %03i\n", 
         //RunMillis[0], RunMillis[1], RunMillis[2], RunMillis[3], RunMillis[4], RunMillis[5], RunMillis[6], RunMillis[7], RunMillis[8], RunMillis[9], RunMillis[10], RunMillis[11], RunMillis[12], RunMillis[13]);
        Console1.printf("\nJob Durations(mS) Current - Max\nMenu:%03i - %03i \nFast:%03i - %03i\nSlow:%03i - %03i\nStat:%03i - %03i\nDisp:%03i - %03i\nSeri:%03i - %03i\nWifi:%03i - %03i\n", 
        RunMillis[1] - RunMillis[0], RunMillis[14], RunMillis[3] - RunMillis[2], RunMillis[15], RunMillis[5] - RunMillis[4], RunMillis[16], RunMillis[7] - RunMillis[6], RunMillis[17], 
        RunMillis[9] - RunMillis[8], RunMillis[18], RunMillis[11] - RunMillis[10], RunMillis[19], RunMillis[13] - RunMillis[12], RunMillis[20]);
        if (serialPeriodicity == '!') serialPage = 0; // One shot reset serial page.
        break;
      case 'S': // Summary
        sprintf(charbuff, " \nSummary Report for \n%s, %02d %s %04d ", DayName , Day , MonthName, Year);
        Console1.print(charbuff);
        Console1.printf("\nHour|    Ah   |    VoutAvg    |    Wh    |\n");
        for  (byte n = 0; n < 32; n++)
        {
          if (n == 24)
          {
            Console1.printf("Extra ""hours"" 25:H-1, 26:today, 27:D-1, 28:D-2..\n");
          }
          else
          {
            Console1.printf("%02u  | %+07.3f | %+07.3f | %+07.3f |\n", n, Ah[n], VoutAvg[n], Ah[n] * Wh[n]);
          }
        }
        serialPage = 0;
        break;
      case '~':   // WiFi status report
        Console1.print(" RRSI= ");   Console4.print(WiFi.RSSI()); sprintf(charbuff, "dB, IP= %03d.%03d.%03d.%03d\n",  ip[0], ip[1], ip[2], ip[3]);  Console4.printf(charbuff);        
        if (serialPeriodicity == '!') serialPage = 0; // One shot reset serial page.
        break;
    }  // end switch (serialPage)
    
  }
  //          console.printf("SetVout:%06.3f Vout:%06.3f SetIout:%06.3f Iout:%06.3f Wout:%+07.3f\n", dashboard.SetVout, dashboard.Vout, dashboard.SetIout, dashboard.Iout, dashboard.Wout);
}
