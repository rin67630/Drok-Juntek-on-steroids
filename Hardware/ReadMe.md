This folder will contain the schematics and hardware description of my Drok-Juntek-on-steroids solution.  
The design uses standard buck converters, an ESP32 module, simple prototyping boards and a few resistors/condensators.
The adapter boards will be slightly different for Drok and Juntek since the pinout varies.
Other ESP32 modules can be used, possibly a TTGO version with a nicer color display will be provided.

Further variants, _ will be described in detail later_ just to give an outlook of the conceptual flexibility.  
The ESP32's ADC are really bad and the simple solution with a few resistors/condensators works, but are stained with +-50mV and +- 50mA error range.
A more precise version with a separate ADC will be provided, requiring however mor components.

Enjoy!

**Last but not least:**
I am giving very detailed explanations and pictures on how to solder Drok-Juntek-on-steroids on a protoyping board. It got now very close to become a full blown PCB.  
I just have not time to learn how to handle a PCB CAD and must concentrate on software.  
It would be GREAT, if someone familiar with KiCAD or other ECAD designers would contribute...
