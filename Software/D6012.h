// #include Drok6012
// All values computed by CalibrationTTGO&ADS1115.xls on GitHub.
#define ADC_IS_ADS1115

// V is output voltage, I is ouput current, P (panel) is input voltage
// BIAS is the value at 0, 
// STEP is the number of PVM or mV feed_back units to increase by 1V or 100mA
// RES is the mV, mA change for one unit of feedback or PWM.I2C (Grove) connector
// Panel Volt FB resistor is 3.0M Ohm (external wire)

#define BOARD "Drok6012"

#define PWM_Vout_BIAS	27.8000
#define PWM_Vout_STEP	21.0333
#define PWM_Vout_RES	47.5436
	
#define PWM_Iout_BIAS	46.4000
#define PWM_Iout_STEP	5.6000
#define PWM_Iout_RES	17.8571
	
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

#define ADS_Ch0_Range ADS1115_RANGE_0256
#define ADS_Ch1_Range ADS1115_RANGE_2048
#define ADS_Ch2_Range ADS1115_RANGE_2048
#define ADS_Ch3_Range ADS1115_RANGE_4096
#define FB_Iin_PIN   ADS1115_COMP_0_GND
#define FB_Vin_PIN   ADS1115_COMP_1_GND
#define FB_Vout_PIN  ADS1115_COMP_2_GND
#define FB_Iout_PIN  ADS1115_COMP_3_GND

#define PWM_Iout_PIN 4
#define PWM_Vout_PIN 5
#define ENA_PIN   12
#define FAN_PIN   2
#define CC_CV_PIN  N/A

#define VIN_MAX      75
#define VOUT_MAX     60
#define IOUT_MAX     12
#define FAN_AMPS_0   2
#define FAN_AMPS_100 8 
