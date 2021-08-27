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
P 1500 3000
F 0 "J1" H 1500 3400 50  0000 C CNN
F 1 "To PSU host board" V 1600 2950 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 1500 3000 50  0001 C CNN
F 3 "~" H 1500 3000 50  0001 C CNN
	1    1500 3000
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x08 J2
U 1 1 60534CC7
P 10150 3100
F 0 "J2" H 10100 3500 50  0000 L CNN
F 1 "To PSU host board" V 10250 2700 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x08_P2.54mm_Vertical" H 10150 3100 50  0001 C CNN
F 3 "~" H 10150 3100 50  0001 C CNN
	1    10150 3100
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0102
U 1 1 6054F23A
P 9600 2700
F 0 "#PWR0102" H 9600 2550 50  0001 C CNN
F 1 "VCC" H 9615 2873 50  0000 C CNN
F 2 "" H 9600 2700 50  0001 C CNN
F 3 "" H 9600 2700 50  0001 C CNN
	1    9600 2700
	1    0    0    -1  
$EndComp
Text Notes 7400 6350 0    50   ~ 0
VCC = +5Vdc\nSignal labels based on B3603/BST900.
Text Label 9900 3200 2    50   ~ 0
VCC
Text Label 9900 2800 2    50   ~ 0
GNDA
Text Label 9900 3500 2    50   ~ 0
RX
Text Label 9900 3400 2    50   ~ 0
TX
Text Label 6750 2700 3    50   ~ 0
+5V
Text Label 6650 2700 3    50   ~ 0
GND
Text Label 6150 4700 1    50   ~ 0
GPIO2
Text Label 6150 2700 3    50   ~ 0
GPIO32
Text Label 6350 4700 1    50   ~ 0
GPIO13
Text Label 6250 4700 1    50   ~ 0
GPIO15
Text Label 6550 4700 1    50   ~ 0
GND
Text Label 6650 4700 1    50   ~ 0
GND
Text Label 6750 4700 1    50   ~ 0
+3V3
Text Label 5650 2700 3    50   ~ 0
+3V3
Text Label 5650 4700 1    50   ~ 0
GND
Text Label 5750 4700 1    50   ~ 0
GND
Wire Wire Line
	5650 4750 5650 4700
Wire Wire Line
	5750 4700 5750 4750
Wire Wire Line
	6550 4750 6550 4700
Wire Wire Line
	6650 4750 6650 4700
Wire Wire Line
	6750 4750 6750 4700
Wire Wire Line
	5650 2650 5650 2700
Wire Wire Line
	6650 2650 6650 2700
Wire Wire Line
	6750 2650 6750 2700
Wire Wire Line
	9700 2800 9950 2800
Wire Wire Line
	9600 3200 9600 2700
Wire Wire Line
	9600 3200 9900 3200
$Comp
L Device:CP C7
U 1 1 6056648B
P 8850 3500
F 0 "C7" H 8750 3400 50  0000 L CNN
F 1 "470µ" H 8750 3300 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D8.0mm_P3.50mm" H 8888 3350 50  0001 C CNN
F 3 "~" H 8850 3500 50  0001 C CNN
	1    8850 3500
	1    0    0    -1  
$EndComp
Connection ~ 9600 2700
Text Label 8800 3650 2    50   ~ 0
GND
Text Label 9900 3000 2    50   ~ 0
GNDD
Wire Wire Line
	9700 3000 9950 3000
Wire Wire Line
	9950 3100 9700 3100
Wire Wire Line
	9700 3100 9700 3000
$Comp
L Jumper:SolderJumper_3_Open JP1
U 1 1 60544F66
P 9350 3100
F 0 "JP1" V 9250 2950 50  0000 L CNN
F 1 "GND/D" H 9250 3200 50  0000 L CNN
F 2 "Jumper:SolderJumper-3_P1.3mm_Open_RoundedPad1.0x1.5mm" H 9350 3100 50  0001 C CNN
F 3 "~" H 9350 3100 50  0001 C CNN
	1    9350 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	9550 3200 9500 3200
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
	9700 2800 9700 2900
