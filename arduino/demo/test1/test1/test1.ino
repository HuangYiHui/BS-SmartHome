/*
 Name:		test1.ino
 Created:	2018/2/17 21:11:30
 Author:	ahui
*/

unsigned long cTime;
// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(19200);
	cTime = millis();
}

// the loop function runs oer and over again until power down or reset
void loop() {
	if(millis()-cTime>2500){
		Serial.println();
		Serial.println("arduino run");
		Serial.println();
		cTime = millis();
	}
	if(Serial.available()>0)
		Serial.print(Serial.read());
}
