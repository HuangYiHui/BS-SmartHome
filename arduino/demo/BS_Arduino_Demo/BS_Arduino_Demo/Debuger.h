#ifndef _BS_DEBUGER_H_
#define _BS_DEBUGER_H_

#include "Arduino.h"
//#include "ZigbeeDevice.h"
#include "AppMsg.h"

class Debuger
{
public:
	//static void printZBPacketReceive(ZBPacketReceive& packet);
	static void printAppMsgReceive(AppMsgReceive& msg);
	static void printAppMsgSend(AppMsgSend& msg);
};

#endif