Wire Wire Line
	9950 2900 9700 2900
Text Label 6450 4700 1    50   ~ 0
GPIO12
Text Label 6550 2700 3    50   ~ 0
GPIO27
Wire Wire Line
	5750 4700 5650 4700
Wire Wire Line
	6650 4700 6550 4700
Text Label 5850 4700 1    50   ~ 0
SDA
Text Label 5950 4700 1    50   ~ 0
SCL
Text Label 6050 4700 1    50   ~ 0
GPIO17
Text Label 6450 2700 3    50   ~ 0
GPIO26
Text Label 6350 2700 3    50   ~ 0
GPIO25
Text Label 6050 2700 3    50   ~ 0
ADC3
Wire Wire Line
	6450 2650 6450 2700
Wire Wire Line
	6350 2650 6350 2700
Text Label 5950 2700 3    50   ~ 0
ADC2
Text Label 5850 2700 3    50   ~ 0
ADC1
Text Label 5750 2700 3    50   ~ 0
ADC0
$Comp
L Device:C C8
U 1 1 60567DD7
P 9050 3500
F 0 "C8" H 8900 3600 50  0000 L CNN
F 1 "0.1µ" H 8900 3750 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 9088 3350 50  0001 C CNN
F 3 "~" H 9050 3500 50  0001 C CNN
	1    9050 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	9950 3300 9900 3300
Wire Wire Line
	9900 3300 9900 3200
Connection ~ 9900 3200
Wire Wire Line
	9900 3200 9950 3200
Text Label 9050 2700 2    50   ~ 0
+5V
$Comp
L Connector_Generic:Conn_01x12 J5
U 1 1 60540801
P 6250 4950
F 0 "J5" V 6350 5400 50  0000 C CNN
F 1 "ESP32-TFT" V 6350 4650 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical" H 6250 4950 50  0001 C CNN
F 3 "~" H 6250 4950 50  0001 C CNN
	1    6250 4950
	0    1    1    0   
$EndComp
Wire Wire Line
	6550 2650 6550 2700
Wire Wire Line
	5850 4700 5850 4750
Wire Wire Line
	5950 4700 5950 4750
$Comp
L Device:R R17
U 1 1 60BC63B7
P 4750 3350
F 0 "R17" V 4750 3350 50  0000 C CNN
F 1 "1k/zero" V 4800 3100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 3350 50  0001 C CNN
F 3 "~" H 4750 3350 50  0001 C CNN
	1    4750 3350
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
F 1 "1k/zero" V 4650 4400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 4400 50  0001 C CNN
F 3 "~" H 4750 4400 50  0001 C CNN
	1    4750 4400
	0    -1   -1   0   
$EndComp
$Comp
L Device:C C1
U 1 1 60A8437B
P 7650 3500
F 0 "C1" H 7500 3600 50  0000 L CNN
F 1 "0.1µ" H 7450 3400 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 7688 3350 50  0001 C CNN
F 3 "~" H 7650 3500 50  0001 C CNN
	1    7650 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 60A8638B
P 7950 3500
F 0 "C2" H 7800 3600 50  0000 L CNN
F 1 "0.1µ" H 7750 3400 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 7988 3350 50  0001 C CNN
F 3 "~" H 7950 3500 50  0001 C CNN
	1    7950 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C3
U 1 1 60A8822B
P 8250 3500
F 0 "C3" H 8100 3600 50  0000 L CNN
F 1 "0.1µ" H 8050 3400 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8288 3350 50  0001 C CNN
F 3 "~" H 8250 3500 50  0001 C CNN
	1    8250 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 60A8A0CB
P 8550 3500
F 0 "C4" H 8400 3600 50  0000 L CNN
F 1 "0.1µ" H 8350 3400 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8588 3350 50  0001 C CNN
F 3 "~" H 8550 3500 50  0001 C CNN
	1    8550 3500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7650 3300 7650 3350
Wire Wire Line
	7950 3300 7950 3350
