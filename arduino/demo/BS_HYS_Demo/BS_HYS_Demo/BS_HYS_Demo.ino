/*
 Name:		BS_HYS_Demo.ino
 Created:	2018/2/13 16:56:30
 Author:	ahui
*/

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(A2, INPUT);
	Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	Serial.println(digitalRead(A2));
	delay(800);
}
