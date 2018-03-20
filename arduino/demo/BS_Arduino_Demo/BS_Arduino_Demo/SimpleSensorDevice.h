#ifndef _BS_SIMPLE_SENSOR_DEVICE_H_
#define _BS_SIMPLE_SENSOR_DEVICE_H_

#include "SensorDevice.h"
#include "Arduino.h"

//SimpleSensorDevice是只通过读取某个引脚的值就能获取传感器的值的设备

#define SENSOR_READ_MODE_ANALOG 0x01
#define SENSOR_READ_MODE_DIGITAL 0x02

class SimpleSensorDevice : public SensorDevice
{
public:
	SimpleSensorDevice(unsigned int deviceID, devicePin pin, unsigned char readMode, unsigned int sensorValueIndex);
	void init();
	float getSensorValue();

private:
	devicePin pin;
	unsigned char readMode;
};

#endif