Wire Wire Line
	8250 3300 8250 3350
Wire Wire Line
	8550 3300 8550 3350
Wire Wire Line
	7650 3650 7950 3650
Wire Wire Line
	8250 3650 8400 3650
Wire Wire Line
	7950 3650 8250 3650
Connection ~ 7950 3650
Connection ~ 8250 3650
Wire Wire Line
	8550 3650 8850 3650
Connection ~ 8550 3650
Text Label 5650 5600 1    50   ~ 0
SDA
Text Label 5750 5600 1    50   ~ 0
SCL
Text Label 5950 5600 1    50   ~ 0
GPIO13
Text Label 5850 5600 1    50   ~ 0
GPIO17
Text Label 5450 5600 1    50   ~ 0
GND
Text Label 1750 2700 0    50   ~ 0
J1.1
Text Label 1750 2800 0    50   ~ 0
J1.2
Text Label 1750 2900 0    50   ~ 0
J1.3
Text Label 1750 3100 0    50   ~ 0
J1.5
Text Label 1750 3200 0    50   ~ 0
J1.6
Text Label 1750 3300 0    50   ~ 0
J1.7
Text Label 1750 3400 0    50   ~ 0
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
	9850 3900 9850 3400
Wire Wire Line
	9850 3400 9950 3400
Wire Wire Line
	9950 3500 9900 3500
Wire Wire Line
	9900 3500 9900 3950
Wire Notes Line
	7200 3900 7500 3900
Text Label 1750 2200 0    50   ~ 0
J6.2
Text Label 1750 2100 0    50   ~ 0
J6.1
Wire Wire Line
	6350 3600 6350 3850
Wire Wire Line
	5850 3850 5850 3800
NoConn ~ 6250 3800
NoConn ~ 6150 3800
Wire Wire Line
	6250 3800 6250 3850
Wire Wire Line
	6150 3850 6150 3800
Wire Wire Line
	6050 3800 6050 3850
Wire Wire Line
	5950 3850 5950 3800
Wire Wire Line
	5750 3800 5750 3850
Text Label 6650 3800 1    50   ~ 0
A3
Text Label 6550 3800 1    50   ~ 0
A2
Text Label 6450 3800 1    50   ~ 0
A1
Text Label 6350 3800 1    50   ~ 0
A0
Text Label 6250 3800 1    50   ~ 0
ALRT
Text Label 6150 3800 1    50   ~ 0
ADDR
Text Label 5950 3800 1    50   ~ 0
SCL
Text Label 6050 3800 1    50   ~ 0
SDA
Text Label 5850 3800 1    50   ~ 0
GND
Text Label 1750 2300 0    50   ~ 0
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
	6450 3550 6450 3850
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
F 1 "1k/zero" V 4850 4200 50  0000 C CNN
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
P 1500 2200
F 0 "J6" H 1500 2400 50  0000 C CNN
F 1 "feedback" V 1600 2200 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Horizontal" H 1500 2200 50  0001 C CNN
F 3 "~" H 1500 2200 50  0001 C CNN
	1    1500 2200
	-1   0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x21 J30
U 1 1 62216144
P 6450 5900
F 0 "J30" V 6550 6800 50  0000 C CNN
F 1 "Expansion1" V 6550 5200 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x21_P2.54mm_Horizontal" H 6450 5900 50  0001 C CNN
F 3 "~" H 6450 5900 50  0001 C CNN
	1    6450 5900
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
Text Label 1750 3000 0    50   ~ 0
J1.4
Text Label 6150 5600 1    50   ~ 0
GPIO12
Text Label 6250 5600 1    50   ~ 0
GPIO25
Text Label 6350 5600 1    50   ~ 0
GPIO26
Text Label 6450 5600 1    50   ~ 0
GPIO27
Text Label 5550 5600 1    50   ~ 0
+3V3
Text Label 6550 5600 1    50   ~ 0
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
	2550 2700 2550 3600
Wire Wire Line
	2550 3600 6350 3600
Wire Wire Line
	2600 2800 2600 3550
