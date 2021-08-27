EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Drok/Juntek-on-steroids"
Date "2021-08-24"
Rev "3.1"
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x08 J1
U 1 1 6053449F
P 1500 2550
F 0 "J1" H 1500 2950 50  0000 C CNN
F 1 "To PSU host board" V 1600 2500 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 1500 2550 50  0001 C CNN
F 3 "~" H 1500 2550 50  0001 C CNN
	1    1500 2550
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J2
U 1 1 60534CC7
P 10700 3100
F 0 "J2" H 10650 3500 50  0000 L CNN
F 1 "To PSU host board" V 10800 2700 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 10700 3100 50  0001 C CNN
F 3 "~" H 10700 3100 50  0001 C CNN
	1    10700 3100
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 6054F23A
P 10150 2700
F 0 "#PWR0102" H 10150 2550 50  0001 C CNN
F 1 "VCC" H 10165 2873 50  0000 C CNN
F 2 "" H 10150 2700 50  0001 C CNN
F 3 "" H 10150 2700 50  0001 C CNN
	1    10150 2700
	1    0    0    -1  
$EndComp
Text Notes 7950 6350 0    50   ~ 0
VCC = +5Vdc\nSignal labels based on B3603/BST900.
Text Label 10450 3200 2    50   ~ 0
VCC
Text Label 10450 2800 2    50   ~ 0
GNDA
Text Label 10450 3500 2    50   ~ 0
RX
Text Label 10450 3400 2    50   ~ 0
TX
Text Label 6750 1800 3    50   ~ 0
+5V
Text Label 6650 1800 3    50   ~ 0
GND
Text Label 6150 5050 1    50   ~ 0
GPIO2
Text Label 6150 1800 3    50   ~ 0
GPIO32
Text Label 6350 5050 1    50   ~ 0
GPIO13
Text Label 6250 5050 1    50   ~ 0
GPIO15
Text Label 6550 5050 1    50   ~ 0
GND
Text Label 6650 5050 1    50   ~ 0
GND
Text Label 6750 5050 1    50   ~ 0
+3V3
Text Label 5650 1800 3    50   ~ 0
+3V3
Text Label 5650 5050 1    50   ~ 0
GND
Text Label 5750 5050 1    50   ~ 0
GND
Wire Wire Line
	5650 5100 5650 5050
Wire Wire Line
	5750 5050 5750 5100
Wire Wire Line
	6550 5100 6550 5050
Wire Wire Line
	6650 5100 6650 5050
Wire Wire Line
	6750 5100 6750 5050
Wire Wire Line
	5650 1750 5650 1800
Wire Wire Line
	6650 1750 6650 1800
Wire Wire Line
	6750 1750 6750 1800
Wire Wire Line
	10250 2800 10500 2800
Wire Wire Line
	10150 3200 10150 2700
Wire Wire Line
	10150 3200 10450 3200
Connection ~ 10150 2700
Text Label 9000 3650 2    50   ~ 0
GND
Text Label 10450 3000 2    50   ~ 0
GNDD
Wire Wire Line
	10250 3000 10500 3000
Wire Wire Line
	10500 3100 10250 3100
Wire Wire Line
	10250 3100 10250 3000
$Comp
L Jumper:SolderJumper_3_Open JP1
U 1 1 60544F66
P 9900 3100
F 0 "JP1" V 9800 2950 50  0000 L CNN
F 1 "GND/D" H 9800 3200 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm" H 9900 3100 50  0001 C CNN
F 3 "~" H 9900 3100 50  0001 C CNN
	1    9900 3100
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID1
U 1 1 60566EF9
P 9850 5500
F 0 "FID1" H 9935 5546 50  0000 L CNN
F 1 "Fiducial" H 9935 5455 50  0000 L CNN
F 2 "Fiducial:Fiducial_0.5mm_Mask1mm" H 9850 5500 50  0001 C CNN
F 3 "~" H 9850 5500 50  0001 C CNN
	1    9850 5500
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID2
U 1 1 60567887
P 9850 5700
F 0 "FID2" H 9935 5746 50  0000 L CNN
F 1 "Fiducial" H 9935 5655 50  0000 L CNN
F 2 "Fiducial:Fiducial_0.5mm_Mask1mm" H 9850 5700 50  0001 C CNN
F 3 "~" H 9850 5700 50  0001 C CNN
	1    9850 5700
	1    0    0    -1  
