# Connectors description



## Motherboard right connector
Luckily, the motherboard right connector has the same pinout for every DC/DC converter:
from the top to the bottom you have a 4 ground connections, 2 +5V connections ( that can approximately supply 100mA) and Tx-Rx pins, that are forwarded to the corresponding Tx-Rx connector on the motherboard.  
2 capacitors C8 and C7 will reduce the impact of the power surges from the RF-transmission to the motherboard.  
![image](https://user-images.githubusercontent.com/14197155/124722731-9f499a00-df0a-11eb-9a4a-693cd53e60e0.png)


## Motherboard left connector
the motherboard left connector is not completely standardised, from the top to the bottom the three first pins carry the feedback signals for the output voltage and the output current at various locations, depending on the board make. One board has a feedback of the input voltage, most don't.  
For that reason, there adapter board will have some jumpers to marshall the signals accordingly to the A2, A3, A1 analog inputs of the ADS1115.  
![image](https://user-images.githubusercontent.com/14197155/124722640-87721600-df0a-11eb-9631-32bf3374cefa.png)

## Feedback of Input voltage or current
On the Juntek 3603, the feedback of the input voltage already exists on pin3 of the left connector.  
On the Juntek 3806, the feedback of the input voltage is not provided, but the pin 3 of the left connector is free, so one can solder a feedback resistor on the motherboard.   
On DROK modules, the pin 3 is not free, so one must go over a side header to provide voltage feedback.  
The current feedback ( optional ) is always to be provided over a side header to ADC0.     

## Extension headers

the standard layout provides two extension headers:
- A Grove-compatible extension header
- A universal extension header

### Grove-compatible extension header
The Grove-compatible extension header uses the standard pinout of the Grove I2C ecosystem adding supplementary ground line and a +5V
on the prototyping board this connector is at the 2.54mm pitch, on the future PCB it should use the Grove system 2mm pitch.
![image](https://user-images.githubusercontent.com/14197155/124719714-b935ad80-df07-11eb-910b-6d9703a3c247.png)


### Universal extension header
The universal extension header exposes all still unused IO lines DAC/ADC lines, the I2C port and some power supply lines.
The (potential) applications are: 
- Rotary control
- I2C keyboard
- Additional I2C sensors (e.g. battery temperature, load currents, light intensity, non-related measurements )
- Additional controls like Load on-off, (I have an extension load control module with 3 FETs and 3 current/voltage feed-back measures in planing)
- and even the potential ability to control a second Drok either for a second source, or a voltage controlled load (e.g. the Juntek 3806 buck boost DC/DC  converter to charge secondary batteries at lower higher voltages)
- everything else from my mad imagination...
I have foreseen the extension connectors just to make an eventual PCB future-proof.
![image](https://user-images.githubusercontent.com/14197155/124784488-44359880-df46-11eb-983a-d6f32ef3adf5.png)


