// #include Drok6012
// All values computed by CalibrationTTGO&ADS1115.xls on GitHub.

// V is output voltage, I is ouput current, P (panel) is input voltage
// BIAS is the value at 0, 
// STEP is the number of PVM or mV feed_back units to increase by 1V or 100mA
// RES is the mV, mA change for one unit of feedback or PWM.I2C (Grove) connector
// Panel Volt FB resistor is 3.0M Ohm (external wire)

#define PWM_Vout_BIAS	29.406
#define PWM_Vout_STEP	20.906
#define PWM_Vout_RES	47.833
	
#define PWM_Iout_BIAS	51.378
#define PWM_Iout_STEP	5.733
#define PWM_Iout_RES	17.443
	
#define FB_Vin_BIAS   	0.000
#define FB_Vin_STEP    	30.200
#define FB_Vin_RES   	33.112
	
#define FB_Iin_BIAS   	0.501
#define FB_Iin_STEP   	44.318
#define FB_Iin_RES   	2.256
	
#define FB_Vout_BIAS	48.350
#define FB_Vout_STEP	33.310
#define FB_Vout_RES 	30.021

#define FB_Iout_BIAS	73.812
#define FB_Iout_STEP	8.962
#define FB_Iout_RES 	11.158


#define ADS_Ch3_Range ADS1115_RANGE_4096
#define ADS_Ch2_Range ADS1115_RANGE_1024
#define ADS_Ch1_Range ADS1115_RANGE_2048
#define ADS_Ch0_Range ADS1115_RANGE_0256

#define FB_Iout_PIN  ADS1115_COMP_3_GND
#define FB_Vout_PIN  ADS1115_COMP_2_GND
#define FB_Vin_PIN   ADS1115_COMP_1_GND
#define FB_Iin_PIN   ADS1115_COMP_0_GND

#define VIN_MAX      75
#define VOUT_MAX     60
#define IOUT_MAX     12
#define FAN_AMPS_0   2
#define FAN_AMPS_100 8 

#define FAN_AMPS_0    2
#define FAN_AMPS_100  8
