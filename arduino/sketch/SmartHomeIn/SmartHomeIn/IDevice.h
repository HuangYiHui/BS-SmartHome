/*
	�豸�ӿڶ���
*/

#ifndef _BS_IDEVICE_H_
#define _BS_IDEVICE_H_

//��ʹ��
#include <MemoryFree.h>

typedef unsigned char deviceState;
typedef unsigned char devicePin;

class IDevice
{
public:
	virtual ~IDevice(){}
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual unsigned int getDeviceID() = 0;
};

#endif