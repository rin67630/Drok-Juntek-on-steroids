
This folder contains the schematics and hardware description of my Drok-Juntek-on-steroids solution.   

On a first approach V1.0, I have used a passive circuitry with resistors and capacitors to adapt the signal levels to the ADCs of the ESP32 and -to a certain extent- compensate the intrinsic deficits of the ESP32 ADCs.  
(You can take a look at the remaining V1.0 description at the bottom of This file.) 

# V2.0 

Finally with V2.0 I decided to use an I2C 16bit, 4 channel ADC  ADS1115 module to replace the very low quality ADCs of the ESP32..  
With this module, conveniently placed under the TTGO, everything becomes much easier.
This new solution uses less components, is much more precise, factory calibrated and the measuring ranges can be determined by software.
The design uses standard buck converters, an ESP32 TTGO TFT module, simple prototyping boards and a few resistors/condensators. 

 ## Bill of materials

- Juntek DSP 3606 / Drok 
- TTGO ESP32 TFT board
- ADS1115 external ADC board
- 4 x 6 cm prototyping board
- pin male / female pin headers
- 1 x 100 k resistor
- 1 x 3,3MM resistor to measure up to 58V Vin for Drok, 2k resistor to measure Vin for JuntekD3806, nothing for Juntek B3603.
- 2 x 68 k resistors
- 2 x 1 k resistors 
- 1 x 470uF 16V chem capacitor **

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
this was my first design which is now deprecated.

The design uses standard buck converters, an ESP32 TTGO TFT module, simple prototyping boards and a few resistors/condensators.

 ## Bill of materials
 
- Juntek DSP 3606
- TTGO ESP32 TFT board
- 4 x 6 cm prototyping board
- pin male / female pin headers
- 3 x 100 k resistors
- 3 x 180 k resistors
- 2 x 68 k resistors
- 3 x 5.6 M resistors
- 1 x 220 resistor **
- 1 x 3.9 M (behind the Juntek module to sense Vin)
- 4 x 330nF tantal capacitors **
- 1 x 470uF 16V chem capacitor **
- 1 x 47uF 16V chem capacitor **

The components marked (**) are not critical +- 50% are possible.

## Proto wiring
![image](https://user-images.githubusercontent.com/14197155/111206570-d34e2780-85c8-11eb-8fb4-a482fadf0cb9.png) 
![image](https://user-images.githubusercontent.com/14197155/111217876-59bd3600-85d6-11eb-8595-dd1af2165e28.png)

(the PCB layout is simple, even single layer, but i never made a Gerber file, if someone would like to contribute...)  
n.b.: *you may have noticed an apparent discrepancy between the jumper settings on the prototype pictures and the jumper settings in the schematic diagram:
the difference is only that I had to move the pin connectors by one 2.54 step upwards for mechanical reasons and did not want to redraw the diagram accordingly.  

## Schematic diagram
https://github.com/rin67630/Drok-Juntek-on-steroids/blob/main/Hardware/Schematic_Juntek%20on%20Steroids_2021-03-10.pdf

The adapter boards will be slightly different for Drok and Juntek since the pinout varies.  
*that variants to come soon, did not test yet*

Other ESP32 modules can be used, a variant with a BW OLED module and a variant with a HELTEC OLED + LoRa module are  planned, just to give an outlook of the conceptual flexibility.  
The ESP32's ADC are really bad and the simple solution with a few resistors/condensators works, but are stained with +-50mV and +- 50mA error range.
A more precise version with a separate ADC will be provided, requiring however mor components.

Enjoy!

**Last but not least:**
I am giving very detailed explanations and pictures on how to solder Drok-Juntek-on-steroids on a protoyping board. It got now very close to become a full blown PCB.  
I just have not time to learn how to handle a PCB CAD and must concentrate on software.  
It would be GREAT, if someone familiar with KiCAD or other ECAD designers would contribute...
