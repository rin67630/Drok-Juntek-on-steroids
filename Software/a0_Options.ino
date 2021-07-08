#define J3603
//#define D6008
//#define D6012
//#define Dummy

#ifdef Dummy
#define DEVICE_NAME "SteroidsADS"
#define THINGER_USERNAME           "UserName1"      // "SoafPower1  SoftPower1" 
//#define WRITE_BUCKETS         // comment out. if this is the second device)
//#include "D6012.h"       // DROK 6012 Motherboard interface parameters
#include "Dummy.h"
#define PANEL_MPP  17    // Maximum Power Point Voltage
#define PANEL_WATT 100   // Maximum Power
#endif

#ifdef D6012
#define DEVICE_NAME "SteroidsADS"
#define THINGER_USERNAME           "UserName1"      // "SoafPower1  SoftPower1" 
//#define WRITE_BUCKETS         // comment out. if this is the second device)
//#include "D6012.h"       // DROK 6012 Motherboard interface parameters
#include "FLA12-100Ah.h"
#define PANEL_MPP  30    // Maximum Power Point Voltage
#define PANEL_WATT 230   // Maximum Power
#endif

#ifdef J3603
#define DEVICE_NAME "Steroids3603"
#define THINGER_USERNAME           "UserName2"      // "SoafPower1  SoftPower1" 
#define WRITE_BUCKETS         // comment out. if this is the second device)
#include "J3603.h"     //Juntekb3603 small DC-DC converter
#include "LiIon3S-4P-8Ah.h"
#define PANEL_MPP  18    // Maximum Power Point Voltage
#define PANEL_WATT 30   // Maximum Power
#endif

#ifdef D6008
#define DEVICE_NAME "Steroids6008"
#define THINGER_USERNAME           "UserName3"      // "SoafPower1  SoftPower1" 
#define WRITE_BUCKETS         // comment out. if this is the second device)
#include "D6008.h"     // DROK 6008 Motherboard interface parameters
#include "FLA12-100Ah.h"
#define PANEL_MPP  30    // Maximum Power Point Voltage
#define PANEL_WATT 230   // Maximum Power
#endif

//#include "GEL12-12Ah.h"
//#include "GEL06-08Ah.h"
//#include "LiFePo2S1P-4Ah.h"
//#include "LiFePo4S2P-8Ah.h"

#include "Credentials.h"

#define wifiMaxTries       20
#define wifiRepeatInterval 500

//Time zone
#define NTP_SERVER "de.pool.ntp.org"
#define TZ            1               // (utc+) TZ in hours


//  ***Communication options*** (For geeks only, else leave as it is)
#define THINGER
#define SERIAL_SPEED  115200  //9600  115200 230400
#define DATA_TARGET "192.168.188.64"  // IP to forward data to a remote ESP
//#define UDP_MASTER          // If this is the  master of a slave ESP
//#define UDP_SLAVE           // If this is the  slave of a master ESP
#define UDP_PORT   4212       // Ports to forward/receive data
//#define _DEBUG_             // debug information over Network and Thinger to serial
//#define BLUETOOTH           //Serial communication over bluetooth  (Exceeds available memory if not compiled with partition scheme minmal SPIFFS)

//  ***Hardware ***
#define SLEEP_US  300000
#define BOARD_IS_TTGO         // IS_WEMOS  IS_TTGO
#define DISPLAY_REVERSED
#define BRIGHTNESS 2048       // PWM value for default brightness 
//#define FET_EXTENSION        // Extension board with 4 FET and ADC 1115
