
This folder contains the schematics and hardware description of my Drok-Juntek-on-steroids solution. 

# History
On a first approach V1.0, I have used a passive circuitry with resistors and capacitors to adapt the signal levels to the ADCs of the ESP32 and -to a certain extent- compensate the intrinsic deficits of the ESP32 ADCs.  
(You can take a look at the ReadMeV1.md if you are interested)

# V2.0 

Finally with V2.0 I decided to use an I2C 16bit, 4 channel ADC  ADS1115 module to replace the very low quality ADCs of the ESP32.    
With this module, conveniently placed under the TTGO, everything becomes much easier.
This new solution uses less components, is much more precise, factory calibrated and the measuring ranges can be determined by software.
The design uses standard buck converters, an ESP32 TTGO TFT module, simple prototyping boards and a few resistors/condensators. 

 ## Bill of materials Off Board

- Juntek DSP 3606 / Drok 
- TTGO ESP32 TFT board
- ADS1115 external ADC board
- 4 x 6 cm prototyping board
- 1 x 3,3MM resistor to measure up to 58V Vin for Drok, 2k resistor to measure Vin for JuntekD3806, nothing for Juntek B3603.

 ## Bill of materials On Board
![image](https://user-images.githubusercontent.com/14197155/130932996-c2326ef9-e03d-4b74-bf2a-86ed12355a69.png)

## Header pinouts (comparison between Juntek / Drok)
![image](https://user-images.githubusercontent.com/14197155/116315430-ccfac000-a7b0-11eb-8aca-cfaca9a70dd4.png)  

**N.B.** If you can, order female pin headers with long pins. The ESP32's socket must be soldered higher than the one of the ADS1115.  

To a certain extend it is doable with regular female headers too:  
On the ADS1115 solder the male pin headers normally, then remove the plastic part of them and cut the pins 5mm shorter.  
That way, the ADS1115 PCB sits directly on the female headers. 
Solder the female headers of the ESP32 with some space between the board and the plastic.  
That lets enough room to piggy-back both modules.

A low profile header / pins for the ADC1115 were the king solution, they are however rare and expensive.


## Proto Wiring
It's relativly easy to wire the adapter to a prototyping board:
### Top view (component side)
![image](https://user-images.githubusercontent.com/14197155/116315567-ffa4b880-a7b0-11eb-81fa-959041c7d8f0.png)

The prototype is universal and fits Juntek/MingHe  and Drok DC/DC conveters.
Since they have some slight difference in the left connector, I have used jumpers.

## PCB
a PCB is now on the final stage... (Thanks to TechColab).
The PCB is designed universal for all supported DC-DC converters.
![image](https://user-images.githubusercontent.com/14197155/130929363-225f5379-17b6-4cc5-97d8-0bba220f7ccd.png)
![image](https://user-images.githubusercontent.com/14197155/130929512-58dedddb-3144-4b42-99c7-8810c854795b.png)

![image](https://user-images.githubusercontent.com/14197155/131181306-fe5a52b8-3b07-4462-9f7d-0b38168d6822.png)

n.b. The 470μF condensator is wired horizontal, we did not have a KiCAD library for that, so it is hot rendered.
The patch fields are shown empty, normally you just will wire a few wires directly but you may poulate them with 90° headers and use prototype jumpers.
On the west side w have 2 header connectors with the analog and control pins, useful for hooking measuring probes.
![image](https://user-images.githubusercontent.com/14197155/131092820-b1ae296f-d175-41c3-814f-16ed135e60da.png)

## Schematic diagram
![image](https://user-images.githubusercontent.com/14197155/131208408-491fee95-9c39-4e8e-adb6-a0c7df7e2d65.png)


# V1.0 
V1.0 is obsolete, that old version used the ESP32 only as ADC and was REALLY inaccurate, see ReadMeV1.md

Enjoy!
