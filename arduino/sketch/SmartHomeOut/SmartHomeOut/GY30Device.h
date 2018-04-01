#ifndef _BS_GY30_DEVICE_H_
#define _BS_GY30_DEVICE_H_

#include "SensorDevice.h"
#include "Arduino.h"
#include "Wire.h"
#include "BH1750xtra.h"

class GY30Device : public SensorDevice
{
public:
	GY30Device(unsigned char sensorID);
	void start();
	float getSensorValue();

private:
	BH1750xtra bhSensor;
};

#endif