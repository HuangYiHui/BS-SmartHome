#ifndef _BS_SIMPLE_SENSOR_DEVICE_H_
#define _BS_SIMPLE_SENSOR_DEVICE_H_

#include "SensorDevice.h"

//SimpleSensorDevice��ֻͨ����ȡĳ�����ŵ�ֵ���ܻ�ȡ��������ֵ���豸

#define SENSOR_READ_MODE_ANALOG		0x01
#define SENSOR_READ_MODE_DIGITAL	0x02

class SimpleSensorDevice : public SensorDevice
{
public:
	SimpleSensorDevice(unsigned int deviceID, devicePin pin, unsigned char readMode);
	void start();
	float getSensorValue();

private:
	devicePin pin;
	unsigned char readMode;
};

#endif