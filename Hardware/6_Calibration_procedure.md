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

We will, for each measurement, to record two values low/high at known values.
The results will be entered in an excel file /hardware/CalibrationTTGO&ADS1115.xlsx
Once all values are entered, the spreadsheet calculates the respective bias/step/ and resolution values and prepares the # include parameters to update the header file.

## Calibrating the input voltage range
Open a serial terminal program e.g. the serial monitor of the Arduino IDE.
- Enter the command "sD" to call the debugging report every second.
- Give exactly 10 V at the input of your DC/DC converter.
The report should print something like:
```
23:33:37.908 -> ADC_VinRaw:625 Vin:20.978 ADC_VoutRaw:418 Vout:14.324 ADC_IoutRaw:116 Iout:00.018 PWM_Vset:0260 Vset:14.400 PWM_Cset:0130 Iset:00.700 
23:33:38.911 -> ADC_VinRaw:625 Vin:20.975 ADC_VoutRaw:418 Vout:14.329 ADC_IoutRaw:113 Iout:00.021 PWM_Vset:0260 Vset:14.400 PWM_Cset:0130 Iset:00.700 
23:33:39.914 -> ADC_VinRaw:626 Vin:20.979 ADC_VoutRaw:418 Vout:14.329 ADC_IoutRaw:110 Iout:00.009 PWM_Vset:0260 Vset:14.400 PWM_Cset:0130 Iset:00.700 
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
```
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
```
![image](https://user-images.githubusercontent.com/14197155/115987923-82faba00-a5b7-11eb-8b44-a7be760487db.png)

Compile.
Enjoy!






