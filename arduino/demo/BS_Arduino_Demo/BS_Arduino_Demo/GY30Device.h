//土壤湿度传感器

#ifndef _BS_GY30_DEVICE_H_
#define _BS_GY30_DEVICE_H_

#include "SampleDevice.h"
#include "Arduino.h"
#include "Wire.h"
#include "BH1750xtra.h"

class GY30Device : public SampleDevice
{
public:
	GY30Device();
	void init();
	unsigned int getLighteness();

private:
	BH1750xtra bhSensor;
};

#endif