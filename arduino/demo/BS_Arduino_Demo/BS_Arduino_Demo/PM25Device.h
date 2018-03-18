//土壤湿度传感器

#ifndef _BS_PM25_DEVICE_H_
#define _BS_PM25_DEVICE_H_

#include "SensorDevice.h"
#include "Arduino.h"

class PM25Device : public SensorDevice
{
public:
	PM25Device(devicePin ledPin, devicePin voPin, unsigned int sensorValueIndex);
	void init();
	float getSensorValue();

private:
	devicePin ledPin;
	devicePin voPin;
};

#endif