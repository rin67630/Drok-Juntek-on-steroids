// compile with ESP32 Wemos LoLin32

// Pins 6 to 11 are connected to the integrated SPI flash never use!
// Pin2 should be connected to on-Board-LED
// Pin 34 to 39 are input only, no pull up, no pulldown.

//#define I2C_SCL     22  // GPIO5 for I2C (Wire) System Clock
//#define I2C_SDA     21  // GPIO4 for I2C (Wire) System Data
#define I2C_SCL      5  // GPIO5 for I2C (Wire) System Clock
#define I2C_SDA      4  // GPIO4 for I2C (Wire) System Data
#define I2C_RST     16  // GPIO0

#define ROTARY_ENCODER_A_PIN      25 // Rotary Encoder A
#define ROTARY_ENCODER_B_PIN      26 // Rotary Encoder B
#define ROTARY_ENCODER_BUTTON_PIN 33 // Rotary Encoder Switch
#define ROTARY_ENCODER_STEPS       4 // Rotary Encoder Delta (Steps) not an input!

#define BUTTON_UP    0
#define BUTTON_DOWN 33

#define ADC_VOUT    36
#define ADC_IOUT    39
#define ADC_VIN     38
#define PWM_V       12 // Pin SD0  (Vpwm)
#define PWM_I       14 // Pin SD1  (Ipwm)
#define CC_CV_PIN   n/a 
#define ENA_PIN     12  // Enable pin
#define FAN_PIN     25 
