# Extension headers

the standard layout provides two extension headers:
- A Grove-compatible extension header
- A universal extension header

## Grove-compatible extension header
The Grove-compatible extension header uses the standard pinout of the Grove I2C ecosystem adding supplementary ground line and a +5V
on the prototyping board this connector is at the 2.54mm pitch, on the future PCB it should use the Grove system 2mm pitch.

## Universal extension header
The universal extension header exposes all still unused IO lines DAC/ADC lines, the I2C port and some power supply lines.
The (potential) applications are: 
- Rotary control
- I2C keyboard
- Additional I2C sensors (e.g. battery temperature, load currents, light intensity, non-related measurements )
- Additional controls like Load on-off, (I have an extension load control module with 3 FETs and 3 current/voltage feed-back measures in planing)
- and even the potential ability to control a second Drok either for a second source, or a voltage controlled load (e.g. the Juntek 3806 buck boost DC/DC  converter to charge secondary batteries at lower higher voltages)
- everything else from my mad imagination...
I have foreseen the extension connectors just to make an eventual PCB future-proof.
