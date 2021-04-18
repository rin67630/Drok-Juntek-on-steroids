# Install IDE and download Software

## Installing the Arduino IDE with ESP support.
https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/

## Installing libraries
You need a few libraries to run Drok-Juntek-on-steroids:  
Start the library manager: Tools/Manage Libraries...  
You need  
- ArduinoJson by Benoit Blanchon
- TFT_eSPI.h from the Arduino library repository or, for the OLED version ESP32...OLED driver, by Thingpulse and Fabrice Weinberg

- thinger.io by Alvaro Luis Bustamente
The other libraries should be already present.

## Download instructions
You can download all the files from the main page of Drok-Juntek-on-steroids upon clicking on the green Code button and selecting "download Zip".    
This will save a file Soft-Power-MPPT-main.zip.  
From that compressed file, extract the folder "Software" and copy it into your Arduino working space, if you and modified it, it's Documents/Arduino  
Rename that folder SoftPowerMPPT.  
You will now find the project in File/Sketchbook/SoftPowerMPPT and after starting, it you will find all tabs present.  

If later you just need to update some tabs individually, you just can copy the content directly into the Arduino IDE.

You must not only install TFT_eSPI library from the library manager, but also configure thie generic library to work with the TFT panel of the TTGO

Go to the root of the TFT_eSPI. Most likely this will be C:\Users\[Your User]\Documents\Arduino\libraries\TFT_eSPI-master
Overwrite the file User_Setup.h  at that location with the User_Setup.h file provided in /Software.

Button2 you must install this lib from the Library manager. 



## Configuration instructions
https://github.com/rin67630/Soft-Power-MPPT//blob/main/Software/Configuration%20Instructions.md

## Dashborad configuration instructions
https://github.com/rin67630/Soft-Power-MPPT//blob/main/Software/Starting%20at%20Thinger.io.md
