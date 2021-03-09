void displayRun()
{
  yield();

#ifdef DISPLAY_IS_OLED128x64
  display.clear();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  // Draw Information matrix

  display.drawString(10, 0,  "| Set");
  display.drawString(50, 0,  "| Value");
  display.drawString(90, 0,  "| Cycle");
  display.drawString(0, 12, "V ");
  sprintf(charbuff, "| %2.2f", dashboard.Vset); display.drawString(10, 12, charbuff);
  sprintf(charbuff, "| %2.2f", dashboard.Vout); display.drawString(50, 12, charbuff);
  sprintf(charbuff, "| %2.2f", dashboard.Vout - initial_voltage); display.drawString(90, 12, charbuff);
  display.drawString(0, 24, "A ");
  sprintf(charbuff, "| %1.3f", dashboard.Iset); display.drawString(10, 24, charbuff);
  sprintf(charbuff, "| %1.3f", dashboard.Iout); display.drawString(50, 24, charbuff);
  sprintf(charbuff, "| %1.3f", CycleIInt / 3600); display.drawString(90, 24, charbuff);
  display.drawString(0, 36, "W ");
  sprintf(charbuff, "| %2.3f", dashboard.Wout); display.drawString(50, 36, charbuff);
  sprintf(charbuff, "| %2.3f", CycleWInt / 3600); display.drawString(90, 36, charbuff);

  buffTimeData();
  display.drawString(0, 50, charbuff);
  sprintf(charbuff, "| %02ih %02im",RunHour, RunMin);
  display.drawString(75, 50, charbuff);
  display.fillRect(0, 63, Second * 2, 1); //display seconds progress bar
  display.display();

#endif
}
