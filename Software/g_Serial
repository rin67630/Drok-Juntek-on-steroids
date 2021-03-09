void serialRun()
{
  yield();
  if (DayExpiring && (serialPeriodicity == 'd')    ||
      HourExpiring && (serialPeriodicity == 'h')   ||
      MinuteExpiring && (serialPeriodicity == 'm') ||
      (serialPeriodicity == 's') || (serialPeriodicity == '!'))
  {
    switch (serialPage)
    {
      case 'E':   // Energy plot every
        Console1.printf("Vset:%06.3f Vout:%06.3f Iset:%06.3f Iout:%06.3f Wout:%+07.3f\n", dashboard.Vset, dashboard.Vout, dashboard.Iset, dashboard.Iout, dashboard.Wout);
        if (serialPeriodicity == '!') serialPage = 0; // One shot reset serial page.
        break;
      case 'W':   // ADC-PWM Report
        Console1.printf("A0Raw:%04i Vout:%06.3f A3Raw:%04i Iout:%06.3f CVinj:%04i Vset:%06.3f CCinj:%04i Iset:%06.3f \n" , A0Raw, dashboard.Vout, A3Raw, dashboard.Iout, CVinj, dashboard.Vset, CCinj, dashboard.Iset);
        if (serialPeriodicity == '!') serialPage = 0; // One shot reset serial page.
        break;      
      case '~':   // WiFi status report
        Console3.printf("RSSI:%d dBm\n", WiFi.RSSI());
        if (serialPeriodicity == '!') serialPage = 0; // One shot reset serial page.
        break;
    }  // end switch (serialPage)
  }
}
