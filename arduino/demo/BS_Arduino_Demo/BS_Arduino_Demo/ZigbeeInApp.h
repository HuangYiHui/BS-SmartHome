
#ifndef _BS_ZIGBEE_IN_APP_H_
#define _BS_ZIGBEE_IN_APP_H_

#include "pt.h"
#include "ZigbeeDevice.h"
#include "SampleApp.h"
#include "Debugger.h"
#include "SystemCfg.h"

#define ZB_REG_ENDPOINT	0x55
#define ZB_REG_APP_PROF_ID0	0x00
#define ZB_REG_APP_PROF_ID1	0x00
#define ZB_REG_APP_DEVICEID0	0x00
#define ZB_REG_APP_DEVICEID1	0x00
#define ZB_REG_END_DEV_VER	0x00
#define ZB_REG_LATENCY_REQ	0x00
#define ZB_REG_APP_NUM_IN_CLUSTERS 0x00
#define ZB_REG_APP_NUM_OUT_CLUSTERS	0x00

#define ZB_PACKET_SEND_DST_ENDPOINT	ZB_REG_ENDPOINT
#define ZB_PACKET_SEND_SRC_ENDPOINT ZB_REG_ENDPOINT
#define ZB_PACKET_SEND_CLUSTER_ID0	0x00
#define ZB_PACKET_SEND_CLUSTER_ID1	0x00
#define ZB_PACKET_SEND_OPTIONS		0x00
#define ZB_PACKET_SEND_RADIUS		0x00

class ZigbeeInApp : public SampleApp
{
public:
	ZigbeeInApp(unsigned int appID, ZigbeeDevice& zigbee);
	void init();
	void run();
	int exeTask();
private:
	unsigned char zbPacketTransID;
	ZigbeeDevice& zigbee;
	struct pt pt;
};

#endif