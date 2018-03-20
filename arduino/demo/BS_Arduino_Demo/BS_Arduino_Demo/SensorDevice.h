#ifndef _BS_SENSOR_DEVICE_H_
#define _BS_SENSOR_DEVICE_H_

#include "SampleDevice.h"

class SensorDevice : public SampleDevice
{
public:
	SensorDevice(unsigned int deviceID, unsigned int sensorValueIndex);
	virtual float getSensorValue() = 0;
	unsigned int getSensorValueIndex();
private:
	unsigned int sensorValueIndex;
};

#endif