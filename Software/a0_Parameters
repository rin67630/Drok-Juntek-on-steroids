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
#define ADC0V        18    //ADC value @0V
#define VOLT_1500 27500    //millivolts @ ADC=1500
#define PWM0V        18    //PWM value @0V
#define PWM_1500   1367    //PWM value @VOLT_1500

#define ADC0A    45        //ADC value @0A
#define AMP_MAX  6500      //Current@ ADC=2047
#define PWM0A    63        //PWM value @0V
#define PWMAMAX  1780
//PWM value @AMP_MAX

#define DISPLAY_REVERSED
#define DISPLAY_IS_OLED128x64
#define THINGER
#define SERIAL_SPEED            115200 //9600  115200 230400

#define SLEEP_US  1000000
//#define _DEBUG_          // debug information over Thinger connection
