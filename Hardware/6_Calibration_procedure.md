The hardware is described in the common project Drok-Juntek-on-Steroids:  
https://github.com/rin67630/Drok-Juntek-on-steroids/tree/main/Hardware  
Enjoy!

The SoftPower HAL files are the header files containing all the specifics to the different components:
- DC-DC converters
- ESP32 boards
- Battery types

They come with usable defaults.

# Calibration procedure

The Juntek/Drok family of digital DC/DC converters are controlled ovr a 8-pin header: They provide measurement signals for current/voltage translated into a microcontroller suitable range 0..2.1V They get also PWM signals form the microcontroller in the same range.

The translation ratios depend on the respective DC/DC converter. Some ranges have a bias. I have recorded all values in header files located in libraries/SoftPower_HAL_Files:

    D6008.h
    D6812.h
    J3603.h
    J3806.h


The default values should give you approximately 1% accuracy out of the box. If you want something more precise, you will need to calibrate and match the microcontroller module to the DC/DC converter.

If you know what you are doing, you might adjust them according to your own calibration procedure.
https://github.com/rin67630/Drok-Juntek-on-steroids/blob/main/Hardware/6_Calibration_procedure.md

You are encouraged to load the above mentionned files e.g. in a programming editor e.g. notepad++

To calibrate, you will need a power supply (e.g. one or two notebook-type 19V power supply (two in series) and a multimeter, plus a dummy load 
( I am e.g. using a 100W 220V halogen rod ).

If the calibration procedure uses a two point linear regression to calculate the bias and the slope of output voltage and output current.
The input current measurement is linear without bias a single point calibration is sufficient.  

The calibration procedure is using a spreadsheet and can take over data provided by the  serial protocol report sX. At the end of the easy calibration procedure the green area of the spreadsheet will be copied in the corresponding part of the DC-DC specific HAL files and be used for subsequent compile.


## Calibrating the voltage ranges

### Hardware setup:

a) provide a fixed, stable input voltage between 19V and 38V and the input of the DC/DC converter.  
b) provide a dummy load at the output of of the DC/DC converter. 
c) Connect your multimeter (set to voltage) to the output terminals 

### Measurement

Open a serial terminal program e.g. the serial monitor of the Arduino IDE.

a) Select screen 2 [return]  
b) type + until the operation is set to manual.  
c) Select screen 3 [return]   
d) type a sequence of +++[return] or ------[return] until the the output voltage (at the multimeter) is at a value of around 5V.  
   (the more ++ or -- you type in sequence the bigger the change)  
e) report the exact value in the cell I19  
f) measure the input voltage and report the exact value in the cell U19  
g) type sX to call the calibration report and copy exactly 5 lines into cell A21  

h) type a sequence of +++[return] or ------[return] until the the output voltage (at the multimeter) is at a value of around 15V (or 30V if you have a 38V input).  
   (the more ++ or -- you type in sequence the bigger the change)  
i) report the exact value in the cell I27  
j) type sX to call the calibration report and copy exactly 5 lines into cell A29

![image](https://user-images.githubusercontent.com/14197155/128615393-7502a99e-bca2-46c8-840c-485d5b783271.png)

## Calibrating the current ranges

### Hardware setup:

a) type a sequence of +++[return] or ------[return] until the the output voltage is at the max battery voltage
b) Select screen 4 [return]
d) Connect your multimeter in series with the load
e) type a sequence of +++[return] or ------[return] until the the output current is at a value of around 500mA.
f) connect the output of of the DC/DC converter now to a partially discharged battery...

### Measurement

Open a serial terminal program e.g. the serial monitor of the Arduino IDE.

g) verify that the current has not changed.
h) report the exact value in the cell I41 
i) type sX to call the calibration report and copy exactly 5 lines into cell A43  

h) type a sequence of +++[return] or ------[return] until the the output current is at ca.the half of your max current.
   (ensure that your max battery voltage is not reached!)
i) report the exact value in the cell I50  
j) type sX to call the calibration report and copy exactly 5 lines into cell A52

![image](https://user-images.githubusercontent.com/14197155/128615697-1445e917-628e-4982-bf61-0d85fb630738.png)


Congratulations! The calibration procedure is finalised.

Copy of green values of the frame into the corresponding header file: e.g.:

![image](https://user-images.githubusercontent.com/14197155/128615708-8ed57022-b02e-4d9b-a5a9-62a19c75e4f2.png)

into the respective header file (e.g. D6008.h) of the converter used, overwriting the corresponding content:

Compile. Enjoy!

    © 2021 GitHub, Inc.
    Terms
    Privacy
