#ifndef _BS_ISYSTEM_H_
#define _BS_ISYSTEM_H_

//µ÷Ê¹ÓÃ
#include <MemoryFree.h>

#include "Arduino.h"
#include "IApp.h"

class ISystem
{
public:
	virtual ~ISystem(){}
	virtual void init() = 0;
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void reset() = 0;
	virtual void installApp(IApp* app) = 0;
	virtual void sendAppMsg(AppMsg& msg, unsigned char appID) = 0;
};
#endif