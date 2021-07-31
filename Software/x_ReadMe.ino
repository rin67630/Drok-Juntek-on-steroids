/*
#include <file>     This variant is used for system header files. It searches for a file named file in a standard list of system directories. 
#include "file"     This variant is used for header files of your own program


rotaryEncoder.setEncoderValue(1);
rotary_onButtonClick();
if (rotaryEncoder.action())
rotaryEncoder.setBoundaries(1, 10, false);
rotaryEncoder.readEncoder()
rotaryEncoder.setAcceleration(0);  //or set the value 0...255 - larger number = more accelearation; 0 or 1 means disabled acceleratio
rotaryEncoder.disableAcceleration();

OLED Display Instructions
    // Resume after a deep sleep without reset
    display.allocateBuffer();
    // Allocates the buffer 
    display.init();
    // Free the memory used by the display
    display.end();
    // Cycle through the initialization
    display.resetDisplay(void);
    // Drawing functions 
    // Sets the color of all pixel CtrlMode s
    display.setColor(OLEDDISPLAY_COLOR color);
    display.setTextColor(BLACK, WHITE); // 'inverted' text
    // Returns the current color.
    OLEDDISPLAY_COLOR getColor();
// Display functions
    // Turn the display on
    display.displayOn(void);
    // Turn the display offs
    display.displayOff(void);
    // Inverted display mode
    display.invertDisplay(void);
    // Normal display mode
    display.normalDisplay(void);
    // Set display contrast
    // really low brightness & contrast: contrast = 10, precharge = 5, comdetect = 0
    // normal brightness & contrast:  contrast = 100
    display.setContrast(uint8_t contrast, uint8_t precharge = 241, uint8_t comdetect = 64);
    // aux method to access
    display.setBrightness(uint8_t);
    // Reset display rotation or mirroring
    display.resetOrientation();
    // Turn the display upside down
    display.flipScreenVertically();
    // Mirror the display (to be used in a mirror or as a projector)
    display.mirrorScreen();

        
    // Draw a pixel at given position
    display.setPixel(int16_t x, int16_t y);
    // Draw a pixel at given position and color
    display.setPixelColor(int16_t x, int16_t y, OLEDDISPLAY_COLOR color);
    // Clear a pixel at given position FIXME: INVERSE is untested with this function
    display.clearPixel(int16_t x, int16_t y);
    // Draw a line from position 0 to position 1
    display.drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
    // Draw the border of a rectangle at the given location
    display.drawRect(int16_t x, int16_t y, int16_t width, int16_t height);
    // Fill the rectangle
    display.fillRect(int16_t x, int16_t y, int16_t width, int16_t height);
    // Draw the border of a circle
    display.drawCircle(int16_t x, int16_t y, int16_t radius);
    // Draw all Quadrants specified in the quads bit mask
    display.drawCircleQuads(int16_t x0, int16_t y0, int16_t radius, uint8_t quads);
    // Fill circle
    display.fillCircle(int16_t x, int16_t y, int16_t radius);
    // Draw a line horizontally
    display.drawHorizontalLine(int16_t x, int16_t y, int16_t length);
    // Draw a line vertically
    display.drawVerticalLine(int16_t x, int16_t y, int16_t length);
    // Draws a rounded progress bar with the outer dimensions given by width and height. Progress is
    // a unsigned byte value between 0 and 100
    display.drawProgressBar(uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint8_t progress);
    // Draw a bitmap in the internal image format
    display.drawFastImage(int16_t x, int16_t y, int16_t width, int16_t height, const uint8_t *image);
    // Draw a XBM
    display.drawXbm(int16_t x, int16_t y, int16_t width, int16_t height, const uint8_t *xbm);
    // Draw icon 16x16 xbm format
    display.drawIco16x16(int16_t x, int16_t y, const char *ico, bool inverse = false);
    // Text functions
    // Draws a string at the given location
    display.drawString(int16_t x, int16_t y, String text);
    // Draws a formatted string (like printf) at the given location
    display.drawStringf(int16_t x, int16_t y, char* buffer, String format, ... );
    // Draws a String with a maximum width at the given location.
    // If the given String is wider than the specified width
    // The text will be wrapped to the next line at a space or dash
    display.drawStringMaxWidth(int16_t x, int16_t y, uint16_t maxLineWidth, String text);
    // Returns the width of the const char* with the current
    // font settings
    uint16_t getStringWidth(const char* text, uint16_t length);
    // aux method for the const char version
    uint16_t getStringWidth(String text);
    // Specifies relative to which anchor point
    // the text is rendered. Available constants:
    // TEXT_ALIGN_LEFT, TEXT_ALIGN_CENTER, TEXT_ALIGN_RIGHT, TEXT_ALIGN_CENTER_BOTH
    display.setTextAlignment(OLEDDISPLAY_TEXT_ALIGNMENT textAlignment);
    // Sets the current font. Available default fonts
    // ArialMT_Plain_10, ArialMT_Plain_16, ArialMT_Plain_24
    display.setFont(const uint8_t *fontData);
    // Set the function that will convert utf-8 to font table index
    display.setFontTableLookupFunction(FontTableLookupFunction function);

    // Write the buffer to the display memory
    display.display(void) = 0;
    // Clear the local pixel buffer
    display.clear(void);
    // Log buffer implementation
    // This will define the lines and characters you can
    // print to the screen. When you exeed the buffer size (lines * chars)
    // the output may be truncated due to the size constraint.
    bool setLogBuffer(uint16_t lines, uint16_t chars);
    // Draw the log buffer at position (x, y)
    display.drawLogBuffer(uint16_t x, uint16_t y);
    // Get screen geometry
    uint16_t getWidth(void);
    uint16_t getHeight(void);
    strftime(charbuff, sizeof(charbuff), "-%d %b", &timeinfo);
    strftime(charbuff, sizeof(charbuff), "%H:%M ", &timeinfo);
    sprintf(charbuff, "%02d,%02d", mainScreen, subScreen);
    sprintf(charbuff, "IP= %03d.%03d.%03d.%03d", ip[0], ip[1], ip[2], ip[3]);
    display.drawString(25, 52, charbuff);
    display.drawStringf(25, 52, "Formatted string: %3d", variable);  // Draws a formatted string (like printf)


TFT Display Instructions
    tft.setTextDatum(); 0:topleft, 2 topright, 4 centre, 6 bottomleft, 8 bottomright
    tft.drawString();
    tft.fillScreen(TFT_BLACK);
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
    tft.setBrightness(uint8_t);  // Retrofitted
    tft.flipScreenVertically();
    tft.invertDisplay(void); // does nothing
    // tft.displayOn(void);  // does not work
    // tft.displayOff(void); // does not work
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
    ▉ TFT_PURPLE (#FF00FF)
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

Panel Correction Factors for Ambient Temperatures Below 25°C (77°F).
(Multiply the rated open-circuit voltage by the appropriatecorrection factor shown below.)
AmbientTemperature (°C) Factor
24 to 20   1.02 
19 to 15   1.04 
14 to 10   1.06 
9 to 5     1.08 
4 to 0     1.10 
–1 to –5   1.12 
–6 to –10  1.14 
–11 to –15 1.16 

*/
