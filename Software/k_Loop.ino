void loop()
{
  // run when idle.
  yield();              //Yield for WiFi
  runEvery(125)         //125mS cf Every Macro in Functions
  {
    if (digitalRead(BUTTON_UP) && digitalRead(BUTTON_DOWN)) nothingPressed = millis();
    MillisMem = millis();
    RunMillis[0] = 0;
    menuRun();
    RunMillis[1] =  millis() - MillisMem;
    getEpoch();         // writes the Epoch (Numbers of seconds till 1.1.1970...
    getTimeData();      // get Second, Minute...Year.
    RunMillis[2] =  millis() - MillisMem;
    data125mSRun();
    RunMillis[3] =  millis() - MillisMem;
    delay(50);          // set as high as possible to save energy but low enough to get the tasks done.

    slice += 1;
    if (slice > 8) slice = 1;
    switch (slice)      // The tasks will run every second, but at at 125mS steps
    {
      case 1:
        RunMillis[4] =  millis() - MillisMem;
        data1SRun();
        RunMillis[5] =  millis() - MillisMem;
        break;
      case 2:
        SecondOfDay = Second + 60 * Minute + 3600 * Hour;  // 0 .. 84600
        if (Second == 0 )         // Starting a new Minute..
        {
          NewMinute = true;
          if (Minute == 0)        // Starting a new hour..
          {
            NewHour = true;
            if (Hour == 0)        // Starting a  new day..
            {
              NewDay = true;             
            }
          }
        }
        if (Second == 58 ) MinuteExpiring = true;
        if (Second == 59 )        // Finishing the Minute next second..
        {
          MinuteExpiring2 = true;
          if (Minute == 59)       // Finishing the hour..
          {
            HourExpiring = true;
            if (Hour == 23)       // Finishing the day..
            {
              DayExpiring = true;
            }
          }
        }
        RunMillis[6] =  millis() - MillisMem;
        statsRun();
        RunMillis[7] =  millis() - MillisMem;
        break;
      case 3:
        RunMillis[8] =  millis() - MillisMem;
        displayRun();
        RunMillis[9] =  millis() - MillisMem;
        break;
      case 4:
        ArduinoOTA.handle();
        break;
      case 5:
        RunMillis[10] =  millis() - MillisMem;
        serialRun();
        RunMillis[11] =  millis() - MillisMem;
        break;
      case 7:
        RunMillis[12] =  millis() - MillisMem;
        if (WiFi.status() == WL_CONNECTED) wirelessRun();
        RunMillis[13] =  millis() - MillisMem;
        break;
      case 8:          // Reinitializations and Timing report
        RunMillis[14] = max( RunMillis[14],RunMillis[1] - RunMillis[0]);  // Max Millis Menu
        RunMillis[15] = max( RunMillis[15],RunMillis[3] - RunMillis[2]);  // Max Millis 125mS Data
        RunMillis[16] = max( RunMillis[16],RunMillis[5] - RunMillis[4]);  // Max Millis 1S Data
        RunMillis[17] = max( RunMillis[17],RunMillis[7] - RunMillis[6]);  // Max Millis Stats
        RunMillis[18] = max( RunMillis[18],RunMillis[9] - RunMillis[8]);  // Max Millis Display
        RunMillis[19] = max( RunMillis[19],RunMillis[11] - RunMillis[10]);  // Max Millis Serial
        RunMillis[20] = max( RunMillis[20],RunMillis[13] - RunMillis[12]);  // Max Millis WiFi
        if (Second % 10 == 5)
        {
          // every 6 seconds
        }
        if (MinuteExpiring)
        {
          //Minutely
          if (HourExpiring)
          {
            //Hourly
            if (DayExpiring)
            {
              //Daily
            }
          }
        }
        NewMinute = false;
        MinuteExpiring = false;
        NewHour = false;
        HourExpiring = false;
        NewDay = false;
        DayExpiring = false;
        triglEvent = false;
        break;
    } // end Switch slice
  } // end Every 125mS
}
//end loop
