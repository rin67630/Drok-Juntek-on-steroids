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
float phase_voltage[] = {0, 9, 12, 12, 12.6, 12.6, 12.6, 12.6, 9.0, 0, 0, 0, 0};
#define MIN_VOLT     9.0 //V
#define MAX_VOLT     16.6 //V
#define BAT_AH   13 //Ah
#define BAT_TEMP_COMP  30 //mV per°C under 25°C
