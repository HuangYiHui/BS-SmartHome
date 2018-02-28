
#include "SystemIn.h"

#ifndef _BS_ZIGBEE_APP_H_
#define _BS_ZIGBEE_APP_H_

#include "pt.h"
#include "ZigbeeDevice.h"
#include "SampleApp.h"

class ZigbeeApp : public SampleApp
{
public:
	ZigbeeApp(ZigbeeDevice& zigbee);
	void init();
	void run();
	int exeTask();
private:
	unsigned char zbPacketTransID;
	ZigbeeDevice& zigbee;
	struct pt pt;
	//AppMsg resolveMsg(ZBPacketReceive& dataPacket);
};

#endif