#ifndef _BS_IAPP_H_
#define _BS_IAPP_H_

#include "AppMsg.h"
//#include "CurSystem.h"

typedef unsigned char appState;

#define APP_STATE_UNREADY	0x31
#define APP_STATE_READY		0x32
#define APP_STATE_WORKING	0x33

class IApp
{
public:
	virtual void init() = 0;
	virtual void run() = 0;
	virtual void stop() = 0;
	virtual void reset() = 0;
	virtual appState getState() = 0;
	virtual unsigned int getAppID();
	virtual void receiveMsg(AppMsg& appMsg);
};

#endif