// #include Juntek3603
// All values computed by CalibrationTTGO&ADS1115.xls on GitHub.
#define ADC_IS_ADS1115

// V is output voltage, I is ouput current, P (panel) is input voltage
// BIAS is the value at 0, 
// STEP is the number of PVM or mV feed_back units to increase by 1V or 100mA
// RES is the mV, mA change for one unit of feedback or PWM.
// Panel Volt FB resistor is built_in
#define BOARD "Juntek3603"

#define PWM_Vout_BIAS  29.4000
#define PWM_Vout_STEP  47.1000
#define PWM_Vout_RES    2.1231
  
#define PWM_Iout_BIAS  97.2667
#define PWM_Iout_STEP  56.7333
#define PWM_Iout_RES   17.6263
  
#define FB_Vin_BIAS    -6.0000
#define FB_Vin_STEP    62.2000
#define FB_Vin_RES     16.0772

#define FB_Iin_BIAS	   14.0000
#define FB_Iin_STEP	   39.0323
#define FB_Iin_RES 	   2.5620
  
#define FB_Vout_BIAS   47.6000
#define FB_Vout_STEP   71.2000
#define FB_Vout_RES    14.0449
  
#define FB_Iout_BIAS  144.7333
#define FB_Iout_STEP   85.2667
#define FB_Iout_RES     1.1728

#define ADS_Ch0_Range ADS1115_RANGE_0256
#define ADS_Ch1_Range ADS1115_RANGE_2048
#define ADS_Ch2_Range ADS1115_RANGE_2048
#define ADS_Ch3_Range ADS1115_RANGE_2048
#define FB_Iin_PIN   ADS1115_COMP_0_GND
#define FB_Vin_PIN   ADS1115_COMP_1_GND
#define FB_Vout_PIN  ADS1115_COMP_2_GND
#define FB_Iout_PIN  ADS1115_COMP_3_GND

#define PWM_Iout_PIN 4
#define PWM_Vout_PIN 5
#define ENA_PIN   12
#define FAN_PIN   2


#define VIN_MAX      38
#define VOUT_MAX     36
#define IOUT_MAX     3
#define FAN_AMPS_0   1
#define FAN_AMPS_100 2.5 

