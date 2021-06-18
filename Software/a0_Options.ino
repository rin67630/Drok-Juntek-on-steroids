//#define DEVICE_NAME   "SteroidsADS" // n.b: The DEVICE_NAME must match the device name of Thinger.
//#define DEVICE_NAME   "Steroids3603" // n.b: The DEVICE_NAME must match the device name of Thinger.
#define DEVICE_NAME   "Steroids6008" // n.b: The DEVICE_NAME must match the device name of Thinger.
//#include "J3603.h"     //Juntekb3603 small DC-DC converter
#include "D6008.h"     // DROK 6008 Motherboard interface parameters
//#include "D6012.h"       // DROK 6012 Motherboard interface parameters
//#include "Dummy.h"     // Simulation
//#include "LiFePo8x32700.h"
#include "FLA12-100Ah.h"
//#include "GEL12-12Ah.h"
//include "GEL06-12Ah.h"
#define PANEL_MPP  30    // Maximum Power Point Voltage
#define PANEL_WATT 230   // Maximum Power

#include "Credentials.h"

#define wifiMaxTries       20
#define wifiRepeatInterval 500

//Time zone
#define NTP_SERVER "de.pool.ntp.org"
#define TZ            1               // (utc+) TZ in hours


//  ***Communication options*** (For geeks only, else leave as it is)
#define THINGER
#define WRITE_BUCKETS         // comment out. if this is the second device)
#define SERIAL_SPEED  115200  //9600  115200 230400
//#define UDP_MASTER          // If this is the  master of a slave ESP
//#define UDP_SLAVE           // If this is the  slave of a master ESP
#define DATA_TARGET "192.168.188.64"  // IP to forward data to a remote ESP
#define UDP_PORT   4212       // Ports to forward/receive data
//#define _DEBUG_             // debug information over Network and Thinger to serial
//#define BLUETOOTH           //Serial communication over bluetooth  (Exceeds available memory if not compiled with partition scheme minmal SPIFFS)

//  ***Hardware ***
#define SLEEP_US  300000
#define BOARD_IS_TTGO         // IS_WEMOS  IS_TTGO
#define DISPLAY_REVERSED
#define BRIGHTNESS 2048       // PWM value for default brightness 
