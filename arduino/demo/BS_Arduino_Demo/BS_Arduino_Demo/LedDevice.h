//土壤湿度传感器

#ifndef _BS_LED_DEVICE_H_
#define _BS_LED_DEVICE_H_

#include "SampleDevice.h"
#include "Arduino.h"

class LEDDevice : public SampleDevice
{
public:
	LEDDevice(devicePin pin);
	void init();
	void light();
	void extinguish();

private:
	devicePin pin;
};

#endif