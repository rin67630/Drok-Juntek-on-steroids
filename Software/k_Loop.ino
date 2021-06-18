void loop()
{
  // run when idle.
  yield();              //Yield for WiFi
  runEvery(125)         //125mS cf Every Macro in Functions
  {
    if (digitalRead(BUTTON_UP) && digitalRead(BUTTON_DOWN)) nothingPressed = millis();
    menuRun();
    getEpoch();         // writes the Epoch (Numbers of seconds till 1.1.1970...
    getTimeData();      // get Second, Minute...Year.
    //    digitalWrite(STDLED, false);
    data125mSRun();
    //    digitalWrite(STDLED, true);
    delay(50);          // set as high as possible to save energy but low enough to get the tasks done.

    slice += 1;
    if (slice > 8) slice = 1;
    switch (slice)      // The tasks will run every second, but at at 125mS steps
    {
      case 1:
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
        if (Second == 58 )        // Finishing the Minute next second..
        {
          MinuteExpiring = true;
          if (Minute == 59)       // Finishing the hour..
          {
            HourExpiring = true;
            if (Hour == 23)       // Finishing the day..
            {
              DayExpiring = true;
            }
          }
        }
        break;
      case 2:
        //       digitalWrite(GRNLED, true);

        data1SRun();
        //       digitalWrite(GRNLED, false);
        break;
      case 3:
        displayRun();
        break;
      case 4:
        ArduinoOTA.handle();
        break;
      case 5:
        //       digitalWrite(BLULED, true);
        serialRun();
        //       digitalWrite(BLULED, false);
        break;
      case 7:
        //       digitalWrite(REDLED, true);
        if (WiFi.status() == WL_CONNECTED) wirelessRun();
        //       digitalWrite(REDLED, false);
        break;
      case 8:          // Reinitializations
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
