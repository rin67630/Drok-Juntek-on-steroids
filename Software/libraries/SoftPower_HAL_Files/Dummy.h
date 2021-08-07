// #include Dummy
// All values computed by CalibrationTTGO&ADS1115.xls on GitHub.

// V is output voltage, I is ouput current, P (panel) is input voltage
// BIAS is the value at 0, 
// STEP is the number of PVM or mV feed_back units to increase by 1V or 100mA
// RES is the mV, mA change for one unit of feedback or PWM.
// Panel Volt FB resistor is built_in

#define PWM_Vout_BIAS  29.4000
#define PWM_Vout_STEP  47.1000
#define PWM_Vout_RES    2.1231
  
#define PWM_Iout_BIAS  97.2667
#define PWM_Iout_STEP  56.7333
#define PWM_Iout_RES   17.6263
	
#define FB_Vin_BIAS	0.0000
#define FB_Vin_STEP	30.3333
#define FB_Vin_RES	32.9670

#define FB_Iin_BIAS	14.0000
#define FB_Iin_STEP	39.0323
#define FB_Iin_RES 	2.5620

#define FB_Vout_BIAS	47.2000
#define FB_Vout_STEP	33.6333
#define FB_Vout_RES 	29.7324
	
#define FB_Iout_BIAS	74.4500
#define FB_Iout_STEP	8.9250
#define FB_Iout_RES  	11.2045

#define VIN_MAX      38
#define VOUT_MAX     36
#define IOUT_MAX     3
#define FAN_AMPS_0   1
#define FAN_AMPS_100 2.5 
