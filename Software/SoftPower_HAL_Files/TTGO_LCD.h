// Compile with ESP32 TTGO T1

// Pins 6 to 11 are connected to the integrated SPI flash never use!

#define I2C_SCL     22  // GPIO5 for I2C (Wire) System Clock
#define I2C_SDA     21  // GPIO4 for I2C (Wire) System Data
#define I2C_RST     16  //    GPIO0
#define TFT_BL       4  // Display backlight control pin

#define ROTARY_ENCODER_A_PIN      25 // Rotary Encoder A
#define ROTARY_ENCODER_B_PIN      26 // Rotary Encoder B
#define ROTARY_ENCODER_BUTTON_PIN 33 // Rotary Encoder Switch
#define ROTARY_ENCODER_STEPS      4  // Rotary Encoder Delta (Steps) not an input!

#define BUTTON_UP    35
#define BUTTON_DOWN  0  

#define ADC_VOUT    36
#define ADC_IOUT    39
#define ADC_VIN     38
#define PWM_V       15  // Pin GPIO15  (Vpwm)
#define PWM_I       13  // Pin GPIO13  (Ipwm) 
#define ENA_PIN     12  // Enable pin
#define FAN_PIN     2
#define CC_CV_PIN   n/a
