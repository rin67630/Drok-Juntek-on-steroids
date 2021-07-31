void wirelessRun()
{
if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.disconnect();
    WiFi.reconnect();
  }
#if defined (THINGER)
  thing.handle();
  if (NewMinute)
  {
    thing.stream("measure");
    thing.stream("status");
  }

#if defined (WRITE_BUCKETS)
  if (triglEvent)     thing.write_bucket("EVENT", "EVENT");
  if (DayExpiring)    thing.write_bucket("DAY", "DAY");
  if (HourExpiring)   thing.write_bucket("HOUR", "HOUR");
  if (MinuteExpiring) thing.write_bucket("MIN", "MIN");
#endif

  if (Minute % 6 == 5)           //every 6 minutes update persistence data
  {
    pson Ah_prop;// 0..23=hour, 25=current, 26=Ah 24h, 27= AhDay
    Ah_prop["00h"] = Ah[0];
    Ah_prop["01h"] = Ah[1];
    Ah_prop["02h"] = Ah[2];
    Ah_prop["03h"] = Ah[3];
    Ah_prop["04h"] = Ah[4];
    Ah_prop["05h"] = Ah[5];
    Ah_prop["06h"] = Ah[6];
    Ah_prop["07h"] = Ah[7];
    Ah_prop["08h"] = Ah[8];
    Ah_prop["09h"] = Ah[9];
    Ah_prop["10h"] = Ah[10];
    Ah_prop["11h"] = Ah[11];
    Ah_prop["12h"] = Ah[12];
    Ah_prop["13h"] = Ah[13];
    Ah_prop["14h"] = Ah[14];
    Ah_prop["15h"] = Ah[15];
    Ah_prop["16h"] = Ah[16];
    Ah_prop["17h"] = Ah[17];
    Ah_prop["18h"] = Ah[18];
    Ah_prop["19h"] = Ah[19];
    Ah_prop["20h"] = Ah[20];
    Ah_prop["21h"] = Ah[21];
    Ah_prop["22h"] = Ah[22];
    Ah_prop["23h"] = Ah[23];
    Ah_prop["LastHour"] = Ah[25];
    Ah_prop["Yesterday"] = Ah[27];
    Ah_prop["Today"] = Ah[26];
    thing.set_property("AhStat", Ah_prop);

    pson LTData;
    LTData["initial_voltage"] = persistence.initial_voltage;
    LTData["voltageAt0H"] = persistence.voltageAt0H ;
    LTData["voltageDelta"] = persistence.voltageDelta ;
    LTData["HourVSum"] = persistence.HourVSum;
    LTData["HourISum"] = persistence.HourISum;
    LTData["HourWSum"] = persistence.HourWSum;
    LTData["HourSamples"] = persistence.HourSamples;
    LTData["CycleVSum"] = persistence.CycleVSum;
    LTData["CycleISum"] = persistence.CycleISum;
    LTData["CycleWSum"] = persistence.CycleWSum;
    LTData["CycleSamples"] = persistence.CycleSamples;
    LTData["AhMode"] = persistence.AhMode;
    thing.set_property("LongTerm", LTData);
  }
#endif // defined Thinger

#if defined (PUBLISH_REPORT)               // Read with NetCat Bash command nc -u -l [UDP_PORT +1]
  if (DayExpiring || triglEvent)
  {
    UDP.beginPacket(REPORT_TARGET, UDP_PORT + 1);
    if (DayExpiring)
    {
      UDP.printf("\nHour|   Ah    |    V    |    W    |\n");
      for  (byte n = 0; n < 31; n++)
      {
        if (n == 24)
        {
          UDP.printf("Extra ""hours"" 25:H-1, 26:today, 27:D-1, 28:D-2..\n");
        }
        else
        {
          UDP.printf("%02u  | %+07.3f | %+07.3f | %+07.3f |\n", n, Ah[n], VoutAvg[n], Wh[n]);
        }
      }
    }
    if (triglEvent)
    {
      UDP.printf("Event reporting to be defined");
    }
    UDP.endPacket();
  }
#endif

  if (NewMinute)
  {
#if defined (UDP_MASTER)
    memcpy(dashboard_punning, &dashboard, sizeof(dashboard));
    UDP.beginPacket(DATA_TARGET, UDP_PORT);
    UDP.write(dashboard_punning, sizeof(dashboard));
    UDP.endPacket();
#else
    yield();
#endif

#if defined (THINGER)
    pson thing_property;
    //Periodically retrieve the PID parameters, comment out once the PID Paramters are stable
    thing.get_property ("thing_property", thing_property);
    P_value = thing_property["_P_value"]; 
    I_value = thing_property["_I_value"]; 
    D_value = thing_property["_D_value"]; 
    fractionVoc = thing_property["_fractionVoc"];

    //Periodically save the values that must persist after reboot
    thing_property["Ah/hour"] = Ahout;
    thing_property["Wh/hour"] = Whout;
    thing_property["voltageAt0H"] =  persistence.voltageAt0H;
    thing_property["voltageDelta"] = persistence.voltageDelta;
    thing_property["InitialVoltage"] = persistence.initial_voltage;
    thing_property["HourSamples"] = persistence.HourSamples;
    if (I_value == 0)    // control parameters unitialized, set default values)
    {
    P_value = 2;
    thing_property["_P_value"]= 2;
    I_value = 2;
    thing_property["_I_value"] = 2;
    fractionVoc = 0.8;
    thing_property["_fractionVoc"] = 0.8;
    }
    thing.set_property("thing_property", thing_property, true);
    yield();
#endif
  }
}
