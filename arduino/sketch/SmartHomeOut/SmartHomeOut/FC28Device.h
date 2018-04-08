#ifndef _BS_FC28_DEVICE_H_
#define _BS_FC28_DEVICE_H_

#include "SensorDevice.h"
#include "Arduino.h"

class FC28Device : public SensorDevice
{
public:
	FC28Device(unsigned char sensorID, unsigned char pin);
	void start();
	float getSensorValue();
private:
	unsigned char pin;
};

#endif