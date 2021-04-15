#define DEVICE_NAME   "SteroidsADS" // n.b: The DEVICE_NAME must match the device name of Thinger.
#include "DROK6008.h"      // DROK 6008 Motherboard interface parameters
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
#define DATA_TARGET "192.168.188.73"  // IP to forward data
#define UDP_PORT   4214       // Ports to forward/receive data

//  ***Hardware ***
#define SLEEP_US  300000
#define BOARD_IS_TTGO        // IS_WEMOS  IS_TTGO
#define DISPLAY_REVERSED
#define BRIGHTNESS 1024       // PWM value for default brightness 

//#define _DEBUG_             // debug information over Network and Thinger to serial