$EndComp
$Comp
L Mechanical:Fiducial FID3
U 1 1 60567F13
P 9850 5900
F 0 "FID3" H 9935 5946 50  0000 L CNN
F 1 "Fiducial" H 9935 5855 50  0000 L CNN
F 2 "Fiducial:Fiducial_0.5mm_Mask1mm" H 9850 5900 50  0001 C CNN
F 3 "~" H 9850 5900 50  0001 C CNN
	1    9850 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10250 2800 10250 2900
Wire Wire Line
	10500 2900 10250 2900
Text Label 6450 5050 1    50   ~ 0
GPIO12
Text Label 6550 1800 3    50   ~ 0
GPIO27
Wire Wire Line
	5750 5050 5650 5050
Wire Wire Line
	6650 5050 6550 5050
Text Label 5850 5050 1    50   ~ 0
SDA
Text Label 5950 5050 1    50   ~ 0
SCL
Text Label 6050 5050 1    50   ~ 0
GPIO17
Text Label 6450 1800 3    50   ~ 0
GPIO26
Text Label 6350 1800 3    50   ~ 0
GPIO25
Text Label 6050 1800 3    50   ~ 0
ADC3
Wire Wire Line
	6450 1750 6450 1800
Wire Wire Line
	6350 1750 6350 1800
Text Label 5950 1800 3    50   ~ 0
ADC2
Text Label 5850 1800 3    50   ~ 0
ADC1
Text Label 5750 1800 3    50   ~ 0
ADC0
Wire Wire Line
	10500 3300 10450 3300
Wire Wire Line
	10450 3300 10450 3200
Connection ~ 10450 3200
Wire Wire Line
	10450 3200 10500 3200
Text Label 9250 2700 2    50   ~ 0
+5V
$Comp
L Connector_Generic:Conn_01x12 J5
U 1 1 60540801
P 6250 5300
F 0 "J5" V 6350 5750 50  0000 C CNN
F 1 "ESP32-TFT" V 6350 5000 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical" H 6250 5300 50  0001 C CNN
F 3 "~" H 6250 5300 50  0001 C CNN
	1    6250 5300
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 1750 6550 1800
Wire Wire Line
	5850 5050 5850 5100
Wire Wire Line
	5950 5050 5950 5100
$Comp
L Device:R R17
U 1 1 60BC63B7
P 4750 2900
F 0 "R17" V 4750 2900 50  0000 C CNN
F 1 "1k/zero" V 4800 2600 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 2900 50  0001 C CNN
F 3 "~" H 4750 2900 50  0001 C CNN
	1    4750 2900
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R20
U 1 1 60BCC05A
P 4200 4900
F 0 "R20" V 4200 4900 50  0000 C CNN
F 1 "100k/none" V 4100 4900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4130 4900 50  0001 C CNN
F 3 "~" H 4200 4900 50  0001 C CNN
	1    4200 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:R R16
U 1 1 60BFC6BF
P 4750 4400
F 0 "R16" V 4750 4400 50  0000 C CNN
F 1 "1k/zero" V 4800 4100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 4400 50  0001 C CNN
F 3 "~" H 4750 4400 50  0001 C CNN
	1    4750 4400
	0    -1   -1   0   
$EndComp
Text Label 5650 5950 1    50   ~ 0
SDA
Text Label 5750 5950 1    50   ~ 0
SCL
Text Label 5950 5950 1    50   ~ 0
GPIO13
Text Label 5850 5950 1    50   ~ 0
GPIO17
Text Label 5450 5950 1    50   ~ 0
GND
Text Label 1750 2250 0    50   ~ 0
J1.1
Text Label 1750 2350 0    50   ~ 0
J1.2
Text Label 1750 2450 0    50   ~ 0
J1.3
Text Label 1750 2650 0    50   ~ 0
J1.5
Text Label 1750 2750 0    50   ~ 0
J1.6
Text Label 1750 2850 0    50   ~ 0
J1.7
Text Label 1750 2950 0    50   ~ 0
J1.8
Text Label 9300 5000 2    50   ~ 0
SDA
Text Label 9300 4800 2    50   ~ 0
GND
Text Label 9300 5100 2    50   ~ 0
SCL
Text Label 9300 4900 2    50   ~ 0
+3V3
Wire Wire Line
	9300 5000 9350 5000
