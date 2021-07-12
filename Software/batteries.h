// Battery parameters
#ifdef BATTERY_IS_12V_FLA
float phase_ratio_C[] = {0, 0.05, 0.2, 0.2, 0.1, 0.1, 0.1, 0, 0, 0, 0, 0, 0};
float phase_voltage[] = {0, 12.4, 13.8, 13.8, 14.6, 13.7, 15.2, 15.6, 11.0, 0, 0, 0, 0};
#define MIN_VOLT 10.8
#define MAX_VOLT 15.6
#endif
#ifdef BATTERY_IS_12V_AGM
float phase_ratio_C[] = {0, 0.05, 0.2, 0.2, 0.1, 0.1, 0.1, 0, 0, 0, 0, 0, 0};
float phase_voltage[] = {0, 12.4, 13.8, 13.8, 14.4, 13.7, 14.4, 15.6, 11.0, 0, 0, 0, 0};
#define MIN_VOLT 10.8
#define MAX_VOLT 15.6
#endif
#ifdef BATTERY_IS_12V_GEL
float phase_ratio_C[] = {0, 0.05, 0.2, 0.2, 0.1, 0.1, 0.1, 0, 0, 0, 0, 0, 0};
float phase_voltage[] = {0, 12.4, 13.8, 13.8, 14.4, 13.7, 15.2, 15.6, 11.0, 0, 0, 0, 0};
#define MIN_VOLT 10.8
#define MAX_VOLT 15.6
#endif
#ifdef BATTERY_IS_12V_LIFEPO
float phase_ratio_C[] = {0, 0.3, 1, 1, 0.5, 0.1, 0.3, 0, 0, 0, 0, 0, 0};
float phase_voltage[] = {0, 11.4, 13.2, 13.7, 13.7, 12.0, 12.0, 12.0, 10.5, 0, 0, 0, 0};
#define MIN_VOLT 10.36
#define MAX_VOLT 14.97
#endif
#ifdef BATTERY_IS_11V_LIPO
float phase_ratio_C[] = {0, 0.3, 1, 1, 0.5, 0.1, 0.3, 0, 0, 0, 0, 0, 0};
float phase_voltage[] = {0, 10, 12.8, 12.8, 12.8, 12.8, 12.8, 12.8, 10.5, 0, 0, 0, 0};
#define MIN_VOLT 10.05
#define MAX_VOLT 14.45