/*
SoftPower_HAL_Files
(Hardware Abstraction Layer)

These files are used to adapt different hardware configuration to the common SoftPower software.

SoftPower is designed in a flexible way in order to support different hardware components:

*** DC/DC converters ***
- Drok 6012  -> D6012.h   now D6012_PCB.h
- Drok 6008  -> D6008.h
- Juntek B3603  -> J3603.h
- Juntek J3806  -> J3806.h

The DC/DC converter files contain the different factors to convert the feedback voltages and the PWM control voltages to the ADC of SoftPower.
You main change the factors according to new calibration, but can use the existing ones if you are using the recommended register of my schmatic diagram and are satisfied with ~2% accuracy.

ESP32 development boards
- ESP32 TTGO with TFT Display -> TTG_LCD.h
- ESP32 WEMOS with OLED Display -> Wemos_OLED.h
- Heltec ESP32 with LoRa and OLED Display -> Heltec_LoRa.h

The ESP32 development board files mainly contain the input output definitions. You should normally not change that content unless you know what you're doing.

Different battery chemistries.
- Flooded Lead Acid 12V 100Ah FLA12-100Ah.h
- Gel Lead Acid 12V 12Ah GEL12-12Ah.h
- Gel Lead Acid 06V 08Ah GEL06-08Ah.h
- LithiumIon 3*4 18650 cells in series -> LiIon3S-4P-4Ah.h
- LiFePo 4*2 32650 cells in series -> LiFePo_4S-2P-8Ah.h

The battery chemistry files contain the different voltage levels, used for charging, you may change the battery capacity accordingly and the voltages if you know what you're doing. 

There is no need to compile this .ino file all information are included in the main programm: This ino is just provided to facilitate editing.
Please think to save if you have modified something: Since you don't compile the content will not be saved automatically.

*/