Wire Wire Line
	9300 5100 9350 5100
Wire Wire Line
	10250 4100 10250 3400
Wire Wire Line
	10250 3400 10500 3400
Wire Wire Line
	10500 3500 10400 3500
Wire Wire Line
	10400 3500 10400 3950
Text Label 1750 1750 0    50   ~ 0
J6.2
Text Label 1750 1650 0    50   ~ 0
J6.1
Wire Wire Line
	5850 3700 5850 3650
NoConn ~ 6250 3650
NoConn ~ 6150 3650
Wire Wire Line
	6250 3650 6250 3700
Wire Wire Line
	6150 3700 6150 3650
Wire Wire Line
	6050 3650 6050 3700
Wire Wire Line
	5950 3700 5950 3650
Wire Wire Line
	5750 3650 5750 3700
Text Label 6650 3650 1    50   ~ 0
A3
Text Label 6550 3650 1    50   ~ 0
A2
Text Label 6450 3650 1    50   ~ 0
A1
Text Label 6350 3650 1    50   ~ 0
A0
Text Label 6250 3650 1    50   ~ 0
ALRT
Text Label 6150 3650 1    50   ~ 0
ADDR
Text Label 5950 3650 1    50   ~ 0
SCL
Text Label 6050 3650 1    50   ~ 0
SDA
Text Label 5850 3650 1    50   ~ 0
GND
Text Label 1750 1850 0    50   ~ 0
J6.3
$Comp
L Device:R R15
U 1 1 61EDD6D4
P 4350 4900
F 0 "R15" V 4350 4900 50  0000 C CNN
F 1 "2k2/none" V 4450 4900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4280 4900 50  0001 C CNN
F 3 "~" H 4350 4900 50  0001 C CNN
	1    4350 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6450 3100 6450 3700
Wire Wire Line
	4600 4400 4350 4400
Connection ~ 4350 4400
Wire Wire Line
	4350 4400 4350 4750
$Comp
L Device:R R18
U 1 1 62165436
P 4750 4200
F 0 "R18" V 4750 4200 50  0000 C CNN
F 1 "1k/zero" V 4800 3900 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 4200 50  0001 C CNN
F 3 "~" H 4750 4200 50  0001 C CNN
	1    4750 4200
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4600 4200 4450 4200
$Comp
L Connector_Generic:Conn_01x03 J6
U 1 1 621EB638
P 1500 1750
F 0 "J6" H 1500 1950 50  0000 C CNN
F 1 "feedback" V 1600 1750 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Horizontal" H 1500 1750 50  0001 C CNN
F 3 "~" H 1500 1750 50  0001 C CNN
	1    1500 1750
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x21 J30
U 1 1 62216144
P 6450 6250
F 0 "J30" V 6550 7150 50  0000 C CNN
F 1 "Expansion1" V 6550 5550 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x21_P2.54mm_Horizontal" H 6450 6250 50  0001 C CNN
F 3 "~" H 6450 6250 50  0001 C CNN
	1    6450 6250
	0    -1   1    0   
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J7
U 1 1 60ED87A5
P 9550 5000
F 0 "J7" H 9500 5200 50  0000 L CNN
F 1 "I2C" V 9650 4900 50  0000 L CNN
F 2 "Connector_JST:JST_PH_B4B-PH-K_1x04_P2.00mm_Vertical" H 9550 5000 50  0001 C CNN
F 3 "~" H 9550 5000 50  0001 C CNN
	1    9550 5000
	1    0    0    1   
$EndComp
Text Label 1750 2550 0    50   ~ 0
J1.4
Text Label 6150 5950 1    50   ~ 0
GPIO12
Text Label 6250 5950 1    50   ~ 0
GPIO25
Text Label 6350 5950 1    50   ~ 0
GPIO26
Text Label 6450 5950 1    50   ~ 0
GPIO27
Text Label 5550 5950 1    50   ~ 0
+3V3
Text Label 6550 5950 1    50   ~ 0
GPIO33
$Comp
L Device:R R11
U 1 1 60BC4267
P 3200 4300
F 0 "R11" V 3200 4300 50  0000 C CNN
F 1 "68k/zero" V 3300 4300 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3130 4300 50  0001 C CNN
F 3 "~" H 3200 4300 50  0001 C CNN
	1    3200 4300
	0    1    1    0   
