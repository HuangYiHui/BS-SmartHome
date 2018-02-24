
//���������ɷ������͵ƹ����

#ifndef _BS_ALARM_DEVICE_H_
#define _BS_ALARM_DEVICE_H_

#include "Arduino.h"
#include "SampleDevice.h"

class AlarmDevice : public SampleDevice
{
public:
	AlarmDevice(devicePin pin);
	void init();
	void start();
	void stop();
private:
	devicePin pin;
};

#endif