Wire Wire Line
	2600 3550 6450 3550
Wire Wire Line
	2650 2900 2650 3450
Wire Wire Line
	5950 2650 5950 3050
Wire Wire Line
	5850 2650 5850 3000
Wire Wire Line
	5750 2650 5750 2950
Text Label 8550 3300 1    50   ~ 0
ADC3
Text Label 8250 3300 1    50   ~ 0
ADC2
Text Label 7950 3300 1    50   ~ 0
ADC1
Text Label 7650 3300 1    50   ~ 0
ADC0
Wire Wire Line
	2750 3000 2750 3350
Wire Wire Line
	4600 3350 2750 3350
Wire Wire Line
	4900 3350 6650 3350
Wire Wire Line
	6650 3350 6650 3850
Wire Wire Line
	3600 2700 3600 2950
Wire Wire Line
	3550 2800 3550 3000
Wire Wire Line
	3550 3000 5850 3000
Wire Wire Line
	3500 2900 3500 3050
Wire Wire Line
	3500 3050 5950 3050
Wire Wire Line
	2750 3000 2850 3000
Wire Wire Line
	2650 2900 2850 2900
Wire Wire Line
	2600 2800 2850 2800
Wire Wire Line
	2550 2700 2850 2700
Wire Wire Line
	3350 3000 3450 3000
Wire Wire Line
	3350 2900 3500 2900
Wire Wire Line
	3350 2800 3550 2800
Wire Wire Line
	3350 2700 3600 2700
Wire Wire Line
	3250 3150 4350 3150
Wire Wire Line
	4350 3150 4350 4400
$Comp
L Connector_Generic:Conn_01x03 J11
U 1 1 61BB2313
P 2150 2800
F 0 "J11" H 2150 3000 50  0000 C CNN
F 1 "patch" V 2250 2800 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2150 2800 50  0001 C CNN
F 3 "~" H 2150 2800 50  0001 C CNN
	1    2150 2800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2500 3100 2500 4300
Wire Wire Line
	2500 4300 3050 4300
Wire Wire Line
	1700 3100 2500 3100
Wire Wire Line
	1700 3000 2450 3000
$Comp
L Connector_Generic:Conn_01x03 J61
U 1 1 61BF9BF7
P 2150 2200
F 0 "J61" H 2150 2000 50  0000 C CNN
F 1 "patch" V 2250 2150 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2150 2200 50  0001 C CNN
F 3 "~" H 2150 2200 50  0001 C CNN
	1    2150 2200
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J12
U 1 1 61C0CDF3
P 2150 3300
F 0 "J12" H 2150 3100 50  0000 C CNN
F 1 "patch" V 2250 3300 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 2150 3300 50  0001 C CNN
F 3 "~" H 2150 3300 50  0001 C CNN
	1    2150 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1700 2200 1950 2200
Wire Wire Line
	1700 2300 1950 2300
Wire Wire Line
	1700 3400 1950 3400
Wire Wire Line
	1700 3300 1950 3300
Wire Wire Line
	1700 3200 1950 3200
Wire Wire Line
	1700 2900 1950 2900
Wire Wire Line
	1700 2800 1950 2800
Wire Wire Line
	1700 2700 1950 2700
Text Label 5400 4200 2    50   ~ 0
FanPWM
Text Label 5400 4400 2    50   ~ 0
NotEnable
Wire Notes Line
	3350 3700 3350 1850
Wire Notes Line
	1950 1850 1950 3700
Wire Notes Line
	1950 3700 3350 3700
Wire Notes Line
	1950 1850 3350 1850
Text Notes 2250 1950 0    50   ~ 0
Wire patch field
$Comp
L Device:C C6
U 1 1 611F1165
P 8900 4950
F 0 "C6" H 8750 5050 50  0000 L CNN
F 1 "0.1µ" H 8700 4850 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8938 4800 50  0001 C CNN
F 3 "~" H 8900 4950 50  0001 C CNN
	1    8900 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	9050 4900 9050 5100
Wire Wire Line
	9050 5100 8900 5100
