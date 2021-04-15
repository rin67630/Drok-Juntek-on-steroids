# Configuration instructions
Warning: a few settings must interactivity match between the configuration at Thinger.io and the configuration file in the ESP.

The software is written in such a way that you can use it just upon defining your options **in the folder a0_Parameters.**  
If you are not familiar with the code, *this (and Dashboard.josn) are the only folders that you should change*:  

## Parameter list
If you have several devices, change the HOST_NAME and let it be "JuntekDrokSteroids", which must be matching the device name that you created at Thinger.io
The HOST_NAME also matches the device content of the default dashboard.  

Begin with populationg your credentials
#### WiFi credentials
 
Enter your Wi-Fi credentials 
´´´
#define ERASE_WIFI_CREDENTIALS 
#define WIFI_SSID          "SSID"
#define WIFI_PASS          "PASSWROD"
#define wifiMaxTries       20
#define wifiRepeatInterval 500
´´´


#### Thinger.io credentials
The next step will be entering your credentials at Thinger.io:
´´´
#define THINGER_USERNAME           "JuntekDrokSteroids"       
#define THINGER_DEVICE_CREDENTIALS "Device credentials"    
#define THINGER_DEVICE HOST_NAME   
´´´
n.b. please note the first line is your username, and the second one is the credentials of the device, *not the password of your web account* at Thinger.io.
Leave the third line unchanged it takes over the device hostname, that you defined right at the beginning of the configuration.


### Time zones
#define NTP_SERVER "de.pool.ntp.org"
#define TZ   1                              // (utc+) TZ in hours


Then proceed with the hardware configuration:
### Hardware configuration

1) match the DC/DC converter type:
#include "DROK6008.h"   // DROK 6008 Motherboard interface parameters
(I have provided four include files containing their electrical parameters of the different DC-converter is for which Drok-Juntek-on-steroids can work.
with these includes the match should be okay out of the box with a precision of approximately 1%) 
You can increase the precision with the calibration procedure described in 6_calibration_procedure.md but this is not a requirement.

the next settings can be left as it is:

```
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
```


That should be all for a first run...  
Compile and enjoy!