$EndComp
$Comp
L Device:R R12
U 1 1 60BCA1D4
P 3200 4500
F 0 "R12" V 3200 4500 50  0000 C CNN
F 1 "68k/zero" V 3300 4500 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 3130 4500 50  0001 C CNN
F 3 "~" H 3200 4500 50  0001 C CNN
	1    3200 4500
	0    1    1    0   
$EndComp
Wire Wire Line
	2550 2250 2550 3150
Wire Wire Line
	2550 3150 6350 3150
Wire Wire Line
	2600 2350 2600 3100
Wire Wire Line
	2600 3100 6450 3100
Wire Wire Line
	2650 2450 2650 3000
Wire Wire Line
	5950 1750 5950 2450
Wire Wire Line
	5850 1750 5850 2350
Wire Wire Line
	5750 1750 5750 2250
Wire Wire Line
	2750 2550 2750 2900
Wire Wire Line
	4600 2900 2750 2900
Wire Wire Line
	4900 2900 6650 2900
Wire Wire Line
	6650 2900 6650 3700
Wire Wire Line
	2750 2550 2850 2550
Wire Wire Line
	2650 2450 2850 2450
Wire Wire Line
	2600 2350 2850 2350
Wire Wire Line
	2550 2250 2850 2250
Wire Wire Line
	3250 2700 4350 2700
Wire Wire Line
	4350 2700 4350 4400
Wire Wire Line
	1850 2650 1850 4300
Wire Wire Line
	1850 4300 3050 4300
Wire Wire Line
	1700 2650 1850 2650
$Comp
L Connector_Generic:Conn_01x03 J61
U 1 1 61BF9BF7
P 2150 1750
F 0 "J61" H 2150 1550 50  0000 C CNN
F 1 "patch" V 2250 1700 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2150 1750 50  0001 C CNN
F 3 "~" H 2150 1750 50  0001 C CNN
	1    2150 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 1750 1950 1750
Wire Wire Line
	1700 1850 1950 1850
Wire Wire Line
	1700 2950 1950 2950
Wire Wire Line
	1700 2850 1950 2850
Wire Wire Line
	1700 2750 1950 2750
Wire Wire Line
	1700 2450 1950 2450
Wire Wire Line
	1700 2350 1950 2350
Wire Wire Line
	1700 2250 1950 2250
Text Label 5600 4200 2    50   ~ 0
FanPWM
Text Label 5650 4400 2    50   ~ 0
NotEnable
Wire Notes Line
	3350 3250 3350 1400
Wire Notes Line
	1950 1400 1950 3250
Wire Notes Line
	1950 3250 3350 3250
Wire Notes Line
	1950 1400 3350 1400
Text Notes 2250 1500 0    50   ~ 0
Wire patch field
$Comp
L Device:C C6
U 1 1 611F1165
P 8550 4950
F 0 "C6" H 8400 5050 50  0000 L CNN
F 1 "0.1µ" H 8350 4850 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8588 4800 50  0001 C CNN
F 3 "~" H 8550 4950 50  0001 C CNN
	1    8550 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 4900 9050 5100
Wire Wire Line
	9050 5100 8900 5100
Wire Wire Line
	9050 4900 9350 4900
Wire Wire Line
	8550 4800 8900 4800
$Comp
L Device:C C5
U 1 1 6123AE5C
P 8200 4950
F 0 "C5" H 8050 5050 50  0000 L CNN
F 1 "0.1µ" H 8000 4850 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8238 4800 50  0001 C CNN
F 3 "~" H 8200 4950 50  0001 C CNN
	1    8200 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 5100 8550 5100
Connection ~ 8550 5100
Wire Wire Line
	8200 4800 8550 4800
Connection ~ 8550 4800
$Comp
L Connector_Generic:Conn_01x02 J22
U 1 1 618B9DDF
P 3050 2800
F 0 "J22" H 2950 2850 50  0000 C CNN
F 1 "patch" V 3150 2750 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3050 2800 50  0001 C CNN
F 3 "~" H 3050 2800 50  0001 C CNN
	1    3050 2800
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J21
U 1 1 61296448
P 3050 2350
F 0 "J21" H 3100 2550 50  0000 C CNN
F 1 "patch" V 3100 2300 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 3050 2350 50  0001 C CNN
F 3 "~" H 3050 2350 50  0001 C CNN
	1    3050 2350
	1    0    0    -1  
