// #include Dummy
// All values computed by CalibrationTTGO&ADS1115.xls on GitHub.
#define ADC_IS_SIMULATED
#define VBAT_MIN     10
#define VBAT_MAX     14.5
#define AhBAT        100
#define OHM_BAT      0.023
#define BOARD "Dummy"

// V is output voltage, I is ouput current, P (panel) is input voltage
// BIAS is the value at 0, 
// STEP is the number of PVM or mV feed_back units to increase by 1V or 100mA
// RES is the mV, mA change for one unit of feedback or PWM.
// Panel Volt FB resistor is built_in
#define BOARD "Dummy"

#define PWM_Vout_BIAS  29.4000
#define PWM_Vout_STEP  47.1000
#define PWM_Vout_RES    2.1231
  
#define PWM_Iout_BIAS  97.2667
#define PWM_Iout_STEP  56.7333
#define PWM_Iout_RES   17.6263
  
#define FB_Vin_BIAS    -6.0000
#define FB_Vin_STEP    62.2000
#define FB_Vin_RES     16.0772
  
#define FB_Vout_BIAS   47.6000
#define FB_Vout_STEP   71.2000
#define FB_Vout_RES    14.0449
  
#define FB_Iout_BIAS  144.7333
#define FB_Iout_STEP   85.2667
#define FB_Iout_RES     1.1728


#define FB_Vout_PIN  ADS1115_COMP_2_GND
#define FB_Iout_PIN  ADS1115_COMP_3_GND
#define FB_Vin_PIN   ADS1115_COMP_1_GND
#define PWM_Iout_PIN 4
#define PWM_Vout_PIN 5
#define ENA_PIN   6
#define FAN_PIN   2
#define CC_CV_PIN 7

#define VIN_MAX      38
#define VOUT_MAX     36
#define IOUT_MAX     3
#define FAN_AMPS_0   1
#define FAN_AMPS_100 2.5 
