#include "SensorDevice.h"

SensorDevice::SensorDevice(unsigned int sensorValueIndex)
{
	this->sensorValueIndex = sensorValueIndex;
	state = DEVICE_STATE_CLOSED;
}
	
unsigned int SensorDevice::getSensorValueIndex()
{
	return sensorValueIndex;
}