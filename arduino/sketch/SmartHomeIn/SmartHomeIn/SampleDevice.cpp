#include "SampleDevice.h"

SampleDevice::SampleDevice(unsigned int deviceID) : deviceID(deviceID)
{
}


void SampleDevice::start()
{
}

void SampleDevice::stop()
{
}

unsigned int SampleDevice::getDeviceID()
{
	return this->deviceID;
}