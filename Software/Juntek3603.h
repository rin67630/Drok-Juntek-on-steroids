// #include Juntek3603
// All values computed by CalibrationTTGO&ADS1115.xls on GitHub.
#define ADC_IS_ADS1115

// V is output voltage, I is ouput current, P (panel) is input voltage
// BIAS is the value at 0, 
// STEP is the number of PVM or mV feed_back units to increase by 1V or 100mA
// RES is the mV, mA change for one unit of feedback or PWM.
// Panel Volt FB resistor is built_in

#define PWM_Vout_BIAS  29.40
#define PWM_Vout_STEP  47.10
#define PWM_Vout_RES   21.2

#define PWM_Iout_BIAS  93.33
#define PWM_Iout_STEP  56.67
#define PWM_Iout_RES   17.65

#define FB_Vout_BIAS   47.60
#define FB_Vout_STEP   71.20
#define FB_Vout_RES    14.04

#define FB_Iout_BIAS   145.07
#define FB_Iout_STEP   84.93
#define FB_Iout_RES    1.18

#define FB_Vin_BIAS  _6
#define FB_Vin_STEP  62.20
#define FB_Vin_RES   16.08


#define FB_Vout_PIN  ADS1115_COMP_3_GND
#define FB_Iout_PIN  ADS1115_COMP_2_GND
#define FB_Vin_PIN   ADS1115_COMP_1_GND
#define PWM_Iout_PIN 4
#define PWM_Vout_PIN 5
#define ENA_PIN   6
#define FAN_PIN   N/A
#define CCCV_PIN  7
