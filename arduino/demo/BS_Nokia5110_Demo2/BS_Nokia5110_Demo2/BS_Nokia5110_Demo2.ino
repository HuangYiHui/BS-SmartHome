

#include "Arduino.h"
void setup(){
	Serial.begin(19200);
	pinMode(A3, INPUT);
}


void loop() {
	
	while(true){
		Serial.println(analogRead(A3));
		delay(500);
	}
}