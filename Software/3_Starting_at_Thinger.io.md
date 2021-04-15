# Starting at Thinger.io

Using Thinger.io is not a precondition, but it makes Drok-Juntek-on-steroids really comfortable and provides a lot of the visibility. 
The following instructions will help you creating an account and the first device at Thinger.io, that is compatible with the Soft-Power example given out of the box.  

## Create a free account
First you need to register at www.thinger.io, take note of your username and password.
Chose a user name and note it.
After confirming your registration go to:
https://console.thinger.io/#!/console/ (this will be your main starting point: good to bookmark it!)
The most important feature for a beginning are:
- Dashboards
- Devices
- Data Buckets

## Preparing your account
First you will need to create a device: Select Devices, then Add Device.  
- leave the device type unchanged  
- as a device ID I recommend to use "Steroids" (without the quotes), you must change that for your second device.  
- enter whatever you want as a device description  
- enter a password as a device credentials (not your password for Thinger.io)  
Click on "Add Device"

Then you must enter the for buckets used by Soft-Power: Select Data Buckets, then Add Bucket.  
you will need to define the following buckets:  
1. EVENT
2. DAY
3. HOUR
4. MIN
for each one, enter exactly the buckets ID. you may enter what you want as a bucket name and bucket description.  
As a data source select " from device write call" out of the drop-down lists.  
Click on "Add bucket"  
Finally you should get that picture:  
![image](https://user-images.githubusercontent.com/14197155/106428750-c090f080-6469-11eb-9144-6d397d9651bf.png)    

## Creating a dashboard.
You can finally enter your first dashboard: Select Dashboards, then  Add Dashboard.  
- you may enter any dashboard ID, dashboard name, dashboard description.  
Click on Add Dashboard
Then click on the name of your newly created dashboard, you will get that picture:  
![image](https://user-images.githubusercontent.com/14197155/106428750-c090f080-6469-11eb-9144-6d397d9651bf.png)  
upon clicking on the right slider you enter the design mode (you can do that anytime from anywhere).  
You may now enter widgets yourself, but for the first dashboard, I can provide a preconfigured powerful dashboard:  
Click on Settings, on the pop-up click on the tab "Developer"  
You will get a small JSON list corresponding to an empty dashboard. 

## Cloning template dashboards.
To start easily, I am providing a preconfigured dashboard in a vertical tablet format.
Dashboard_json.h in the Arduino IDE. 
The file is not intended to be compiled in any way by C++, it is just placed there for convenience. 

"SteroidsADS" with your own device name
and
"SoftPower1" with your username at thinger.io.
with your device and user name.
The arduino IDE does the job perfectly.

Once the file is adapted to your requirement you can cut and paste its content in place of the json content of the tab "Developer".
Save the developer view.

Enjoy your preconfigured Drok-Juntek-on-steroids dashboard!  
![image](https://user-images.githubusercontent.com/14197155/114902318-ffea9e80-9e15-11eb-9235-9589b24c6f71.png)
   
The dashboard is best viewed on a vertical tablet or a smart phone: change the zoom level of your browser to get the best display.
Of course if you prefer a horizontal view, you may move the widgets to match your preferences.

** Further design possibilities
Thinger.io dashboard system allows creating nice data representation interfaces within minutes in a very simple way.  
No coding is required, just selecting different widgets from a list and using drag&drop technology to configure the layout of the dashboard, then using the configuration forms it is possible to set the data sources, sampling interval, and other behaviors of each widget.  
The main types of these widgets are: 

* **Real-time** data representation
* **Historical** data representation from buckets 
* **Control** device functions or change values with On/Off buttons or sliders  

https://docs.thinger.io/features/dashboards#create-a-dashboard  
You may any time enter the design mode by clicking on the right slider.  
Every widget has at its upper right corner 3 icons !  
[image](https://user-images.githubusercontent.com/14197155/106430653-67768c00-646c-11eb-8eee-5a0c796d9060.png)  
corresponding to: duplicate, edit, trash.  
e.g. upon clicking on edit the widget you might get something like:  
![image](https://user-images.githubusercontent.com/14197155/106430945-dbb12f80-646c-11eb-9a95-b2874cdfbfeb.png)  
meaning that that widget is getting its information from device resource named measure, using the value Ipan, which will be sampled every 2 seconds.  
The corresponding ESP8266 code is defined in the Arduino IDE under c-Setup:  
```C++
    thing["measure"] >> [](pson & out)
    {
      out["Vout"]            = dashboard.Vout ;
      out["Iout"]            = dashboard.Iout ;
      out["Wout"]            = dashboard.Wout ;
      out["Ahout"]           = persistance.Ahout ;
      out["Whout"]           = persistance.Whout ;
      out["Vin"]             = dashboard.Vin ;
      out["Iin"]             = dashboard.Iin ;
      out["Iout"]            = dashboard.Iout ;
      out["Vset"]            = dashboard.Vset ;
      out["Iset"]            = dashboard.Iset ;
      out["Vhout"]           = dashboard.Vout - persistance.initial_voltage;
    };
``` 
You might also have other widgets getting their data from "device properties".  
The corresponding ESP8266 code is defined in the Arduino IDE under c-Setup:  
```C++
    pson persistances;// Retrieve Persistance values
    thing.get_property("persistances", persistances);
    persistance.Ahout = persistances["Ah/hour"];
    persistance.Whout = persistances["Wh/hour"];
    persistance.Runseconds = persistances["Runseconds"];
    persistance.initial_voltage = persistances["InitialVoltage"];
```
Device properties are a kind of memory in the cloud, where the ESP can write data and retrieve it.  
This is an essential feature to store information that must survive a reset.  

Last but not least, widgets can get the information from Data Buckets.  
Data buckets are time series information useful to plot longtime trends.  
the structure of the data is defined in the Arduino IDE under c-Setup:  
e.g. for the data being written every minute:  
```C++
    thing["MIN"] >> [](pson & out)
    {
      out["Vout"]             = dashboard.Vout ;
      out["Iout"]             = dashboard.Iout ;
      out["Wout"]             = dashboard.Wout ;
      out["Ahout"]            = persistance.Ahout ;
      out["Whout"]            = persistance.Whout ;
      out["Vin"]              = dashboard.Vin ;
      out["Iin"]              = dashboard.Iin ;
      out["Iout"]            = dashboard.Iout ;
      out["Vset"]            = dashboard.Vset ;
      out["Iset"]            = dashboard.Iset ;
    };
```
and the transmission is triggered in the Arduino IDE under c-Wireless:  
```C++
#if defined (WRITE_BUCKETS)
  if (triglEvent)   thing.write_bucket("EVENT", "EVENT");
  if (NewDay)       thing.write_bucket("DAY", "DAY");
  if (HourExpiring) thing.write_bucket("HOUR", "HOUR");
  if (NewMinute)    thing.write_bucket("MIN", "MIN");
#endif
```
You have even got more possibilities, but that was the most important ones as a starting manual.  
Enjoy your Thinger.io dashboards!  
