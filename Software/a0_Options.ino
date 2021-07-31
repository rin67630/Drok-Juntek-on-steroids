// *** Component selection ***
// Select Converter type, Controller type, Display type, ADC type

#define CONTR_IS_TTGO     //_IS_HELTEC, _IS_WEMOS; _IS_TTGO                      Choice of ESP controller boards
// N.B. Compile sketch with following board settings: 
//- for option Wemos:          Wemos Lolin32
//- for option TTGO:           TTGO T1 
//- for option Heltec LoRa:    Heltec WiFi Lora32  (Not V2 !) 
#define DISPLAY_IS_LCD      //_IS_OLED, _IS_LCD, _IS_NONE                         Choice of display
#define ADC_IS_ADS1115     //_IS_INA226, _IS_ADS1115, _IS_ESP, _IS_SIMULATED          Choice of ADC used
#define CONV_IS_D6012    //_IS_D6008, _IS_D6012,_IS_J3603, IS_J3806, _IS_SIMULATED  Choice of converter motherboards


// *** List of available battery header files ***, uncomment accordingly
//#include "GEL12-12Ah.h"
//#include "GEL06-08Ah.h"
//#include "LiFePo2S1P-4Ah.h"
//#include "LiFePo4S2P-8Ah.h"
#include "FLA12-100Ah.h"
//#include "LiIon3S-4P-8Ah.h"

//  *** Hardware options ***
#define SLEEP_US  300000
#define DISPLAY_REVERSED
#define DISPLAY_TILTED      // works only for TTGO TFT display.
#define BRIGHTNESS 2048     // PWM value for default brightness
#define ROTARY              // Uncomment if rotary encode is not present
//#define FET_EXTENSION     // Extension board with 4 FET and ADC 1115
#define PANEL_MPP 30

//  ***Communication options*** (For geeks only, else leave as it is)
#define THINGER           // Comment out if no Thinger is to be used
#define SERIAL_SPEED      115200  //9600  115200 230400
#define DATA_TARGET     "192.168.188.64"  // IP to forward data to a remote UDP Receiver
//#define UDP_MASTER       // If this is the  master of a slave ESP
//#define UDP_SLAVE        // If this is the  slave of a master ESP
#define UDP_PORT   4212    // Ports to forward/receive data
//#define _DEBUG_          // debug information over Network and Thinger to serial
//#define BLUETOOTH        //Serial communication over bluetooth  (Exceeds available memory if not compiled with partition scheme minmal SPIFFS)

#define wifiMaxTries       20
#define wifiRepeatInterval 500
#include "Credentials.h"

//  *** Time zone ***
#define NTP_SERVER "de.pool.ntp.org"
#define TZ            1               // (utc+) TZ in hours


// Presets according to personal projects
#ifdef CONV_IS_D6012             // DROK 6012 Motherboard interface parameters
#include "D6012.h"
#define DEVICE_NAME      "SteroidsADS"
#define THINGER_USERNAME "SoftPower1"      // "SoafPower1  SoftPower1" 
//#define WRITE_BUCKETS    // comment out. if this is the second device)
#endif

#ifdef CONV_IS_J3603             //Juntek B3603 small DC-DC converter
#include "J3603.h"
#define DEVICE_NAME      "Steroids3603"
#define THINGER_USERNAME "SoafPower1"      // "SoafPower1  SoftPower1" 
#define WRITE_BUCKETS    // comment out. if this is the second device)
#endif

#ifdef CONV_IS_D6008             // DROK 6008 Motherboard interface parameters
#include "D6008.h"
#define DEVICE_NAME      "Steroids6008"
#define THINGER_USERNAME "SoftPower1"      // "SoafPower1  SoftPower1" 
#define WRITE_BUCKETS     // comment out. if this is the second device)
#endif

#ifdef CONV_IS_SIMULATED             // Use to test with stock ESP32 without periphery
#include "Dummy.h"
#define DEVICE_NAME      "SteroidsADS"
#define THINGER_USERNAME "SoftPower1"      // "SoafPower1  SoftPower1" 
//#define WRITE_BUCKETS  // comment out. if this is the second device)

#endif
