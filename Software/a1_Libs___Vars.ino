// *** libraries***

#include <Wire.h>          // Libs for I2C
#include <ArduinoOTA.h>
#include <WiFi.h>
#include "time.h"
#include <FS.h>
#include <ThingerESP32.h>
#include <EEPROM.h>

#include "SSD1306Wire.h"  // from https://github.com/ThingPulse/esp8266-oled-ssd1306/

#define OLED_SCL   5  // D1 GPIO5 for I2C (Wire) System Clock
#define OLED_SDA   4  // D2 GPIO4 for I2C (Wire) System Data
#define OLED_RST   0  //    GPIO0
#define MOSI      23  //    GPIO for SPI Master Out
#define MISO      19  //    GPIO for SPI Master In
#define SCLK      18  //    GPIO for SPI System Clock

#define A0        36  //Pin SVP  (V)
#define A3        39  //Pin SVN  (I)
#define PWM0      12 // Pin SD0  (Vpwm)
#define PWM3      14 // Pin SD1  (Ipwm) 

#define RecvPin   15 // Pin for IR Receiver




//***Variables for Time***
tm*        timeinfo;                 //localtime returns a pointer to a tm struct static int Second;
time_t     Epoch;
time_t     now;
byte Second;
long SecondOfDay;
byte GracePause;
long MillisMem;
byte Minute;
byte Hour;
byte Day;
byte Month;
unsigned int Year;
byte Weekday;
char DayName[12];
char MonthName[12];
char Time[10];
char Date[12];
byte RunMin;
byte RunHour;

byte slice;
boolean Each6S;
boolean NewMinute;
boolean MinuteExpiring;
boolean NewHour;
boolean HourExpiring;
boolean NewDay;
boolean DayExpiring;


// ***Variables for Menu***
byte    inbyte;
byte    displayPage;
byte    displaySubPage;
byte    serialPage;
byte    serialPeriodicity;
boolean serialEvent;
boolean triglEvent;

static IPAddress ip;
byte wifiConnectCounter;


struct dashboard {
// Measures
  float Vout = 0;
  float Iout = 0;
  float Wout ;
  float Ahout ;
  float Whout ;  
  float Vin = 0;
  float Iin = 0;
  float Vset ;
  float Iset ;
  float Vday ;
  float Iday ;
  float Wday ;
} dashboard;

struct persistance {
  long  Runtime;
  float Whout ;
  float Ahout ;  
} persistance;

float load_internal_resistance;
float source_internal_resistance;
float delta_current;
float delta_voltage;
float initial_voltage;
float currentInt;
int   nCurrent;
float CycleVInt;
float CycleIInt;
float CycleWInt;
int   nCycle; 

// Statistics
float Vh[31];
float Ah[31];
float Wh[31];

int A0Raw;
int A3Raw;
int lastA0;
int lastA3;

// Injection PWM output values
unsigned int CVinj;
unsigned int CCinj;

//*** Buffers ***
static char charbuff[80];    //Char buffer for many functions

//*** Aliases ***
#define Console0 Serial  // Reports 1
#define Console1 Serial  // Reports 2
#define Console2 Serial  // Menu
#define Console3 Serial  // Errors
#define Console4 Serial  // Boot messages
