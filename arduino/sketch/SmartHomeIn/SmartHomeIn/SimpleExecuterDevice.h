
//���������ɷ������͵ƹ����

#ifndef _BS_SIMPLE_EXECUTER_DEVICE_H_
#define _BS_SIMPLE_EXECUTER_DEVICE_H_

#include "SampleDevice.h"

#define LOGIC_LEVEL_OPEN_HIGH HIGH
#define LOGIC_LEVEL_OPEN_LOW LOW

//�����豸��ֻ�п��͹ز���

class SimpleExecuterDevice : public SampleDevice
{
public:
	SimpleExecuterDevice(unsigned int deviceID, devicePin pin, unsigned char logicLevelOpen);
	void start();
	void openExecuter();
	void closeExecuter();
	bool isOpened();

private:
	devicePin pin;
	unsigned char logicLevelOpen;
	bool isSimpleExecuterOpened;
};

#endif