//土壤湿度传感器

#ifndef _BS_FC28_DEVICE_H_
#define _BS_FC28_DEVICE_H_

#include "SampleDevice.h"
#include "Arduino.h"

class FC28Device : public SampleDevice
{
public:
	FC28Device(devicePin pin);
	void init();
	unsigned char getHumidity();

private:
	devicePin pin;
};

#endif