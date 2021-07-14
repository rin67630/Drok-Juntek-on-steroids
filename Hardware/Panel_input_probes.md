# Panel input Probes

With the exception of the J3603 the DC-DC converters used do not provide a measurement of the panel voltage, nor its current.  
The input voltage valaue is however essential to control the MPPT. 
The input current is nice to have.  
Most DC-DC converters feed back the output power to the input (the solar panel) which is first wasting a part of energy when the panel does not produce current, 
secondly an inadvertent short on the panel while the battery is connected will be an irresistible call for the magic smoke.
So we will need a diode to block the backfeed current.

Since the panel voltages and current can be pretty high the circuit for them is not on the board.

All these functions will be realised in two input probes connected just before the inputs of the motherboard.

![image](https://user-images.githubusercontent.com/14197155/125686482-913e222e-b51d-4df7-a70b-682bf2467454.png)
