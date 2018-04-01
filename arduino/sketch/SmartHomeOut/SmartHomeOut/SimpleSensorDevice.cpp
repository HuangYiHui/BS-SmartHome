#include "SimpleSensorDevice.h"

SimpleSensorDevice::SimpleSensorDevice(unsigned char sensorID, unsigned char pin, unsigned char readMode) : SensorDevice(sensorID)
{
	this->pin = pin;
	this->readMode = readMode;
}

void SimpleSensorDevice::init()
{
	pinMode(pin, INPUT);
}
	
float SimpleSensorDevice::getSensorValue()
{
	if(readMode == SENSOR_READ_MODE_ANALOG)
		return analogRead(pin);
	else
		return digitalRead(pin);
}