/*
 Name:		SmartHomeOut.ino
 Created:	2018/3/20 23:25:44
 Author:	ahui
*/

#include "SmartHomeSystem.h"

extern SmartHomeSystem curSystem;

void setup() {
	curSystem.init();
}

// the loop function runs over and over again until power down or reset
void loop() {
	curSystem.start();
}
