
//警报器，由蜂鸣器和灯光组成

#ifndef _BS_SIMPLE_EXECUTER_DEVICE_H_
#define _BS_SIMPLE_EXECUTER_DEVICE_H_

#include "Arduino.h"
#include "SampleDevice.h"

#define LOGIC_LEVEL_OPEN_HIGH HIGH
#define LOGIC_LEVEL_OPEN_LOW LOW

//开关设备，只有开和关操作

class SimpleExecuterDevice : public SampleDevice
{
public:
	SimpleExecuterDevice(devicePin pin, unsigned char logicLevelOpen);
	void init();
	void openSwitch();
	void closeSwitch();

private:
	devicePin pin;
	unsigned char logicLevelOpen;
};

#endif