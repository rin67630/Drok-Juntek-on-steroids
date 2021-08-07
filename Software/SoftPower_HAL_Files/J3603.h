// #include Juntek3603
// All values computed by CalibrationTTGO&ADS1115.xls on GitHub.

// V is output voltage, I is ouput current, P (panel) is input voltage
// BIAS is the value at 0, 
// STEP is the number of PVM or mV feed_back units to increase by 1V or 100mA
// RES is the mV, mA change for one unit of feedback or PWM.
// Panel Volt FB resistor is built_in

#define PWM_Vout_BIAS	31.665
#define PWM_Vout_STEP	47.058
#define PWM_Vout_RES	21.251
	
#define PWM_Iout_BIAS	50.000
#define PWM_Iout_STEP	54.910
#define PWM_Iout_RES	1.821
	
#define FB_Vin_BIAS   	0.000
#define FB_Vin_STEP    	62.149
#define FB_Vin_RES   	16.090
	
#define FB_Iin_BIAS   	0.504
#define FB_Iin_STEP   	-1030.345
#define FB_Iin_RES   	-0.097
	
#define FB_Vout_BIAS	47.848
#define FB_Vout_STEP	70.816
#define FB_Vout_RES 	14.121
	
#define FB_Iout_BIAS	147.396
#define FB_Iout_STEP	82.739
#define FB_Iout_RES 	1.209


#define ADS_Ch3_Range ADS1115_RANGE_2048
#define ADS_Ch2_Range ADS1115_RANGE_2048
#define ADS_Ch1_Range ADS1115_RANGE_2048
#define ADS_Ch0_Range ADS1115_RANGE_0256

#define FB_Iout_PIN    ADS1115_COMP_3_GND
#define FB_Vout_PIN    ADS1115_COMP_2_GND
#define FB_Vin_PIN     ADS1115_COMP_1_GND
#define FB_Iin_PIN     ADS1115_COMP_3_GND

#define VIN_MAX        38
#define VOUT_MAX       36
#define IOUT_MAX        3

#define FAN_AMPS_0      1
#define FAN_AMPS_100    2.5 