$EndComp
Text Label 6050 5950 1    50   ~ 0
GPIO2
Wire Wire Line
	5450 5950 5450 6050
Wire Wire Line
	5550 5950 5550 6050
Wire Wire Line
	5650 5950 5650 6050
Wire Wire Line
	5750 5950 5750 6050
Wire Wire Line
	5850 5950 5850 6050
Wire Wire Line
	5950 5950 5950 6050
Wire Wire Line
	6050 5950 6050 6050
Wire Wire Line
	6150 5950 6150 6050
Wire Wire Line
	6250 5950 6250 6050
Wire Wire Line
	6350 5950 6350 6050
Wire Wire Line
	6450 5950 6450 6050
Wire Wire Line
	6550 5950 6550 6050
$Comp
L Device:R R13
U 1 1 61232F23
P 4750 3000
F 0 "R13" V 4750 3000 50  0000 C CNN
F 1 "1k/zero" V 4700 2700 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 3000 50  0001 C CNN
F 3 "~" H 4750 3000 50  0001 C CNN
	1    4750 3000
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4900 3000 6550 3000
Wire Wire Line
	4600 3000 2650 3000
Wire Wire Line
	6550 3000 6550 3700
Wire Wire Line
	1700 1650 1950 1650
Connection ~ 1950 1650
Wire Wire Line
	4200 1650 4200 4750
$Comp
L Device:R R14
U 1 1 611BB67B
P 4750 2550
F 0 "R14" V 4750 2550 50  0000 C CNN
F 1 "1k/zero" V 4700 2850 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 2550 50  0001 C CNN
F 3 "~" H 4750 2550 50  0001 C CNN
	1    4750 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 2550 6050 2550
Wire Wire Line
	6050 1750 6050 2550
Text Label 5750 3650 1    50   ~ 0
+3V3
Text Label 6750 5950 1    50   ~ 0
+3V3
Text Label 6650 5950 1    50   ~ 0
GND
Wire Wire Line
	6650 5950 6650 6050
Wire Wire Line
	6750 6050 6750 5950
Wire Wire Line
	1950 1650 4200 1650
Wire Wire Line
	4450 2800 4450 4200
Wire Wire Line
	3250 2800 4450 2800
Wire Wire Line
	1700 4500 3050 4500
Wire Wire Line
	3350 4300 6350 4300
Wire Wire Line
	6350 4300 6350 5100
Wire Wire Line
	3350 4500 6250 4500
Wire Wire Line
	6250 4500 6250 5100
$Comp
L power:GND #PWR0103
U 1 1 61330B64
P 4350 5050
F 0 "#PWR0103" H 4350 4800 50  0001 C CNN
F 1 "GND" H 4355 4877 50  0000 C CNN
F 2 "" H 4350 5050 50  0001 C CNN
F 3 "" H 4350 5050 50  0001 C CNN
	1    4350 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0105
U 1 1 613315EE
P 4200 5050
F 0 "#PWR0105" H 4200 4800 50  0001 C CNN
F 1 "GND" H 4205 4877 50  0000 C CNN
F 2 "" H 4200 5050 50  0001 C CNN
F 3 "" H 4200 5050 50  0001 C CNN
	1    4200 5050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0106
U 1 1 61332016
P 8600 3650
F 0 "#PWR0106" H 8600 3400 50  0001 C CNN
F 1 "GND" H 8605 3477 50  0000 C CNN
F 2 "" H 8600 3650 50  0001 C CNN
F 3 "" H 8600 3650 50  0001 C CNN
	1    8600 3650
	1    0    0    -1  
$EndComp
Connection ~ 8600 3650
Wire Wire Line
	4900 4200 6150 4200
Wire Wire Line
	6150 4200 6150 5100
Wire Wire Line
	4900 4400 6450 4400
Wire Wire Line
	6450 4400 6450 5100
Wire Wire Line
	6150 2700 6950 2700
Wire Wire Line
	6950 2700 6950 3950
Wire Wire Line
	6150 1750 6150 2700
