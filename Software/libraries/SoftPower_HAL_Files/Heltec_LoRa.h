// Compile with ESP32 Heltec LoRa (not V2!)

// Pins 6 to 11 are connected to the integrated SPI flash never use!

#define I2C_SCL     15  // GPIO22 for I2C (Wire) System Clock
#define I2C_SDA      4  // GPIO21 for I2C (Wire) System Data   // 21 is standard.
#define I2C_RST     16  //    GPIO0
#define OLED_SCL    15  // GPIO22 for I2C (Wire) System Clock
#define OLED_SDA     4  // GPIO21 for I2C (Wire) System Data

#define ROTARY_ENCODER_A_PIN      22 // Rotary Encoder A
#define ROTARY_ENCODER_B_PIN      23 // Rotary Encoder B
#define ROTARY_ENCODER_BUTTON_PIN 17 // Rotary Encoder Switch
#define ROTARY_ENCODER_STEPS      4  // Rotary Encoder Delta (Steps not an input!)

#define BUTTON_UP     0   //Is also Prog button
#define BUTTON_DOWN   2      

#define ADC_VOUT    36    // not used with external ADC
#define ADC_IOUT    37    // not used with external ADC
#define ADC_VIN     38    // not used with external ADC
#define ADC_IIN     39    // not used with external ADC
#define PWM_V       13    //(Vpwm)
#define PWM_I       12    //(Ipwm) 
#define ENA_PIN     21    // Enable pin
#define FAN_PIN     25    // Is also LED
#define CC_CV_PIN   n/a
#define EXT_out     21    // Control the external power out
