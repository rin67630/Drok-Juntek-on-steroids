#define DEVICE_NAME   "JuntekNT" // n.b: The DEVICE_NAME must match the device name of Thinger.

//  ***Credentials***  
// WifI: for the very first run with a new ESP or on a new WiFi network 
// remove the // from the next line and provide real SSID and PASS credentials.
//#define ERASE_WIFI_CREDENTIALS 
#define WIFI_SSID          "SSID"
#define WIFI_PASS          "PASS"
#define wifiMaxTries       20
#define wifiRepeatInterval 500
// after a successful connection, you can revert to the defaults lines again.

//Thinger
#define THINGER_USERNAME           "USER"       
#define THINGER_DEVICE_CREDENTIALS "CREDENTIALS"    
#define THINGER_DEVICE DEVICE_NAME    

//Time zone
#define NTP_SERVER "de.pool.ntp.org"
#define TZ            1               // (utc+) TZ in hours
#define DST_MN        60              // use 60mn for summer time in some countries
#define GMT_OFFSET_SEC 3600 * TZ      // Do not change here...
#define DAYLIGHT_OFFSET_SEC 60 * DST_MN // Do not change here...

// Buck converter control/measures conversions.
#define ADC0V        13      //ADC value @0V
#define VOUT_1500    26620   //millivolts @ ADC=1500
#define VIN_1500     13800   //millivolts @ ADC=1500
#define PWM_VV       32      //PWM value @0V
#define PWM_1500     1331    //PWM value @VOUT_1500

#define ADC0A        38       //ADC value @0A
#define AMP_MAX      6500     //Current@ ADC=1500
#define PWM_VA       50       //PWM value @0V
#define PWMAMAX      1780     //PWM value @AMP_MAX

#define BOARD_IS_TTGO
#define DISPLAY_REVERSED
#define BRIGHTNESS 2047       // PWM value for default brightness 

//  ***Communication options*** (For geeks only, else leave as it is)
#define THINGER
#define SERIAL_SPEED            115200 //9600  115200 230400

#define SLEEP_US  1000000
//#define _DEBUG_             // debug information over Thinger connection
//#define UDP_MASTER          // If this is the  master of a slave ESP
//#define UDP_SLAVE             // If this is the  slave of a master ESP
#define DATA_TARGET "192.168.188.73"  // IP to forward data
#define UDP_PORT   4214       // Ports to forward/receive data
