
#ifndef _BS_TOUCH_SENSOR_DEVICE_H_
#define _BS_TOUCH_SENSOR_DEVICE_H_

#include "Arduino.h"
#include "SampleDevice.h"

class TouchSensorDevice : public SampleDevice
{
public:
	TouchSensorDevice(devicePin pin);
	void init();
	bool isTouching();
	//void bell(unsigned int frequency, unsigned long duration = 0);
	//void unBell();

private:
	devicePin pin;
};

#endif