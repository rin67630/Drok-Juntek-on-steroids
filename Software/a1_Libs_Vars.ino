// *** libraries***
//#define _DISABLE_TLS_
#include <Wire.h>          // from Library (I2C)
#include <ArduinoOTA.h>    // from Library
#include <WiFi.h>          // built-in
#include <WiFiUdp.h>       // built-in
#include "time.h"          // built-in
#include <FS.h>            // built-in
#include <ThingerESP32.h>  // from Library (Thinger)
//#include <ThingerConsole.h>// from Library (Thinger) Hmm... does that work?
#include <EEPROM.h>        // to be replaced by preferences
#include <ADS1115_WE.h>    // from Library (Wollewald)
#include <Preferences.h>   //built-in  to use: https://randomnerdtutorials.com/esp32-save-data-permanently-preferences/
#include "AiEsp32RotaryEncoder.h"
#include "PCF8574.h"   // from library Renzo Mischienti/PCF8574 


#ifdef BLUETOOTH
#include "BluetoothSerial.h"
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
#endif

// Solar charger CtrlMode  modes
#define MANU         0  // fix voltage 
#define PVFX         1  // fix panel voltage
#define MPPT         2  // maximum power point tracking
#define AUTO         3  // automatic

#define ROTARY_ENCODER_A_PIN      25 // Rotary Encoder A
#define ROTARY_ENCODER_B_PIN      26 // Rotary Encoder B
#define ROTARY_ENCODER_BUTTON_PIN 33 // Rotary Encoder Switch
#define ROTARY_ENCODER_STEPS      4  // Rotary Encoder Delta (Steps) not an input!

#define UDP_TX_PACKET_MAX_SIZE 128 //increase UDP size
#define DST_MN        60
#define GMT_OFFSET_SEC 3600 * TZ
#define DAYLIGHT_OFFSET_SEC 60 * DST_MN

#ifdef BOARD_IS_WEMOS
#include <SSD1306Wire.h>  // from https://github.com/ThingPulse/esp8266-oled-ssd1306/
#define OLED_W 128
#define OLED_H 64
#define OLED_SCL   5  // D1 GPIO5 for I2C (Wire) System Clock
#define OLED_SDA   4  // D2 GPIO4 for I2C (Wire) System Data
#define OLED_RST   0  //    GPIO0
#define ADC_VOUT   36
#define ADC_IOUT   39
#define ADC_VIN    38
#define ADS_VOUT   ADS1115_COMP_0_GND
#define ADS_IOUT   ADS1115_COMP_1_GND
#define ADS_VIN    ADS1115_COMP_2_GND
#define TFT_BL     0  // dummy

#define PWM_V      12 // Pin SD0  (Vpwm)
#define PWM_I      14 // Pin SD1  (Ipwm) 
#endif

#ifdef BOARD_IS_TTGO
#include <TFT_eSPI.h> // Hardware-specific library
#include <SPI.h>
#define TFT_W 160
#define TFT_H 128
#define OLED_SCL     22  // GPIO22 for I2C (Wire) System Clock
#define OLED_SDA     21  // GPIO21 for I2C (Wire) System Data
#define TFT_BL       4  // Display backlight control pin
#define SCL          22  // D1 GPIO22 for I2C (Wire) System Clock
#define SDA          21  // D2 GPIO21 for I2C (Wire) System Data
#define RST          0   //    GPIO0
#define MOSI         23  //    GPIO for SPI Master Out
#define MISO         19  //    GPIO for SPI Master In
#define SCLK         18  //    GPIO for SPI System Clock
#define BUTTON_UP    35
#define BUTTON_DOWN  0
#define ADC_VOUT     36
#define ADC_IOUT     39
#define ADC_VIN      38
#define ADS_VOUT     ADS1115_COMP_0_GND
#define ADS_IOUT     ADS1115_COMP_1_GND
#define ADS P        ADS1115_COMP_2_GND

#define PWM_V        15  // Pin GPIO15  (Vpwm)
#define PWM_I        13  // Pin GPIO13  (Ipwm) 
#endif

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


// ***Variables for Menu***
byte    inbyte;
byte    displayPage;
byte    displaySubPage;
byte    serialPage;
byte    serialPeriodicity;
boolean serialEvent;
boolean triglEvent;
boolean cycleDisplay = false;
boolean coarse = true;
long    nothingPressed;
unsigned int rotaryEncoderValue;
long    encoderChanged;
boolean buttonPressed;

static IPAddress ip;
byte wifiConnectCounter;

//ADC / PWM measurement and conversions
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

// Controller Settings
float P_value = 1;     //Proportional Gain
float I_value = 3;     //Integrative Gain
float D_value = 1;     //Derivative Gain

// MPPT
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

// Power Integrations and mean values
float delta_current = 1;
float delta_voltage = 1;
float raw_internal_resistance;
float Whout;           //Wh of the current hour
float Ahout;           //Ah of the current hour
float Vavgout;          //Avg voltage in hour

// Dashboard
String CtrlMode_description[] = {"MANU", "PVFX", "MPPT"}; // for dashboard.CtrlMode
String ChrgPhase_description[] = {"NIGH", "RECO", "BULK", "PANL", "ABSO", "FLOA", "EQUA", "OVER", "DISC", "PAUS", "NOBA", "NOPA", "EXAM"}; // for dashboard.ChrgPhase

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

// Reset safe initialisation
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

// Power Statistics Arrays
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
