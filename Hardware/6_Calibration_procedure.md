# Calibration procedure

The Juntek/Drok family of digital DC/DC converters are controlled ovr a 8-pin header:
They provide measurement signals for current/voltage translated into a microcontroller suitable range 0..2.1V
They get also PWM signals form the microcontroller in the same range.

The translation ratios depend on the respective DC/DC converter. Some ranges have a bias.
I have recorded all values in header files:
1) D6008.h
2) D6812.h
3) J3603.h
4) J3806.h  

These values should give you approximately 1% accuracy out of the box.
If you want something more precise, you will need to calibrate and match the microcontroller module to the DC/DC converter.  
To do that, you will need an adjustable power supply and a multimeter, plus a dummy load that is able to accept some current  
( I am e.g. using a 1000W 220V halogen bulb from an old cinema projector ).

For each Analog parameter, we will measure and record two readings in the spreadsheet TTGO&ADS1115.xlsx  
Once all values are entered, the spreadsheet calculates the respective bias/step/ and resolution values and prepares the # include parameters to update the header file.


## Calibrating the input voltage range
Open a serial terminal program e.g. the serial monitor of the Arduino IDE.
- Enter the command "sX" to call the debugging report every second.  
- Give exactly 10 V at the input of your DC/DC converter.
The report should print something like:
```
16:33:57.442 -> eXcel Calibration Report
16:33:57.865 -> ADC_VinRaw:0 Vin:03.612 ADC_IinRaw:0 Iin:03.198 ADC_VoutRaw:0 Vout:10.403 ADC_IoutRaw:0 Iout:03.998 PWM_SetVout:0707 SetVout:14.400 PWM_SetIout:0648 SetIout:04.000 PWM_Fan:2000 
16:33:58.857 -> ADC_VinRaw:0 Vin:03.625 ADC_IinRaw:0 Iin:03.196 ADC_VoutRaw:0 Vout:10.406 ADC_IoutRaw:0 Iout:03.994 PWM_SetVout:0707 SetVout:14.400 PWM_SetIout:0648 SetIout:04.000 PWM_Fan:2000 
16:33:59.849 -> ADC_VinRaw:0 Vin:03.639 ADC_IinRaw:0 Iin:03.193 ADC_VoutRaw:0 Vout:10.409 ADC_IoutRaw:0 Iout:03.991 PWM_SetVout:0707 SetVout:14.400 PWM_SetIout:0648 SetIout:04.000 PWM_Fan:2000 
16:34:00.884 -> ADC_VinRaw:0 Vin:03.653 ADC_IinRaw:0 Iin:03.191 ADC_VoutRaw:0 Vout:10.412 ADC_IoutRaw:0 Iout:03.988 PWM_SetVout:0707 SetVout:14.400 PWM_SetIout:0648 SetIout:04.000 PWM_Fan:2000  
```
- Record the value of ADC_VinRaw: in the spreadsheet in cell D19.
- Give exactly 30 V at the input of your DC/DC converter.
- Record the value of ADC_VinRaw: in the spreadsheet in cell D39.

## Calibrating the output voltage range
Using the serial terminal program, change the output voltage by entering a sequence of +++[return] or ------[return] until the output voltage is exactly 6V.
- Record the value of ADC_VoutRaw: in the spreadsheet in cell E15
- Record the value of PWM_Vset: in the spreadsheet in cell B15
- change the output voltage by entering a sequence of +++[return] or ------[return] until the output voltage is exactly 26V.
- Record the value of ADC_VoutRaw: in the spreadsheet in cell E35
- Record the value of PWM_Vset: in the spreadsheet in cell B35

## Calibrating the output current range
Connect your bulb and the multimeter measuring current
Using the serial terminal program, change the output current by entering a sequence of >>>[return] or <<<<<[return] until the output current is exactly 100mA
- Record the value of ADC_VoutRaw: in the spreadsheet in cell F10
- Record the value of PWM_Vset: in the spreadsheet in cell C10
- change the output voltage by entering a sequence of +++[return] or ------[return] until the output voltage is exactly 1,6A
- Record the value of ADC_VoutRaw: in the spreadsheet in cell F25
- Record the value of PWM_Vset: in the spreadsheet in cell C25

Congratulations!
The calibration procedure is finalised.

Copy of green values of the frame into the corresponding header file:
e.g.:

![image](https://user-images.githubusercontent.com/14197155/115987923-82faba00-a5b7-11eb-8b44-a7be760487db.png)

into the respective header file of the converter used:

```
// #include Drok6008
// All values computed by CalibrationTTGO&ADS1115.xls on GitHub.
#define ADC_IS_ADS1115

// V is output voltage, I is ouput current, P (panel) is input voltage
// BIAS is the value at 0, 
// STEP is the number of PVM or mV feed_back units to increase by 1V or 100mA
// RES is the mV, mA change for one unit of feedback or PWM.I2C (Grove) connector
// Panel Volt FB resistor is 5.0M Ohm (external wire)


#define PWM_Vout_BIAS	-1.2000  
#define PWM_Vout_STEP	18.2000  
#define PWM_Vout_RES	54.9451  
	
#define PWM_Iout_BIAS	68.1500  
#define PWM_Iout_STEP	8.8500
#define PWM_Iout_RES	11.2994
	
#define FB_Vin_BIAS	0.0000
#define FB_Vin_STEP	29.8000
#define FB_Vin_RES	33.5570
	
#define FB_Vout_BIAS	0.0000
#define FB_Vout_STEP	29.1667
#define FB_Vout_RES	34.2857
	
#define FB_Iout_BIAS	109.8750
#define FB_Iout_STEP	14.1250
#define FB_Iout_RES	7.0796


#define ADS_Ch0_Range  ADS1115_RANGE_0256
#define ADS_Ch1_Range  ADS1115_RANGE_2048
#define ADS_Ch2_Range  ADS1115_RANGE_2048
#define ADS_Ch3_Range  ADS1115_RANGE_2048
#define FB_Vout_PIN  ADS1115_COMP_3_GND
#define FB_Iout_PIN  ADS1115_COMP_2_GND
#define FB_Vin_PIN   ADS1115_COMP_1_GND
#define FB_Iin_PIN   ADS1115_COMP_0_GND

#define VIN_MAX      65
#define VOUT_MAX     60
#define IOUT_MAX     8

#define FAN_AMPS_0   1.5
#define FAN_AMPS_100 5 
```


Compile.
Enjoy!






