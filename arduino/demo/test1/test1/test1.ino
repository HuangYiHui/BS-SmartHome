/*
 Name:		test1.ino
 Created:	2018/2/17 21:11:30
 Author:	ahui
*/

// the setup function runs once when you press reset or power the board
void setup() {
	pinMode(13, OUTPUT);
	delay(2000);
	Serial.begin(19200);
}

// the loop function runs over and over again until power down or reset
void loop() {
  
	int i=1;
	int j=0;
	int k = i/j;
	Serial.println(k);
	while(true){
		digitalWrite(13, HIGH);
		delay(200);
		digitalWrite(13, LOW);
		delay(200);
	}
}
