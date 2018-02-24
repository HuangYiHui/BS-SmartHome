#ifndef _BS_FIRE_SENSOR_DEVICE_H_
#define _BS_FIRE_SENSOR_DEVICE_H_

#include "Arduino.h"
#include "SampleDevice.h"

class FireSensorDevice : public SampleDevice
{
public:
	FireSensorDevice(devicePin pin);
	void init();
	bool hasFire();

private:
	devicePin pin;
};

#endif