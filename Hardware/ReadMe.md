
This folder contains the schematics and hardware description of my Drok-Juntek-on-steroids solution.   

On a first approach V1.0, I have used a passive circuitry with resistors and capacitors to adapt the signal levels to the ADCs of the ESP32 and -to a certain extent- compensate the intrinsic deficits of the ESP32 ADCs.  
(You can take a look at the remaining V1.0 description at the bottom of This file.) 

# V2.0 

Finally with V2.0 I decided to use an I2C 16bit, 4 channel ADC  ADS1115 module to replace the very low quality ADCs of the ESP32..  
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

- C7 	1	yes	470µ	Capacitor_THT:CP_Radial_D8.0mm_P3.50mm
- C1 C2 C3 C4 C5 C6 C8 	7	yes	0.1µ	Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm
		Ref		     Qtty Required  Description
- J1 J2 	      2	yes	To PSU host board	Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical
- J10 	        1	yes	ADS1115	Connector_PinSocket_2.54mm:PinSocket_1x10_P2.54mm_Vertical
- J11 J12 J61 	3	no	patch	Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical
- J21 	        1	no	patch	Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical
J- 22 	        1	no	patch	Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical
- J30 	        1	optional	Expansion1	Connector_PinHeader_2.54mm:PinHeader_1x21_P2.54mm_Horizontal
- J4 J5 	      2	yes	ESP32-TFT	Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical
- J6 	         1	mostly	feedback	Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Horizontal
- J7 	         1	yes	I2C	Connector_JST:JST_PH_B4B-PH-K_1x04_P2.00mm_Vertical
- R11 R12 	    2		68k/zero	Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal
- R15 	        1		2k2/none	Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal
- R13 R14 R16 R17 R18 	5		1k/zero	Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal
- R20 	        1	mostly	100k/none	Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal

![image](https://user-images.githubusercontent.com/14197155/130932996-c2326ef9-e03d-4b74-bf2a-86ed12355a69.png)

## Header pinouts (comparison between Juntek / Drok)
![image](https://user-images.githubusercontent.com/14197155/116315430-ccfac000-a7b0-11eb-8aca-cfaca9a70dd4.png)



## Proto Wiring
There is no PCB yet, it's relativly easy to wire the adapter to a prototyping board:
### Top view (component side)
![image](https://user-images.githubusercontent.com/14197155/116315567-ffa4b880-a7b0-11eb-81fa-959041c7d8f0.png)

I have put much attention to avoid wire crossings, so it should be easy to make a PCB, but i just did not yet enter into that realm.
The prototype is universal and fits Juntek and Drok DC/DC conveters.
Since they have some difference in the left connector, I have used jumpers.

The blue part of the schematic are a provision for extensions, you may omit these parts.

## PCB
a PCB is now on the final stage... (Thanks to TechColab).
The PCB is designed universal for all supported DC-DC converters.
![image](https://user-images.githubusercontent.com/14197155/130929363-225f5379-17b6-4cc5-97d8-0bba220f7ccd.png)
![image](https://user-images.githubusercontent.com/14197155/130929512-58dedddb-3144-4b42-99c7-8810c854795b.png)

![image](https://user-images.githubusercontent.com/14197155/130929011-33952b3b-74ef-4928-b443-ea3e08dbc8d7.png)
The 470μF condensator is wired horizontal, we did not have a KiCAD library for that.
The patch fields are shown with pins, normally you just will wire a few wires directly.
On the west side w have 2 header connectors with the analog pins these are optionaly populated and more testing points to hook probes.


## Schematic diagram

you may find the editable schematic in the last version always here:   
https://oshwlab.com/lazlo.lebrun/juntek-on-steroids   
(please use the last page only, the others are obsolete now...)  
You have a PDF Schematic_Juntek on Steroids_2021-04.27.pdf in the Hardware folder as well.


# V1.0 
see ReadMeV1.md

Enjoy!
