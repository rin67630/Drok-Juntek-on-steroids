void menuRun()
{
  if (Year < 2020) setTimefromSerial();
  byte n;
  byte m;
  if (Console0.available())   inbyte = Console0.read(); //Serial input available
  switch (inbyte)
  {
    //====(Serial Menu)======

    // *** Actions***
    case '0': //Display mode 0
      displayPage = 0;
      Console1.printf ("Off\n");
      break;
    case '1': //Display mode 1
      displayPage = 1;
      Console1.printf ("D=1\n");
      break;
    case '2': //Display mode 2
      displayPage = 2;
      Console1.printf ("D=2\n");
      break;
    case '3': //Display mode 3
      displayPage = 3;
      Console1.printf ("D=3\n");
      break;
    case '4': //Display mode 3
      displayPage = 4;
      Console1.printf ("D=3\n");
      break;
    case '5': //Display mode 3
      displayPage = 5;
      Console1.printf ("D=3\n");
      break;
    case '+': //Increase Volt
      //CVinj += 10;
      //Console1.printf ("+1 Vinj=%i Vadc=%i\n", CVinj, A0Raw);
      dashboard.Vset += 0.1;
      Console1.printf ("+1 Volt=%06.3f\n", dashboard.Vset);
      break;
    case '-': //Reduce Volt
      //CVinj -= 10;
      //Console1.printf ("-1 Vinj=%i Vadc=%i\n", CVinj, A0Raw);
      dashboard.Vset -= 0.1;
      Console1.printf ("-1 Volt=%06.3f\n", dashboard.Vset);
      break;
    case '>': //Increase Amp
      //CCinj += 10;
      //Console1.printf ("+1 Cinj=%i Iadc=%i\n", CCinj,A3Raw);
      dashboard.Iset += 0.05;
      Console1.printf ("+10 Amp=%06.3f \n", dashboard.Iset);
      break;
    case '<': //Reduce Amp
      //CCinj -= 10;
      //Console1.printf ("+1 Cinj=%i Iadc=%i\n", CCinj,A3Raw);
      dashboard.Iset -= 0.05;
      Console1.printf ("-10 Amp=%06.3f\n", dashboard.Iset);
      break;
    case 'Z':  //Reset
      Console1.printf ("\nResetting in 10s...\n");
      delay(10000);
      ESP.restart();
      break;
    case 'z':  //Reset runtime
      Console1.printf ("\nRt:%06i s Ah:%06.3f Wh:%06.3f \n", persistance.Runtime, persistance.Ahout, persistance.Whout);
      Console1.printf ("\nResetting \n");
      persistance.Runtime = 0;
      persistance.Ahout = 0;
      persistance.Whout = 0;
      CycleVInt = CycleIInt = CycleWInt = nCycle = 0;
      initial_voltage = dashboard.Vout;
      break;    

    // ***One shot Reports**
    case 'S':  //Summary Report
      Console1.printf ("\nSummary Report\n");
      serialPage = 'S';
      break;
    case 'P': //Parameter List
      Console1.printf("Par.List \n Vout %6.2f CV %6.2f Iout %6.3f CC %6.3f", dashboard.Vout, dashboard.Vset, dashboard.Iout, dashboard.Iset );
       break;
    case 't': // Print time
      Console1.println(ctime(&now));
      break;
    case 'T': // Enter time
      setTimefromSerial();
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
      //      Console1.printf ("\nEnergy plot :\n");
      break;
    case 'W':  //PWM Plot
      serialPage = 'W';
      //      Console1.printf ("\nPWM Plot :\n");
      break;
    case '~':  //Redio Report / WiFi
      serialPage = '~';
      Console1.printf ("\nWiFi Plot :\n");
      WiFi.printDiag(Console1);
      Console1.flush();
      break;
  } //end switch (inbyte)

  inbyte = 0 ;
}
