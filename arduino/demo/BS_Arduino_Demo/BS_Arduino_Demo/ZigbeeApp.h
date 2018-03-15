
#ifndef _BS_ZIGBEE_APP_H_
#define _BS_ZIGBEE_APP_H_

#include "pt.h"
#include "ZigbeeDevice.h"
#include "SampleApp.h"
#include "Debuger.h"
#include "SystemCfg.h"

class ZigbeeApp : public SampleApp
{
public:
	ZigbeeApp(unsigned int appID, ZigbeeDevice& zigbee);
	void init();
	void run();
	int exeTask();
private:
	unsigned char zbPacketTransID;
	ZigbeeDevice& zigbee;
	struct pt pt;
};

#endif