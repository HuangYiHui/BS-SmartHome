/*
	设备接口定义
*/

#ifndef _BS_IDEVICE_H_
#define _BS_IDEVICE_H_

//调使用
#include "MemoryFree.h"

#include "Arduino.h"
#include "SystemCfg.h"

class IDevice
{
public:
	virtual ~IDevice(){}
	virtual void start() = 0;
	virtual void stop() = 0;
};

class SampleDevice : public IDevice
{
public:
	virtual	void start(){};
	virtual	void stop(){};
};

#endif