NoConn ~ 6950 6050
NoConn ~ 7050 6050
NoConn ~ 7150 6050
NoConn ~ 7250 6050
NoConn ~ 7350 6050
Wire Wire Line
	6050 4650 7000 4650
Wire Wire Line
	7000 4650 7000 4100
Wire Wire Line
	6050 4650 6050 5100
Wire Wire Line
	6850 5950 6850 6050
Text Label 6850 5950 1    50   ~ 0
+5V
$Comp
L Connector_Generic:Conn_01x12 J4
U 1 1 6053C1C0
P 6250 1550
F 0 "J4" V 6350 2000 50  0000 C CNN
F 1 "ESP32-TFT" V 6350 1250 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical" H 6250 1550 50  0001 C CNN
F 3 "~" H 6250 1550 50  0001 C CNN
	1    6250 1550
	0    1    -1   0   
$EndComp
Text Label 6250 1800 3    50   ~ 0
GPIO33
Wire Wire Line
	6250 1750 6250 1800
Text Label 7450 5900 1    50   ~ 0
GND
Wire Wire Line
	7450 6050 7450 5900
Wire Wire Line
	9250 2700 9800 2700
Wire Wire Line
	9250 2700 9050 2700
Connection ~ 9250 2700
Wire Wire Line
	9900 3650 9900 3250
Wire Wire Line
	10250 2900 9700 2900
Wire Wire Line
	9700 2900 9700 3100
Connection ~ 10250 2900
Wire Wire Line
	10250 3100 10100 3100
Connection ~ 10250 3100
Wire Wire Line
	7000 4100 10250 4100
Wire Wire Line
	6950 3950 10400 3950
Text Notes 850  1900 0    59   ~ 0
Vin Probe\nIin Probe\nIout Probe
Text Notes 850  2950 0    59   ~ 0
Iout Sense\nVout Sense\nVin Sense\nIout Set\nVout Set\n! Enable \nCV/CC\nFan PWM
$Comp
L Connector_Generic:Conn_01x10 J10
U 1 1 60B80EFA
P 6150 3900
F 0 "J10" V 6250 4250 50  0000 C CNN
F 1 "ADS1115" V 6250 3650 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x10_P2.54mm_Vertical" H 6150 3900 50  0001 C CNN
F 3 "~" H 6150 3900 50  0001 C CNN
	1    6150 3900
	0    -1   1    0   
$EndComp
Wire Wire Line
	3350 2450 5950 2450
Wire Wire Line
	3350 2250 5750 2250
Wire Wire Line
	3350 2350 5850 2350
Wire Wire Line
	3350 2550 4600 2550
Wire Wire Line
	6350 3150 6350 3700
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 61402127
P 9800 2700
F 0 "#FLG0101" H 9800 2775 50  0001 C CNN
F 1 "PWR_FLAG" H 9800 2850 50  0000 C CNN
F 2 "" H 9800 2700 50  0001 C CNN
F 3 "~" H 9800 2700 50  0001 C CNN
	1    9800 2700
	1    0    0    -1  
$EndComp
Connection ~ 9800 2700
Wire Wire Line
	9800 2700 10150 2700
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 61403084
P 9900 3650
F 0 "#FLG0102" H 9900 3725 50  0001 C CNN
F 1 "PWR_FLAG" H 9900 3800 50  0000 C CNN
F 2 "" H 9900 3650 50  0001 C CNN
F 3 "~" H 9900 3650 50  0001 C CNN
	1    9900 3650
	-1   0    0    1   
$EndComp
Connection ~ 9900 3650
Wire Wire Line
	9250 3250 9250 2700
Wire Wire Line
	9050 3250 9050 2700
$Comp
L Device:C C8
U 1 1 60567DD7
P 9250 3400
F 0 "C8" H 9100 3500 50  0000 L CNN
F 1 "0.1µ" H 9300 3300 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9288 3250 50  0001 C CNN
F 3 "~" H 9250 3400 50  0001 C CNN
	1    9250 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C7
U 1 1 6056648B
P 9050 3400
F 0 "C7" H 8900 3550 50  0000 L CNN
F 1 "470µ" H 8950 3100 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P3.50mm" H 9088 3250 50  0001 C CNN
F 3 "~" H 9050 3400 50  0001 C CNN
	1    9050 3400
	1    0    0    -1  
