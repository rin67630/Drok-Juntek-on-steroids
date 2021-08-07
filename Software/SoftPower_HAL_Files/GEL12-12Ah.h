// Solar charger dashboard.phases
#define NIGH         0  // panel voltage < battery voltage Low-Power mode
#define RECO         1  // battery voltage < LOWLIM, panel current > low limit, cut off load 
#define BULK         2  // battery voltage < FLOAT, current limited by battery
#define PANL         3  // battery voltage < FLOAT, current limited by panel
#define ABSO         4  // battery voltage > FLOAT < ABSORB, current limited by battery and time
#define FLOA         5  // battery voltage = FLOAT
#define EQUA         6  // battery voltage = EQUALIZE, current limited by battery and time
#define OVER         7  // battery voltage > ABSORB and not EQUALIZATION
#define DISC         8  // battery voltage < LOWLIM, panel current < low limit , cut off load
#define PAUS         9  // no charge, wait for a defined time
#define NOBA         10 // no battery current possible at Vbat = ABSORB
#define NOPA         11 // no panel current for more than 20h
#define EXAM         12 // evaluate battery condition

float phase_ratio_C[] = {0, 0.05, 0.2, 0.2, 0.1, 0.1, 0.1, 0, 0, 0, 0, 0, 0};
float phase_voltage[] = {0, 12.4, 13.8, 13.8, 14.4, 13.7, 15.2, 15.6, 11.0, 0, 0, 0, 0};
#define MIN_VOLT 10.8
#define MAX_VOLT 15.6
#define BAT_AH          12
#define BAT_TEMP_COMP   30           //mV per°C under 25°C
#define BAT_CURRENT_HYSTERESIS 700   //mV difference between charging/discharging voltage @ 1A for evaluation of charging percentage
