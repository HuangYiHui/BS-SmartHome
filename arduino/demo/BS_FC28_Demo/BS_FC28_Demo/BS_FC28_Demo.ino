/*
 Name:		BS_FC28_Demo.ino
 Created:	2017/12/17 10:12:23
 Author:	ahui
*/

#define FC28A0_PIN A0

void setup() {
	pinMode(FC28A0_PIN, INPUT);
	Serial.begin(9600);
}

void loop() {

	Serial.println(analogRead(FC28A0_PIN)/10.23);
	delay(1500);
}
