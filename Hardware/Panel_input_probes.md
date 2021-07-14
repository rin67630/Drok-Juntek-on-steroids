# Panel input Probes

With the exception of the J3603 the DC-DC converters used do not provide a measurement of the panel voltage, nor its current.  
The input voltage valaue is however essential to control the MPPT. 
The input current is nice to have.  
Most DC-DC converters feed back the output power to the input (the solar panel) which is first wasting a part of energy when the panel does not produce current, 
secondly an inadvertent short on the panel while the battery is connected will be an irresistible call for the magic smoke.
So we will need a diode to block the backfeed current.

Since the panel voltages and current can be pretty high the circuit for them is located away from the control board with resistors limiting the energy fed to the inputs.

All these functions will be realised in two input probes connected just before the inputs of the motherboard.

![image](https://user-images.githubusercontent.com/14197155/125686482-913e222e-b51d-4df7-a70b-682bf2467454.png)

## Voltage probe + blocking diode.

The 10A Schottky diode will be directly soldered to a fork terminal for screws. On the other side the input cable will be soldered to the diode with the feed back resistor (the high side of the input voltage divisor) and finally both sides are wrapped with thermo sleeves:
![image](https://user-images.githubusercontent.com/14197155/125689286-25220c50-038e-4865-8692-bc65307efedf.png)


## Current probe
I have used two 0.05 smd resistors in // (for mechanical stabilty) soldered to a fork terminal and to the input wire at the other side (the fork is folded to fit into the tube and unfolded after) then glued everything in a hard plastic tube. On the shunt, i have a 1kΩ resistor in series to limit the damage if the shunt burns through. Finally both sides are wrapped with thermo sleeves:

![image](https://user-images.githubusercontent.com/14197155/125688707-2d47358a-3885-45ed-a5c6-89df81461a5f.png)
![image](https://user-images.githubusercontent.com/14197155/125688759-1976a904-6b5b-4796-bc14-b44e16530f4c.png)
