//土壤湿度传感器

#ifndef _BS_PM25_DEVICE_H_
#define _BS_PM25_DEVICE_H_

#include "SensorDevice.h"
#include "Arduino.h"

class PM25Device : public SensorDevice
{
public:
	PM25Device(unsigned char deviceID, unsigned char ledPin, unsigned char voPin);
	void start();
	float getSensorValue();

private:
	unsigned char ledPin;	//PM2.5传感器的LED引脚	
	unsigned char voPin;	//PM2.5传感器输出引脚
};

#endif