#include "FC28Device.h"

FC28Device::FC28Device(unsigned char deviceID, unsigned char pin) : SensorDevice(deviceID)
{
	this->pin = pin;
}

void FC28Device::start()
{
	pinMode(pin, INPUT);
}

float FC28Device::getSensorValue()
{
	float value = (1024 - analogRead(pin)) / 10.24;
	return value;
}