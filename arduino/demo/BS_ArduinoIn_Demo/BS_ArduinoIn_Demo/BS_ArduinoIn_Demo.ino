/*
 Name:		BS_ArduinoIn_Demo.ino
 Created:	2018/2/15 12:55:43
 Author:	ahui
*/

#include "Arduino.h"
#include "System.h"
#include "Test1.h"

System mySystem;

void setup() {

	mySystem.init();
}

void loop() {

	mySystem.start();
}
