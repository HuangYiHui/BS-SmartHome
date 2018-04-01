#ifndef _BS_SENSOR_DEVICE_H_
#define _BS_SENSOR_DEVICE_H_

#include "IDevice.h"

class SensorDevice : public SampleDevice
{
protected:
	unsigned char sensorID;

public:
	SensorDevice(unsigned char sensorID) : sensorID(sensorID) {}
	unsigned char getSensorID() {return sensorID;}
	virtual float getSensorValue() = 0;
};

#endif