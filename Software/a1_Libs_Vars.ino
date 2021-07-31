// *** libraries*** (including with <> takes by priority global files, including with "" takes local files). 

//#define _DISABLE_TLS_      (Workaround to circumvent a bug in TLS handling for Thinger.io versions >2.15, better use 2.14)
#include <ArduinoOTA.h>    // from Library
#include <WiFi.h>          // built-in
#include <WiFiUdp.h>       // built-in
#include "time.h"          // built-in
#include <FS.h>            // built-in
#include <ThingerESP32.h>  // from Library (Thinger)
#include <EEPROM.h>        // to be replaced by preferences
#include <Wire.h>          // from Library (I2C)
#include <MoToButtons.h>   // from Library (MoBaTools).

// *** Optional libraries ***
#ifdef CONTR_IS_HELTEC
#include <heltec.h>
#include "Heltec_LoRa.h"  // from libraries/SoftPower_HAL_Files
#endif

#ifdef CONTR_IS_TTGO
#include <TFT_eSPI.h> 
#include "TTGO_LCD.h"  // from libraries/SoftPower_HAL_Files
#include <SPI.h>
#endif

#ifdef CONTR_IS_WEMOS 
#include <SSD1306Wire.h>  // from https://github.com/ThingPulse/esp8266-oled-ssd1306/
#include "Wemos32_OLED.h"  // from libraries/SoftPower_HAL_Files
#endif

#ifdef ADC_IS_ADS1115
#include <ADS1115_WE.h>    // from Library (Wollewald)
#endif

#ifdef ADC_IS_INA226
#include <INA.h>    
#endif

#ifdef ROTARY
#include "AiEsp32RotaryEncoder.h"
#endif

#ifdef FET_EXTENSION
#include "PCF8574.h"   // from library Renzo Mischienti/PCF8574 
#endif

#ifdef BLUETOOTH
#include "BluetoothSerial.h"
#endif

//****************************************************************************
//***Definitions***

// Solar charger CtrlMode  modes
#define MANU       0  // fix voltage 
#define PVFX       1  // fix panel voltage
#define MPPT       2  // maximum power point tracking

#define STOP       0  //Ah mode reset
#define RUN        1  //Ah mode reset
#define DAILY      2  //Ah mode reset

#define OLED_W 128
#define OLED_H 64

#define TFT_W 160
#define TFT_H 128

#define UDP_TX_PACKET_MAX_SIZE 128 //increase UDP size
#define DST_MN        60
#define GMT_OFFSET_SEC 3600 * TZ
#define DAYLIGHT_OFFSET_SEC 60 * DST_MN

//*****************************************************************************
// ***Variables***

// ***Time***
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
unsigned int RunMillis[21];
unsigned int Year;
byte Weekday;
char DayName[12];
char MonthName[12];
char Time[10];
char Date[12];
unsigned int  RunMin;
unsigned int  RunHour;
String Runtime;
String Message;

byte slice;
boolean Each6S;
boolean NewMinute;
boolean MinuteExpiring;
boolean MinuteExpiring2;
boolean NewHour;
boolean HourExpiring;
boolean NewDay;
boolean DayExpiring;


// ***Menu***
byte    inbyte;
byte    displayPage;
byte    displaySubPage;
byte    serialPage;
byte    serialPeriodicity;
boolean serialEvent;
boolean triglEvent;
boolean cycleDisplay = false;
boolean coarse = true;
unsigned long lastTimePressed[3];
unsigned int rotaryEncoderValue;
long    action;
boolean setpointMode;
// Parameters for MoToButtons
#define MAX8BUTTONS     // This saves ressources if you don't need more than 8 buttons
const byte buttonPins [] = { BUTTON_UP, BUTTON_DOWN, ROTARY_ENCODER_BUTTON_PIN };
enum : byte { UP, DOWN, ROT };
const byte buttonCount = sizeof(buttonPins);

static IPAddress ip;
byte wifiConnectCounter;

// ***ADC / PWM measurement and conversions***
int ADC_VoutRaw;
int ADC_IoutRaw;
int ADC_VinRaw;
int ADC_IinRaw;
int lastADC_Vout;
int lastADC_Iout;
float converted_VoutRaw = 10;
float converted_IoutRaw = 0.3;
float converted_VinRaw = 16;
float converted_IinRaw = 0.3;

