// #include Drok6008
// All values computed by CalibrationTTGO&ADS1115.xls on GitHub.

// V is output voltage, I is ouput current, P (panel) is input voltage
// BIAS is the value at 0, 
// STEP is the number of PVM or mV feed_back units to increase by 1V or 100mA
// RES is the mV, mA change for one unit of feedback or PWM.I2C (Grove) connector
// Panel Volt FB resistor is 5.0M Ohm (external wire)

#define PWM_Vout_BIAS	-1.655
#define PWM_Vout_STEP	18.262
#define PWM_Vout_RES	54.760
	
#define PWM_Iout_BIAS	50.000
#define PWM_Iout_STEP	8.918
#define PWM_Iout_RES	11.213
	
#define FB_Vin_BIAS   	0.000
#define FB_Vin_STEP    	31.591
#define FB_Vin_RES   	31.654
	
#define FB_Iin_BIAS   	0.502
#define FB_Iin_STEP   	48.621
#define FB_Iin_RES   	2.057
	
#define FB_Vout_BIAS	-1.648
#define FB_Vout_STEP	29.219
#define FB_Vout_RES 	34.225
	
#define FB_Iout_BIAS	108.104
#define FB_Iout_STEP	14.134
#define FB_Iout_RES 	7.075


#define ADS_Ch3_Range ADS1115_RANGE_1024
#define ADS_Ch2_Range ADS1115_RANGE_2048
#define ADS_Ch1_Range ADS1115_RANGE_2048
#define ADS_Ch0_Range ADS1115_RANGE_0256

#define FB_Vout_PIN  ADS1115_COMP_3_GND
#define FB_Iout_PIN  ADS1115_COMP_2_GND
#define FB_Vin_PIN   ADS1115_COMP_1_GND
#define FB_Iin_PIN   ADS1115_COMP_0_GND



#define VIN_MAX      60
#define VOUT_MAX     60
#define IOUT_MAX     8

#define FAN_AMPS_0   1.5
#define FAN_AMPS_100 5 
