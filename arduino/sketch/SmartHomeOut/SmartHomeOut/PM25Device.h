//土壤湿度传感器

#ifndef _BS_PM25_DEVICE_H_
#define _BS_PM25_DEVICE_H_

#include "SensorDevice.h"
#include "Arduino.h"

class PM25Device : public SensorDevice
{
public:
	PM25Device(unsigned int deviceID, unsigned char ledPin, unsigned char voPin);
	void start();
	float getSensorValue();

private:
	unsigned char ledPin;
	unsigned char voPin;
};

#endif