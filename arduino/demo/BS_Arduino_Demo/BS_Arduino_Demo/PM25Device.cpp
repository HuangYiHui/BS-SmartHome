#include "PM25Device.h"

PM25Device::PM25Device(unsigned int deviceID, devicePin ledPin, devicePin voPin, unsigned int sensorValueIndex) : SensorDevice(deviceID, sensorValueIndex)
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

float PM25Device::getSensorValue()
{
	digitalWrite(ledPin, LOW);
	delayMicroseconds(280);
	float voMeasured = analogRead(voPin);
	delayMicroseconds(40);
	digitalWrite(ledPin, HIGH);
	delayMicroseconds(9680);
	float calcVoltage = voMeasured*(5.0/1024);
	float dustDensity = 1000*(0.17*calcVoltage-0.1);	//µ¥Î»Îªug/m3
	Serial.print("dustDensity");
	Serial.println(dustDensity);
	if(dustDensity < 0){
		return 0;
	}
	else if(dustDensity > 760){
		return 760;
	}else{
		return dustDensity;
	}
}