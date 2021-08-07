// #include JuntekD3806
// All values computed by CalibrationTTGO&ADS1115.xls on GitHub.

// V is output voltage, I is ouput current, P (panel) is input voltage
// BIAS is the value at 0, 
// STEP is the number of PVM or mV feed_back units to increase by 1V or 100mA
// RES is the mV, mA change for one unit of feedback or PWM.
// Panel FB resistor is 2 MOhm to Pin3 on the back of the Motherboard.

#define PWM_Vout_BIAS	26.124
#define PWM_Vout_STEP	49.393
#define PWM_Vout_RES	20.246
	
#define PWM_Iout_BIAS	50.000
#define PWM_Iout_STEP	27.995
#define PWM_Iout_RES	3.572
	
#define FB_Vin_BIAS   	0.000
#define FB_Vin_STEP    	46.546
#define FB_Vin_RES   	21.484
	
#define FB_Iin_BIAS   	0.499
#define FB_Iin_STEP   	87.898
#define FB_Iin_RES   	1.138
	
#define FB_Iout_BIAS	90.535
#define FB_Iout_STEP	41.853
#define FB_Iout_RES 	2.389
	
#define FB_Vout_BIAS	47.746
#define FB_Vout_STEP	73.173
#define FB_Vout_RES 	13.666




#define ADS_Ch3_Range ADS1115_RANGE_2048
#define ADS_Ch2_Range ADS1115_RANGE_4096
#define ADS_Ch1_Range ADS1115_RANGE_2048
#define ADS_Ch0_Range ADS1115_RANGE_0256

#define FB_Iout_PIN    ADS1115_COMP_3_GND
#define FB_Vout_PIN    ADS1115_COMP_2_GND
#define FB_Vin_PIN     ADS1115_COMP_1_GND
#define FB_Iin_PIN     ADS1115_COMP_3_GND

#define VIN_MAX        40
#define VOUT_MAX       60
#define IOUT_MAX       6

#define FAN_AMPS_0     1.5
#define FAN_AMPS_100   4
