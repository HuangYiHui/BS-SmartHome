
#ifndef _BS_ZIGBEE_IN_APP_H_
#define _BS_ZIGBEE_IN_APP_H_

#include "ZigbeeDevice.h"
#include "SampleApp.h"
#include "SystemCfg.h"
#include "ZigbeeAppCmd.h"
#include "LCDAppCmd.h"
#include "DangerAlarmAppCmd.h"
#include "pt.h"

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
	void init();	//初始化
	void run();		//运行
	void appMsgReceivedCallback(AppMsg& msg);	//应用消息回调
private:
	ZigbeeDevice& zigbee;
	struct pt ptQueryIsOnline;
	bool isOnline;
	void receiveZigbeeMsg();	//接收zigbee消息
	int runQueryIsOnlineTask();	//运行查询是否在线任务
	void queryIsZigbeeOnline();	//运行查询是否
	void noticeLCDIsOnline(bool isOnline);	//同时LCD是否在线
};

#endif