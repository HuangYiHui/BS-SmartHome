//����ʪ�ȴ�����

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
	unsigned char ledPin;	//PM2.5��������LED����	
	unsigned char voPin;	//PM2.5�������������
};

#endif