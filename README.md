# Drok&Juntek on steroids.
Extend the possibilities of cheap digital power supplies with an ESP32 WiFi module

Juntek and Drok (maybe others) sell some interesting cheap programmable buck converter modules e.g.:
- DPS3806         (60V/6A boost/buck converter) https://www.aliexpress.com/item/1005001591485527.html
- Buck3603        (36V/3A buck converter) https://www.aliexpress.com/item/32872687512.html
- Drok low Power  (60V/8A buck converter) https://www.aliexpress.com/item/32862110549.html
- Drok high power (80V/12A buck converter) https://www.aliexpress.com/item/32863179021.html 
(links only given to identify the modules, you are encouraged to procure the devices from your favourite source)  

They are all controlled by a pluggable control board, which stages a STM microcontroller and a 4x7 digit LED display.  
The 4 push-buttons to control the operations are clumsy and the seven segment display is everything but comfortable.  
Some Drok modules provide a serial port to remote control the operation, the Juntek do not.  

Both Vendors are however using the same analog control principle:  
On the left side the connector gets two PWM voltage and current control inputs and deliver two analog voltage and current control outputs all in the range 0..2,4V.
On the right side, the connector provides GND and 5V at ~200mA

My idea was to get rid of the original control module, and to replace it by an ESP32 WiFi enabled microcontroller in order to boost it's usability,   
give full internet control and provide tons of features...

I used a Wemos ESP32 with an integrated 128*64 OLED display plugged onto a 6*8cm prototyping board as an adapter.
![image](https://cjoint.com/doc/21_03/KChtpxwcM50_ESP32-on-Juntek.jpg)

OK it was not straight forward to get the crappy ADCs of the ESP32 to work correctly, but I now got it running.

##The fun can begin!
Recycling a big part of the software resources of https://github.com/rin67630/Soft-Power-MPPT, I will be able to provide much more than just a simple programmable power supply.

###Power supply mode
The power supply is controllable by:
a) USB -Serial with a simple menu to change the set-points control, the OLED display variants, the cherging profiles and print reports.
b) from everywhere in the world using the cloud dashboard service of https://thinger.io with a free limited maker account.
This is just an example, much more will come:
c) a IR remote control.
d) remote screen replication

Over the serial port and thinger.io, many reports will be made available:
-energy report by the second, the minute, the hour.
-Ah, Wh Joule/Coulomb reports by the minutes, the hour, the day.

Beside the usual constant voltage and constant current set points, I will provide many interesting things that are not common, but very useful:

###Battery Charger mode:
- charging profiles for many battery chemistries
- evaluation of the battery's internal resistance
- evaluation of the battery' capacity
- charging time series plots

###Power Source emulation:
- add a programmable internal resistance
- run a constant power mode
- emulation of solar panel / wind turbine incuding "daily" gaussian cycles (accelerated 60x)

Programmable Load (for the Juntek buck-boost version
- together with a flooder to dissipate the energy, the buck-boost converter can be used to discharge batteries and transfer energy from one battery to another one.

Maybe other useful ideas that you might have...

Last but not least everything is neatly self powered, and integrated on one single board, that plugs instead of the original controller board.
If you wanted to revert to the original functionality, just replug the manufacturer's control board.
There is absolutely no cable mess and even a new program can be updated over the air.
You need no additional computer to manage the dashboards, everything is done in the cloud.
The only thing you need, is a Wifi connection.
