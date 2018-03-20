#ifndef _BS_SENSOR_DEVICE_H_
#define _BS_SENSOR_DEVICE_H_

#include "SampleDevice.h"

class SensorDevice : public SampleDevice
{
public:
	SensorDevice(unsigned int deviceID);
	virtual float getSensorValue() = 0;
};

#endif