Wire Wire Line
	9050 4900 9350 4900
Wire Wire Line
	8900 4800 9350 4800
$Comp
L Device:C C5
U 1 1 6123AE5C
P 8650 4950
F 0 "C5" H 8500 5050 50  0000 L CNN
F 1 "0.1µ" H 8450 4850 50  0000 L CNN
F 2 "Capacitor_THT:C_Disc_D3.0mm_W1.6mm_P2.50mm" H 8688 4800 50  0001 C CNN
F 3 "~" H 8650 4950 50  0001 C CNN
	1    8650 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 5100 8900 5100
Connection ~ 8900 5100
Wire Wire Line
	8650 4800 8900 4800
Connection ~ 8900 4800
$Comp
L Connector_Generic:Conn_01x02 J22
U 1 1 618B9DDF
P 3050 3250
F 0 "J22" H 2950 3300 50  0000 C CNN
F 1 "patch" V 3150 3200 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3050 3250 50  0001 C CNN
F 3 "~" H 3050 3250 50  0001 C CNN
	1    3050 3250
	-1   0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_02x04_Odd_Even J21
U 1 1 61296448
P 3050 2800
F 0 "J21" H 3100 3000 50  0000 C CNN
F 1 "patch" V 3100 2750 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x04_P2.54mm_Vertical" H 3050 2800 50  0001 C CNN
F 3 "~" H 3050 2800 50  0001 C CNN
	1    3050 2800
	1    0    0    -1  
$EndComp
Text Label 6050 5600 1    50   ~ 0
GPIO2
Wire Wire Line
	5450 5600 5450 5700
Wire Wire Line
	5550 5600 5550 5700
Wire Wire Line
	5650 5600 5650 5700
Wire Wire Line
	5750 5600 5750 5700
Wire Wire Line
	5850 5600 5850 5700
Wire Wire Line
	5950 5600 5950 5700
Wire Wire Line
	6050 5600 6050 5700
Wire Wire Line
	6150 5600 6150 5700
Wire Wire Line
	6250 5600 6250 5700
Wire Wire Line
	6350 5600 6350 5700
Wire Wire Line
	6450 5600 6450 5700
Wire Wire Line
	6550 5600 6550 5700
$Comp
L Device:R R13
U 1 1 61232F23
P 4750 3450
F 0 "R13" V 4750 3450 50  0000 C CNN
F 1 "1k/zero" V 4700 3200 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 3450 50  0001 C CNN
F 3 "~" H 4750 3450 50  0001 C CNN
	1    4750 3450
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4900 3450 6550 3450
Wire Wire Line
	4600 3450 2650 3450
Wire Wire Line
	6550 3450 6550 3850
Wire Wire Line
	1700 2100 1950 2100
Connection ~ 1950 2100
Wire Wire Line
	3600 2950 5750 2950
Wire Wire Line
	4200 2100 4200 4750
$Comp
L Device:R R14
U 1 1 611BB67B
P 4750 3150
F 0 "R14" V 4750 3150 50  0000 C CNN
F 1 "1k/zero" V 4700 3400 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0204_L3.6mm_D1.6mm_P7.62mm_Horizontal" V 4680 3150 50  0001 C CNN
F 3 "~" H 4750 3150 50  0001 C CNN
	1    4750 3150
	0    1    1    0   
$EndComp
Wire Wire Line
	4900 3150 6050 3150
Wire Wire Line
	3450 3000 3450 3100
Wire Wire Line
	6050 2650 6050 3150
Text Label 5750 3800 1    50   ~ 0
+3V3
Text Label 6750 5600 1    50   ~ 0
+3V3
Text Label 6650 5600 1    50   ~ 0
GND
Wire Wire Line
	6650 5600 6650 5700
Wire Wire Line
	6750 5700 6750 5600
Wire Wire Line
	1950 2100 4200 2100
Wire Wire Line
	4450 3250 4450 4200
Wire Wire Line
	3250 3250 4450 3250
Wire Wire Line
	4450 3100 4450 3150
