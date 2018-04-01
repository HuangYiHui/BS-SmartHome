
//警报器，由蜂鸣器和灯光组成

#ifndef _BS_SIMPLE_EXECUTER_DEVICE_H_
#define _BS_SIMPLE_EXECUTER_DEVICE_H_

#include "IDevice.h"

#define LOGIC_LEVEL_OPEN_HIGH HIGH
#define LOGIC_LEVEL_OPEN_LOW LOW

//开关设备，只有开和关操作

class SimpleExecuterDevice : public SampleDevice
{
public:
	SimpleExecuterDevice(unsigned char executerID, unsigned char pin, unsigned char logicLevelOpen);
	unsigned char getExecuterID();
	void start();
	void openExecuter();
	void closeExecuter();
	bool isOpened();

protected:
	unsigned char executerID;

private:
	unsigned char pin;
	unsigned char logicLevelOpen;
	bool isSimpleExecuterOpened;
};

#endif