$EndComp
Text Label 7850 3200 1    50   ~ 0
ADC0
Text Label 8150 3200 1    50   ~ 0
ADC1
Text Label 8450 3200 1    50   ~ 0
ADC2
Text Label 8750 3200 1    50   ~ 0
ADC3
Wire Wire Line
	8750 3200 8750 3250
Wire Wire Line
	8450 3200 8450 3250
Wire Wire Line
	8150 3200 8150 3250
Wire Wire Line
	7850 3200 7850 3250
$Comp
L Device:C C4
U 1 1 60A8A0CB
P 8750 3400
F 0 "C4" H 8600 3500 50  0000 L CNN
F 1 "0.1µ" H 8550 3300 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8788 3250 50  0001 C CNN
F 3 "~" H 8750 3400 50  0001 C CNN
	1    8750 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 60A8822B
P 8450 3400
F 0 "C3" H 8300 3500 50  0000 L CNN
F 1 "0.1µ" H 8250 3300 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8488 3250 50  0001 C CNN
F 3 "~" H 8450 3400 50  0001 C CNN
	1    8450 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 60A8638B
P 8150 3400
F 0 "C2" H 8000 3500 50  0000 L CNN
F 1 "0.1µ" H 7950 3300 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8188 3250 50  0001 C CNN
F 3 "~" H 8150 3400 50  0001 C CNN
	1    8150 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:C C1
U 1 1 60A8437B
P 7850 3400
F 0 "C1" H 7700 3500 50  0000 L CNN
F 1 "0.1µ" H 7650 3300 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 7888 3250 50  0001 C CNN
F 3 "~" H 7850 3400 50  0001 C CNN
	1    7850 3400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7850 3650 8150 3650
Wire Wire Line
	8600 3650 8750 3650
Wire Wire Line
	7850 3550 7850 3650
Wire Wire Line
	8150 3550 8150 3650
Connection ~ 8150 3650
Wire Wire Line
	8150 3650 8450 3650
Wire Wire Line
	8450 3550 8450 3650
Connection ~ 8450 3650
Wire Wire Line
	8450 3650 8600 3650
Wire Wire Line
	8750 3550 8750 3650
Connection ~ 8750 3650
Wire Wire Line
	8750 3650 9050 3650
Wire Wire Line
	9250 3550 9250 3650
Connection ~ 9250 3650
Wire Wire Line
	9250 3650 9900 3650
Wire Wire Line
	9050 3550 9050 3650
Connection ~ 9050 3650
Wire Wire Line
	9050 3650 9250 3650
$Comp
L Device:C C9
U 1 1 61490F5C
P 8900 4950
F 0 "C9" H 8750 5050 50  0000 L CNN
F 1 "0.1µ" H 8700 4850 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8938 4800 50  0001 C CNN
F 3 "~" H 8900 4950 50  0001 C CNN
	1    8900 4950
	1    0    0    -1  
$EndComp
Connection ~ 8900 4800
Wire Wire Line
	8900 4800 9350 4800
Connection ~ 8900 5100
Wire Wire Line
	8900 5100 8550 5100
$Comp
L Connector:TestPoint TP1
U 1 1 612A3044
P 7350 3650
F 0 "TP1" H 7350 3920 50  0000 C CNN
F 1 "TestPoint_GND" H 7350 3850 50  0000 C CNN
F 2 "Connector_Pin:Pin_D1.3mm_L11.0mm" H 7550 3650 50  0001 C CNN
F 3 "~" H 7550 3650 50  0001 C CNN
	1    7350 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 3650 7850 3650
Connection ~ 7850 3650
Wire Wire Line
	1700 2550 1700 4500
$Comp
L Connector_Generic:Conn_01x08 J3
U 1 1 612AAB8C
P 2150 2550
F 0 "J3" H 2150 2950 50  0000 C CNN
F 1 "Patch / Test points" V 2250 2500 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 2150 2550 50  0001 C CNN
F 3 "~" H 2150 2550 50  0001 C CNN
	1    2150 2550
	1    0    0    -1  
$EndComp
Wire Wire Line
	1950 2550 1700 2550
Connection ~ 1700 2550
Wire Wire Line
	1950 2650 1850 2650
Connection ~ 1850 2650
$EndSCHEMATC
