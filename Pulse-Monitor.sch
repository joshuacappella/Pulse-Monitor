EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Notes 8150 7650 0    50   ~ 0
11/30/2023
Text Notes 10600 7650 0    50   ~ 0
1.0
Text Notes 7350 7500 0    79   ~ 16
Pulse Monitor Wiring Diagram
Text Notes 7000 7100 0    50   ~ 0
Author: Joshua Cappella\nDesigned For: Cedarville Microcontrollers EGCP-2120
$Comp
L Device:Battery_Cell BT?
U 1 1 65566E9D
P 4550 3400
F 0 "BT?" V 4295 3450 50  0001 C CNN
F 1 "2x3.7_Battery_Cells" V 4713 3450 50  0000 C CNN
F 2 "" V 4550 3460 50  0001 C CNN
F 3 "~" V 4550 3460 50  0001 C CNN
	1    4550 3400
	0    -1   -1   0   
$EndComp
$Comp
L Sensor:MAX30100 IC?
U 1 1 655686DB
P 7350 4150
F 0 "IC?" H 7880 4196 50  0001 L CNN
F 1 "MAX30100" H 7250 4150 50  0000 L CNN
F 2 "OptoDevice:Maxim_OLGA-14_3.3x5.6mm_P0.8mm" H 7200 5050 50  0001 C CNN
F 3 "https://datasheets.maximintegrated.com/en/ds/MAX30102.pdf" H 7000 4400 50  0001 C CNN
	1    7350 4150
	1    0    0    -1  
$EndComp
$Comp
L MCU_Module:Arduino_Nano A?
U 1 1 65570915
P 4800 4000
F 0 "A?" H 5980 3896 50  0001 L CNN
F 1 "Arduino_Nano" H 4850 3850 50  0000 L CNN
F 2 "Module:Arduino_Nano" V 5050 3850 50  0001 C CIN
F 3 "https://www.arduino.cc/en/uploads/Main/ArduinoNanoManual23.pdf" V 5050 3850 50  0001 C CNN
	1    4800 4000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 3650 5150 3550
Wire Wire Line
	5150 3550 6050 3550
Wire Wire Line
	6050 3550 6050 4350
Wire Wire Line
	6050 4350 6750 4350
Wire Wire Line
	6750 4200 6200 4200
Wire Wire Line
	6200 3400 5050 3400
Wire Wire Line
	5050 3400 5050 3650
Wire Wire Line
	6200 3400 6200 4200
Wire Wire Line
	5750 3650 5750 3600
Wire Wire Line
	5750 3600 6650 3600
Wire Wire Line
	6650 3600 6650 3900
Wire Wire Line
	6650 3900 6750 3900
Wire Wire Line
	4750 4800 6300 4800
Wire Wire Line
	6300 4800 6300 4050
Wire Wire Line
	6300 4050 6750 4050
Text GLabel 6700 4500 0    50   Input ~ 0
Interrupt
Wire Wire Line
	6750 4500 6700 4500
Wire Wire Line
	4350 3400 4350 3550
Wire Wire Line
	4350 3550 4450 3550
Wire Wire Line
	4450 3550 4450 3650
Wire Wire Line
	4650 3400 4650 3550
Wire Wire Line
	4650 3550 4550 3550
Wire Wire Line
	4550 3550 4550 3650
Wire Wire Line
	6750 5000 4750 5000
Wire Wire Line
	4750 4650 4750 4800
Connection ~ 4750 4800
Wire Wire Line
	4750 4800 4750 5000
$Comp
L Device:Speaker LS?
U 1 1 6556677C
P 6950 4900
F 0 "LS?" H 7120 4896 50  0001 L CNN
F 1 "Speaker" H 6913 4575 50  0000 C CNN
F 2 "" H 6950 4700 50  0001 C CNN
F 3 "~" H 6940 4850 50  0001 C CNN
	1    6950 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 4900 5450 4900
Wire Wire Line
	5450 4900 5450 4650
$EndSCHEMATC
