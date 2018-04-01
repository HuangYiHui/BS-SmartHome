
#ifndef _BS_ZIGBEE_IN_APP_H_
#define _BS_ZIGBEE_IN_APP_H_

#include "pt.h"
#include "ZigbeeDevice.h"
#include "SampleApp.h"
#include "SystemCfg.h"
#include "ZigbeeAppCmd.h"

#define ZB_PACKET_SEND_DST_ENDPOINT	0x55
#define ZB_PACKET_SEND_SRC_ENDPOINT 0x55
#define ZB_PACKET_SEND_CLUSTER_ID0	0x00
#define ZB_PACKET_SEND_CLUSTER_ID1	0x00
#define ZB_PACKET_SEND_OPTIONS		0x00
#define ZB_PACKET_SEND_RADIUS		0x00

class ZigbeeApp : public SampleApp
{
public:
	ZigbeeApp(ZigbeeDevice& zigbee);
	void init();
	void run();
	void appMsgReceivedCallback(AppMsg& msg);
private:
	ZigbeeDevice& zigbee;
	void receiveZigbeeMsg();
};


#endif