// Injection PWM output values
int PWM_SetVout;   // CV Setpoint PWM
int PWM_SetIout;   // CC Setpoint PWM
int PWM_Fan;       // Fan control PWM

// ***Controller Settings***
float P_value = 1;     //Proportional Gain
float I_value = 3;     //Integrative Gain
float D_value = 1;     //Derivative Gain

// ***MPPT***
unsigned int collapseTimer;
float MPPT_last_power;
float MPPT_last_voltage;
float MPPT_voc;
float fractionVoc = 0.9;
float dP; // power difference;
float dV; // voltage difference;
float VinSlow;
float IoutSlow;
float collapseTreshold = 5;
float MPPT_perturbe = 0.025;

// ***Power Integrations and mean values***
float delta_current = 1;
float delta_voltage = 1;
float raw_internal_resistance;
float Whout;           //Wh of the current hour
float Ahout;           //Ah of the current hour
float Vavgout;          //Avg voltage in hour

// ***Thinger.io Dashboard***
String CtrlMode_description[] = {"Manu ", "PVFx ", "MPPT "}; // for dashboard.CtrlMode
String ChrgPhase_description[] = {"NIGH", "RECO", "BULK", "PANL", "ABSO", "FLOA", "EQUA", "OVER", "DISC", "PAUS", "NOBA", "NOPA", "EXAM"}; // for dashboard.ChrgPhase
String AhCycle_description[] = {" Stop ", "  Run ", "Daily "}; // for persistance.AhMode

struct dashboard {
  // Measures
  float Vout = 0;
  float Iout = 0;
  float Wout = 0;
  float Vin = 0;
  float Iin = 0;
  float SetVout ;   //manual output voltage setpoint
  float ConVout ;   //controlled  output voltage setpoint
  float SetIout ;   //manual output current setpoint
  float ConIout ;   //controlled output current setpoint
  float SetVin ;    //manual input voltage setpoint
  float ConVin ;    //controlled input voltage setpoint
  float VoutAvg = 0;//averaged output voltage
  float Ahout ;     //Ah of the current cycle
  float Whout ;     //Wh of the current cycle
  float load_internal_resistance;
  byte  ChrgPhase ; // charger phases
  byte  CtrlMode = 2 ;  // mode of operation
  float efficiency; // converter efficiency
  float percent_charged = 66;  // estimation
} dashboard;
unsigned char dashboard_punning[sizeof(dashboard)];  //  Array of characters as image of the structure for udp xmit/rcv

// ***Reset safe initialisation***
struct persistence {
  float initial_voltage;
  float voltageAt0H ;
  float voltageDelta ;
  float HourVSum;
  float HourISum;
  float HourWSum;
  unsigned int HourSamples;
  float CycleVSum;
  float CycleISum;
  float CycleWSum;
  unsigned int CycleSamples;
  byte AhMode ;
} persistence;
unsigned char persistence_punning[sizeof(persistence)];  //  Array of characters as image of the structure for udp xmit/rcv

// ***Power Statistics Arrays***
float VoutAvg[32];
float Ah[32];
float Wh[32];

//*** Buffers ***
static char charbuff[80];    //Char buffer for many functions

#ifdef FET_EXTENSION
float ADC_IExt0;
float ADC_IExt1;
float ADC_IExt2;
float ADC_IExt3;

boolean Out_IExt0;
boolean Out_IExt1;
boolean Out_IExt2;
boolean Out_IExt3;
#endif

// ***Serial Output Definitions***
#ifdef BLUETOOTH
//*** Aliases for serial communication***
#define Console0 SerialBT  // Reports 1
#define Console1 SerialBT  // Reports 2
#define Console2 SerialBT  // Menu
#define Console3 Serial // Errors
#define Console4 Serial  // Boot messages
#else
#define Console0 Serial  // Reports 1
#define Console1 Serial  // Reports 2
#define Console2 Serial  // Menu
#define Console3 Serial  // Errors
#define Console4 Serial  // Boot messages
#endif
