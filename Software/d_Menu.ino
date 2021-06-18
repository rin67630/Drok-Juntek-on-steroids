void menuRun()
{
  //  if (Year < 2020) setTimefromSerial();

  if (Console0.available())   inbyte = Console0.read(); //Serial input available
  /*
    Wire.requestFrom(0x08, 1)
    while (Wire.available())
    {
      inbyte = = Wire.read();                  // receive a byte as character
      if (key_val != 0) {
        if (key_val >= 0x20 && key_val < 0x7F) { // ASCII String
          Serial.print((char)key_val);
        } else {
          Serial.printf("0x%02X ", key_val);
        }
      }
    }
  */

// Process rotary switch

  switch (displayPage)
  {
    case 0 :
      setBrightness (0);
      break;
  }


  switch (inbyte)
  {
    //====(Serial Menu)======

    // *** Actions***
    case '0': //Display mode 0
      displayPage = 0;
      tft.fillScreen(TFT_BLACK);
      Console1.printf ("Off\n");
      break;
    case '1': //Display mode 1
      cycleDisplay = false;
      displayPage = 1;
      tft.fillScreen(TFT_BLACK);
      Console1.printf ("D=1\n");
      break;
    case '2': //Display mode 2
      cycleDisplay = false;
      displayPage = 2;
      tft.fillScreen(TFT_BLACK);
      Console1.printf ("D=2\n");
      break;
    case '3': //Display mode 3
      cycleDisplay = false;
      displayPage = 3;
      tft.fillScreen(TFT_BLACK);
      Console1.printf ("D=3\n");
      break;
    case '4': //Display mode 4
      cycleDisplay = false;
      displayPage = 4;
      tft.fillScreen(TFT_BLACK);
      Console1.printf ("D=4\n");
      break;
    case '5': //Display mode 5
      cycleDisplay = false;
      displayPage = 5;
      tft.fillScreen(TFT_BLACK);
      Console1.printf ("D=5\n");
      break;
    case '9': //Cycle Displays
      cycleDisplay = true;
      tft.fillScreen(TFT_BLACK);
      Console1.printf ("Cycling displays\n");
      break;   
    case '%':  //toggle between coarse/fine settings for "+,-,<,>"
      coarse = not coarse;
      Console1.printf ("%s \n", coarse ? "coarse" : "fine");
      break;
    case '+': //Increase Volt
      //PWM_SetVout += 10;
      //Console1.printf ("+1 Vinj=%i Vadc=%i\n", PWM_SetVout, ADC_VoutRaw);
      if (coarse) dashboard.SetVout += 0.1;
      if (not coarse) dashboard.SetVout += 0.01;
      Console1.printf ("%s Volt=%06.3f\n", coarse ? "++" : "+", dashboard.SetVout);
      break;
    case '-': //Reduce Volt
      //PWM_SetVout -= 10;
      //Console1.printf ("-1 Vinj=%i Vadc=%i\n", PWM_SetVout, ADC_VoutRaw);
      if (coarse && dashboard.SetVout >= 0.1) dashboard.SetVout -= 0.1;
      if (not coarse && dashboard.SetVout >= 0.01) dashboard.SetVout -= 0.01;
      Console1.printf ("%s Volt=%06.3f\n", coarse ? "--" : "-", dashboard.SetVout);
      break;
    case '>': //Increase Amp
      //PWM_SetIout += 10;
      //Console1.printf ("+1 Cinj=%i Iadc=%i\n", PWM_SetIout,ADC_IoutRaw);
      if (coarse) dashboard.SetIout += 0.05;
      if (not coarse) dashboard.SetIout += 0.001;
      Console1.printf ("%s Amp=%06.3f\n", coarse ? "++" : "+", dashboard.SetIout);
      break;
    case '<': //Reduce Amp
      //PWM_SetIout -= 10;
      //Console1.printf ("+1 Cinj=%i Iadc=%i\n", PWM_SetIout,ADC_IoutRaw);
      if (coarse && dashboard.SetIout >= 0.05) dashboard.SetIout -= 0.05;
      if (not coarse && dashboard.SetIout >= 0.001) dashboard.SetIout -= 0.001;
      Console1.printf ("%s Amp=%06.3f\n", coarse ? "--" : "-", dashboard.SetIout);
      break;
    case 'Z':  // Write persistence and Reset
      for ( int i = 0; i < sizeof(persistence); ++i ) EEPROM.write ( i + 100,  persistence_punning[i] );
      EEPROM.commit();
      memcpy(persistence_punning, &persistence, sizeof(persistence));
      Console1.printf ("\nResetting in 10s...\n");
      delay(10000);
      ESP.restart();
      break;
    case 'z':  //Reset runtime
      Console1.printf ("\nRt:%06ui m, Ah:%06.3f Wh:%06.3f \n", persistence.CycleSamples, Ahout, Whout);
      Console1.printf ("\nResetting \n");
      persistence.HourSamples = 0;
      Ahout = Whout = 0;
      persistence.CycleVSum = persistence.CycleISum = persistence.CycleSamples = 0;
      persistence.initial_voltage = dashboard.Vout;
      thing.stream("status");
      break;
    case 'C': //Ah Cycle 0-1-2  Stop, Run, Daily
      persistence.AhMode  ++;
      if (persistence.AhMode  >= 2) persistence.AhMode  = 0;
      displayPage = 1;
      tft.fillScreen(TFT_BLACK);
      Console1.printf ("AhMode  changed to %i \n",persistence.AhMode );
      break;       
    // ***One shot Reports**
    case 'S':  //Summary Report
      Console1.printf ("\nSummary Report\n");
      serialPage = 'S';
      break;
    case 'D':  //Debug Report
      Console1.printf ("\nDebug Report\n");
      serialPage = 'D';
      break;
    case 'P': //Parameter List
      Console1.printf("Par.List \n Vout %6.2f CV %6.2f Iout %6.3f CC %6.3f", dashboard.Vout, dashboard.SetVout, dashboard.Iout, dashboard.SetIout );
      break;
    case 't': // Print time
      Console1.println(ctime(&now));
      break;
    case 'T': // Enter time
      //setTimefromSerial();
      break;
    case '~':  //Redio Report / WiFi
      Console1.printf ("\nWiFi Status\n");
      serialPage = '~';
      break;
    case 'W': // Write persistence data to EEPROM (Adress = 100...)
      for ( int i = 0; i < sizeof(persistence); ++i ) EEPROM.write ( i + 100,  persistence_punning[i] );
      EEPROM.commit();
      memcpy(persistence_punning, &persistence, sizeof(persistence));
      //persistence_punning[i] = EEPROM.read ( i + 100 );
      break;
    // ***Options for periodical Reports**
    case 'd': //Day Report
      serialPeriodicity = 'd';
      break;
    case 'h': //Hour Report
      serialPeriodicity = 'h';
      break;
    case 'm': //Minute Report
      serialPeriodicity = 'm';
      break;
    case 's': //Second Report
      serialPeriodicity = 's';
      break;
    case '!': //Unique (One shot)
      serialPeriodicity = '!';
      break;
    case '#': //Stop Reports
      serialPeriodicity = '0';
      break;
    case 'e': //Toggle Events
      serialEvent = not serialEvent;
      break;

    // ***Periodical Reports/Plots**
    case 'E':  //Energy Plot
      serialPage = 'E';
      break;
    case 'V':  //Variables (PWM, ADC) tracking
      serialPage = 'V';
      break;
  } //end switch (inbyte)

  inbyte = 0 ;
}
