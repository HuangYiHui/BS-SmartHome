#include "SimpleSensorDevice.h"

SimpleSensorDevice::SimpleSensorDevice(unsigned int deviceID, devicePin pin, unsigned char readMode) : SensorDevice(deviceID)
{
	this->pin = pin;
	this->readMode = readMode;
}

void SimpleSensorDevice::start()
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