void wirelessRun()
{
  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.disconnect();
    WiFi.reconnect();
  }
#if defined (THINGER)

  MillisMem = millis();
  thing.handle();
  if (NewMinute) 
  {
    thing.stream("measure");
    thing.stream("status"); 
  }

#if defined (WRITE_BUCKETS)
  if (triglEvent)   thing.write_bucket("EVENT", "EVENT");
  if (NewDay)       thing.write_bucket("DAY", "DAY");
  if (HourExpiring) thing.write_bucket("HOUR", "HOUR");
  if (NewMinute)    thing.write_bucket("MIN", "MIN");
#endif


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
          UDP.printf("%02u  | %+07.3f | %+07.3f | %+07.3f |\n", n, Ah[n], Vbat[n], Ah[n] * Vbat[n]);
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

  pson persistances;
  persistances["Ah/hour"] = persistance.Ahout;
  persistances["Wh/hour"] = persistance.Whout;
  persistances["Runseconds"] = persistance.Runseconds;
  persistances["InitialVoltage"] = persistance.initial_voltage;
  thing.set_property("persistances", persistances, true);
  yield();
  }
}
