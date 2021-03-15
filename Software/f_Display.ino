void displayRun()
{
  yield();

#ifdef BOARD_IS_WEMOS
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
  sprintf(charbuff, "| %2.2f", dashboard.Vout - persistance.initial_voltage); display.drawString(90, 12, charbuff);
  display.drawString(0, 24, "A ");
  sprintf(charbuff, "| %1.3f", dashboard.Iset); display.drawString(10, 24, charbuff);
  sprintf(charbuff, "| %1.3f", dashboard.Iout); display.drawString(50, 24, charbuff);
  sprintf(charbuff, "| %1.3f", CycleIInt / 3600); display.drawString(90, 24, charbuff);
  display.drawString(0, 36, "W ");
  sprintf(charbuff, "| %2.3f", dashboard.Wout); display.drawString(50, 36, charbuff);
  sprintf(charbuff, "| %2.3f", CycleWInt / 3600); display.drawString(90, 36, charbuff);

  buffTimeData();
  display.drawString(0, 50, charbuff);
  display.drawString(75, 50, Runtime);
  display.fillRect(0, 63, Second * 2, 1); //display seconds progress bar
  display.display();

#endif

#ifdef BOARD_IS_TTGO
  tft.setCursor(0, 0, 2); tft.setTextFont(2);  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  sprintf(charbuff, "Setpoints: %05.2fV | %05.2fA | *USER", dashboard.Vset, dashboard.Iset) ;  tft.println(charbuff);
  tft.setTextFont(4); 
  tft.setTextColor(TFT_YELLOW, TFT_BLACK) ; sprintf(charbuff, "%06.2fVo", dashboard.Vout); tft.print(charbuff);
  tft.setTextColor(TFT_GREEN, TFT_BLACK) ; sprintf(charbuff, "  %06.2fVi ", dashboard.Vin); tft.println(charbuff); 
  tft.setTextColor(TFT_VERMILON, TFT_BLACK)    ; sprintf(charbuff, "%06.2fA    %06.2fAh ", dashboard.Iout, persistance.Ahout); tft.println(charbuff); 
  tft.setTextColor(TFT_BLUE, TFT_BLACK)      ; sprintf(charbuff, "%06.2fW  %06.2fWh ", dashboard.Wout, persistance.Whout); tft.println(charbuff);  
  buffTimeData();
  tft.setTextFont(4); tft.setTextColor(TFT_GREY, TFT_BLACK); tft.print(charbuff); 
  tft.setTextColor(TFT_MAGENTA, TFT_BLACK) ; tft.println(Runtime);
  tft.fillRect(0, 120, 120, 2,TFT_BLACK); //clear seconds progress bar
  tft.fillRect(0, 120, Second * 2, 2,TFT_MAGENTA); //display seconds progress bar


/*
tft.drawString(charbuff, x, y);
tft.setTextDatum(MC_DATUM);
tft.writecommand(TFT_DISPOFF);
tft.writecommand(TFT_SLPIN);
tft.setPixel(int16_t x, int16_t y, COLOR);
tft.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, COLOR);
tft.drawRect(int16_t x, int16_t y, int16_t width, int16_t height, COLOR);
tft.fillRect(int16_t x, int16_t y, int16_t width, int16_t height, COLOR);
tft.drawCircle(int16_t x, int16_t y, int16_t radius, COLOR);
tft.fillCircle(int16_t x, int16_t y, int16_t radius, COLOR);
tft.drawHorizontalLine(int16_t x, int16_t y, int16_t length, COLOR);
tft.drawVerticalLine(int16_t x, int16_t y, int16_t length, COLOR);
tft.drawProgressBar(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t progress, COLOR);
tft.mirrorScreen();
// tft.setBrightness(uint8_t);  // Does not work
tft.flipScreenVertically();
tft.invertDisplay(void); // does nothing
tft.displayOn(void);
tft.displayOff(void);
▉ TFT_BLACK
▉ TFT_NAVY (#000080)
▉ TFT_DARKGREEN (#008000)
▉ TFT_DARKCYAN (#008080)
▉ TFT_MAROON (#80000)
▉ TFT_PURPLE #800080)
▉ TFT_OLIVE (#808000)
▉ TFT_LIGHTGREY (#D3D3D3)
▉ TFT_DARKGREY (#808080)
▉ TFT_BLUE (#0000FF)
▉ TFT_GREEN (#00FF00)
▉ TFT_CYAN (#00FFFF)
▉ TFT_RED (#FF0000)
▉ TFT_MAGENTA (#FF00FF)
▉ TFT_YELLOW (#FFFF00)
▢ TFT_WHITE (#FFFFFF)
▉ TFT_ORANGE (#FFB400)
▉ TFT_VERMILON (#FF8000)
▉ TFT_GREENYELLOW (#B4FF00)
▉ TFT_PINK (#FFC0CB)
▉ TFT_BROWN (#964B00)
▉ TFT_GOLD (#FFD700)
▉ TFT_SILVER (#C0C0C0)
▉ TFT_SKYBLUE (#87CEEB)
▉ TFT_VIOLET (#B42EE2)
*/  
#endif
}
