#include "SensorDevice.h"

SensorDevice::SensorDevice(unsigned int deviceID, unsigned int sensorValueIndex) : SampleDevice(deviceID)
{
	this->sensorValueIndex = sensorValueIndex;
	state = DEVICE_STATE_CLOSED;
}
	
unsigned int SensorDevice::getSensorValueIndex()
{
	return sensorValueIndex;
}