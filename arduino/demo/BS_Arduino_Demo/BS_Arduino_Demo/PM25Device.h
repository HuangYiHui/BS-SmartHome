//土壤湿度传感器

#ifndef _BS_PM25_DEVICE_H_
#define _BS_PM25_DEVICE_H_

#include "SampleDevice.h"
#include "Arduino.h"

class PM25Device : public SampleDevice
{
public:
	PM25Device(devicePin ledPin, devicePin voPin);
	void init();
	float getDustDensity();

private:
	devicePin ledPin;
	devicePin voPin;
};

#endif