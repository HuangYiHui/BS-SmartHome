/*
 Name:		test1.ino
 Created:	2018/2/17 21:11:30
 Author:	ahui
*/

#include "Tool.h"

void setup() {
	Serial.begin(19200);
}

void loop() {
	
	unsigned int n1 = 6000;
	unsigned char bs[2];
	Tool::intTo2Bytes(n1, bs);
	Serial.println(bs[0], HEX);
	Serial.println(bs[1], HEX);

	unsigned char bs1[2];
	bs1[0] = bs[0];
	bs1[1] = bs[1];
	unsigned int n2 = Tool::bytesToInt(bs1);
	Serial.println(n2);

	while(true);
}

