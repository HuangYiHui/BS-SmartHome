
#ifndef _BS_ZIGBEE_IN_APP_H_
#define _BS_ZIGBEE_IN_APP_H_

#include "pt.h"
#include "ZigbeeDevice.h"
#include "SampleApp.h"
#include "SystemCfg.h"
#include "ZigbeeAppCmd.h"

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

class ZigbeeApp : public SampleApp
{
public:
	ZigbeeApp(unsigned int appID, ZigbeeDevice& zigbee);
	void init();
	void run();
private:
	void prcAppMsg();
	void receiveZigbeeMsg();
	ZigbeeDevice& zigbee;
};

#endif