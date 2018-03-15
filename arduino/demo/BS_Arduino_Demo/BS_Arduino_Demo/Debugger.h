#ifndef _BS_DEBUGGER_H_
#define _BS_DEBUGGER_H_

#include "Arduino.h"
//#include "ZigbeeDevice.h"
#include "AppMsg.h"

class Debugger
{
public:
	//static void printZBPacketReceive(ZBPacketReceive& packet);
	static void printAppMsg(AppMsg& msg);
};

#endif