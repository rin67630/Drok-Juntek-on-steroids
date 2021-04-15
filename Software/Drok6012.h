// #include Drok6012.h
// currently not tested (hardware ordered), assuming identical values as Drok6008.h
#define ADC_IS_ADS1115

// V is output voltage, I is ouput current, P (panel) is input voltage
// BIAS is the value at 0, 
// STEP is the number of PVM or mV feed_back units to increase by 1V or 100mA
// RES is the mV, mA change for one unit of feedback or PWM.
// Panel Volt FB resistor is 5.0M Ohm (external wire)

#define PWM_Vout_BIAS  -1.2000
#define PWM_Vout_STEP 18.2050
#define PWM_Vout_RES  54.9451
  
#define PWM_Iout_BIAS 68.1500
#define PWM_Iout_STEP 8.8500
#define PWM_Iout_RES  112.9944
  
#define FB_Vin_BIAS 0.0000
#define FB_Vin_STEP 29.8000
#define FB_Vin_RES  33.5570
  
#define FB_Vout_BIAS  0.0000
#define FB_Vout_STEP  29.168
#define FB_Vout_RES 34.2857
  
#define FB_Iout_BIAS  109.8750
#define FB_Iout_STEP  14.1250
#define FB_Iout_RES 70.7965


#define FB_Vout_PIN  ADS1115_COMP_2_GND
#define FB_Iout_PIN  ADS1115_COMP_3_GND
#define FB_Vin_PIN   ADS1115_COMP_1_GND
#define PWM_Iout_PIN 4
#define PWM_Vout_PIN 5
#define ENA_PIN   6
#define FAN_PIN   7
#define CCCV_PIN  N/A
