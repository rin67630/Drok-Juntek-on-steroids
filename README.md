# Drok&Juntek on steroids.
Extend the possibilities of cheap digital power supplies with an ESP32 WiFi module

Juntek (aka MingHe) and Drok (maybe others) sell some interesting cheap programmable buck converter modules e.g.:
- DPS3806         (60V/6A boost/buck converter) https://www.aliexpress.com/item/1005001591485527.html
- Buck3603        (36V/3A buck converter) https://www.aliexpress.com/item/32872687512.html
- Drok low Power  (60V/8A buck converter) https://www.aliexpress.com/item/32862110549.html
- Drok high power (80V/12A buck converter) https://www.aliexpress.com/item/32863179021.html  
*(links only given to identify the modules, you are encouraged to procure the devices from your favourite source)  

They are all controlled by a pluggable control board, which stages a STM microcontroller and a 4x7 digit LED display.  
The 4 push-buttons to control the operations are clumsy and the seven segment display is everything but comfortable.  
![image](https://user-images.githubusercontent.com/14197155/124734018-08360f80-df15-11eb-9a24-05381d302f41.png)


My idea was to get rid of the original control module, and to replace it by an ESP32 WiFi enabled microcontroller in order to boost it's usability,
give full internet control and provide tons of features... 

Drok and Juntek are using the same analog control principle:  on the left side, the connector gets two PWM control inputs (voltage and current) and deliver two corresponding analog control feedback outputs all in the range 0..2,1V.  
On the right side, the connector provides GND and 5V at ~200mA.  

I used a TTGO ESP32 with an integrated TFT color display plugged onto a 6x8cm prototyping board as an adapter.  
![image](https://user-images.githubusercontent.com/14197155/114783655-54d8d700-9d7a-11eb-900d-9af7a66a8807.png)  
![image](https://user-images.githubusercontent.com/14197155/124740190-d7f16f80-df1a-11eb-9e05-a38282b05a60.png)  

The BOM for the upgrade cost less than 20$ (the ESP TTGO, an ADS1115 module, a prototyping board, some pin headers, a few resistors and condensators...)  

## The fun can begin!
Recycling a big part of the software resources of https://github.com/rin67630/Soft-Power-MPPT, I am providing much more than just a simple programmable power supply.

### Power supply mode
The power supply is controllable by:   
- USB -Serial with a simple menu to change the set-points control, the OLED display variants, the charging profiles and print reports.  
- from everywhere in the world using the cloud dashboard service of https://thinger.io with a free limited maker account.  
This is just an example, much more will come:  
![image](https://user-images.githubusercontent.com/14197155/121425793-16732900-c973-11eb-972a-bc29875c6cbc.png)
![image](https://user-images.githubusercontent.com/14197155/121425599-e1ff6d00-c972-11eb-9692-d7096f89d966.png)
 
- using the integrated buttons of the TTGO and/or an optional rotary knob to make it more comfortable to control.  
- can optionally be remotely controlled by another "slave" TTGO module in the same WiFi area.

Over the serial port and thinger.io, many reports will be made available:  
- Energy report by the second, the minute, the hour.
- Ah, Wh Joule/Coulomb reports by the minutes, the hour, the day.
- Events of the charging process
- ...  

Beside the usual constant voltage and constant current set points, I will provide many interesting things that are not common, but very useful:

### MPPT Solar charger:
cf: https://github.com/rin67630/Soft-Power2-MPPT

### Battery Charger mode: (1)  
- charging profiles for many battery chemistries
- evaluation of the battery's internal resistance
- evaluation of the battery' capacity
- charging time series plots

### Power Source emulation: (1)  
- add a programmable internal resistance
- run a constant power mode
- emulation of solar panel / wind turbine incuding "pseudo-daily" gaussian cycles (accelerated 60x) to test solar chargers

### Programmable Load (for the Juntek buck-boost version) (1)  
- together with a flooder to dissipate the energy, the buck-boost converter can be used to discharge batteries and transfer energy from one battery to another one.  

### Maybe other useful ideas that you might have...

Last but not least everything is neatly self powered, and integrated on one single board, that plugs instead of the original controller board.  
If you wanted to revert to the original functionality, just replug the manufacturer's control board.  
There is absolutely no cable mess and even a new program can be updated over the air using a beginner's easy Arduino IDE.  
You need no additional computer to manage the dashboards, everything is done in the cloud.  
The only thing you need, is a Wifi connection.  

(1) not yet finalized...

You are invited to discuss your personal project on Discord:
https://discord.gg/eY5H6PMqfk