Wire Wire Line
	4450 3150 4600 3150
Wire Wire Line
	3450 3100 4450 3100
Wire Wire Line
	2450 3000 2450 4500
Wire Wire Line
	2450 4500 3050 4500
Wire Wire Line
	3350 4300 6350 4300
Wire Wire Line
	6350 4300 6350 4750
Wire Wire Line
	3350 4500 6250 4500
Wire Wire Line
	6250 4500 6250 4750
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
P 8400 3650
F 0 "#PWR0106" H 8400 3400 50  0001 C CNN
F 1 "GND" H 8405 3477 50  0000 C CNN
F 2 "" H 8400 3650 50  0001 C CNN
F 3 "" H 8400 3650 50  0001 C CNN
	1    8400 3650
	1    0    0    -1  
$EndComp
Connection ~ 8400 3650
Wire Wire Line
	8400 3650 8550 3650
Wire Wire Line
	4900 4200 6150 4200
Wire Wire Line
	6150 4200 6150 4750
Wire Wire Line
	4900 4400 6450 4400
Wire Wire Line
	6450 4400 6450 4750
Wire Wire Line
	6150 3150 6950 3150
Wire Wire Line
	6950 3150 6950 3950
Wire Wire Line
	6150 2650 6150 3150
Connection ~ 8850 3650
Connection ~ 9050 3650
Wire Wire Line
	8850 3650 9050 3650
Wire Wire Line
	8850 3350 8850 2700
Wire Wire Line
	9050 3350 9050 2700
NoConn ~ 6950 5700
NoConn ~ 7050 5700
NoConn ~ 7150 5700
NoConn ~ 7250 5700
NoConn ~ 7350 5700
Wire Wire Line
	6050 4600 7000 4600
Wire Wire Line
	7000 4600 7000 3900
Wire Wire Line
	6050 4600 6050 4750
Wire Wire Line
	6850 5600 6850 5700
Text Label 6850 5600 1    50   ~ 0
+5V
$Comp
L Connector_Generic:Conn_01x12 J4
U 1 1 6053C1C0
P 6250 2450
F 0 "J4" V 6350 2900 50  0000 C CNN
F 1 "ESP32-TFT" V 6350 2150 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x12_P2.54mm_Vertical" H 6250 2450 50  0001 C CNN
F 3 "~" H 6250 2450 50  0001 C CNN
	1    6250 2450
	0    1    -1   0   
$EndComp
Text Label 6250 2700 3    50   ~ 0
GPIO33
Wire Wire Line
	6250 2650 6250 2700
Text Label 7450 5550 1    50   ~ 0
GND
Wire Wire Line
	7450 5700 7450 5550
Wire Wire Line
	9050 2700 9600 2700
Wire Wire Line
	9050 2700 8850 2700
Connection ~ 9050 2700
Wire Wire Line
	9350 3650 9350 3250
Wire Wire Line
	9050 3650 9350 3650
Wire Wire Line
	9700 2900 9150 2900
Wire Wire Line
	9150 2900 9150 3100
Connection ~ 9700 2900
Wire Wire Line
	9700 3100 9550 3100
Connection ~ 9700 3100
Wire Wire Line
	7000 3900 9850 3900
Wire Wire Line
	6950 3950 9900 3950
Text Notes 850  2350 0    59   ~ 0
Vin Probe\nIin Probe\nIout Probe
Text Notes 850  3400 0    59   ~ 0
Iout Sense\nVout Sense\nVin Sense\nIout Set\nVout Set\n! Enable \nCV/CC\nFan PWM
$Comp
L Connector_Generic:Conn_01x10 J10
U 1 1 60B80EFA
P 6150 4050
F 0 "J10" V 6250 4400 50  0000 C CNN
F 1 "ADS1115" V 6250 3800 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x10_P2.54mm_Vertical" H 6150 4050 50  0001 C CNN
F 3 "~" H 6150 4050 50  0001 C CNN
	1    6150 4050
	0    -1   1    0   
$EndComp
$EndSCHEMATC
