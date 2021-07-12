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
	
#define FB_Iin_BIAS	14.0000
#define FB_Iin_STEP	39.0323
#define FB_Iin_RES	2.5620
	
#define FB_Vout_BIAS	0.0000
#define FB_Vout_STEP	29.1667
#define FB_Vout_RES	34.2857
	
#define FB_Iout_BIAS	109.8750
#define FB_Iout_STEP	14.1250
#define FB_Iout_RES	7.0796


#define FB_Vout_PIN  ADS1115_COMP_3_GND
#define FB_Iout_PIN  ADS1115_COMP_2_GND
#define FB_Vin_PIN   ADS1115_COMP_1_GND
#define FB_Iin_PIN   ADS1115_COMP_0_GND
#define PWM_Iout_PIN 4
#define PWM_Vout_PIN 5
#define ENA_PIN   12
#define FAN_PIN   2
#define CC_CV_PIN  N/A

#define VIN_MAX      65
#define VOUT_MAX     60
#define IOUT_MAX     8
#define FAN_AMPS_0   1.5
#define FAN_AMPS_100 5 
