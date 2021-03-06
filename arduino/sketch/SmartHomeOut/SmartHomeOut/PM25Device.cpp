#include "PM25Device.h"

PM25Device::PM25Device(unsigned char deviceID, unsigned char ledPin, unsigned char voPin) : SensorDevice(deviceID)
{
	this->ledPin = ledPin;
	this->voPin = voPin;
}

void PM25Device::start()
{
	pinMode(ledPin, OUTPUT);
	pinMode(voPin, INPUT);
}

float PM25Device::getSensorValue()
{
	digitalWrite(ledPin, LOW);
	delayMicroseconds(280);
	float voMeasured = analogRead(voPin);
	delayMicroseconds(40);
	digitalWrite(ledPin, HIGH);
	delayMicroseconds(9680);
	float calcVoltage = voMeasured*(5.0/1024);
	float dustDensity = 1000*(0.17*calcVoltage-0.1);	//��λΪug/m3
	if(dustDensity < 0){
		return 0;
	}
	else if(dustDensity > 760){
		return 760;
	}else{
		return dustDensity;
	}
}