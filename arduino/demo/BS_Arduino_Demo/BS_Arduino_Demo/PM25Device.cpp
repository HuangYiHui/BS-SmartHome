#include "PM25Device.h"

PM25Device::PM25Device(devicePin ledPin, devicePin voPin)
{
	this->ledPin = ledPin;
	this->voPin = voPin;
	state = DEVICE_STATE_CLOSED;
}

void PM25Device::init()
{
	pinMode(ledPin, OUTPUT);
	pinMode(voPin, INPUT);
	state = DEVICE_STATE_READY;
}

float PM25Device::getDustDensity()
{
	digitalWrite(ledPin, LOW);  
	delayMicroseconds(280);  
	float voMeasured = analogRead(voPin);  
	delayMicroseconds(40);  
	digitalWrite(ledPin, HIGH);  
	delayMicroseconds(9680);  
	float calcVoltage = voMeasured*(5.0/1024);  
	float dustDensity = 0.17*calcVoltage-0.1;
	return dustDensity;
}