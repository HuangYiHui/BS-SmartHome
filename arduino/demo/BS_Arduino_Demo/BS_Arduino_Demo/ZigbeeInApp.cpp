#include "ZigbeeInApp.h"

//zigbee使用注意
//设备类型正确、目标地址是否正确，endpoint是否注册

ZigbeeInApp::ZigbeeInApp(unsigned int appID, ZigbeeDevice& zigbee) : SampleApp(appID), zigbee(zigbee)
{
	zbPacketTransID = 0;
	state = APP_STATE_UNREADY;
}

void ZigbeeInApp::init()
{
	ZBAppReg appRegs[1];
	appRegs[0] = ZBAppReg();
	appRegs[0].endPoint = ZB_REG_ENDPOINT;
	appRegs[0].appProfID[0] = ZB_REG_APP_PROF_ID0;
	appRegs[0].appProfID[1] = ZB_REG_APP_PROF_ID1;
	appRegs[0].appDeviceID[0] = ZB_REG_APP_DEVICEID0;
	appRegs[0].appDeviceID[1] = ZB_REG_APP_DEVICEID1;
	appRegs[0].endDevVer = ZB_REG_END_DEV_VER;
	appRegs[0].latencyReq = ZB_REG_LATENCY_REQ;
	appRegs[0].appNumInClusters = ZB_REG_APP_NUM_IN_CLUSTERS;
	appRegs[0].appNumOutClusters = ZB_REG_APP_NUM_OUT_CLUSTERS;

	zigbee.setAppRegs(appRegs, 1);

	zigbee.begin();
	PT_INIT(&pt);

	//调试用
	pinMode(13, OUTPUT);

	state = APP_STATE_READY;
}


int ZigbeeInApp::exeTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_TIMER_DELAY(&pt, 2000);
		ZBPacketSend packet;
		packet.dstAddr[0] = 0x00;
		packet.dstAddr[1] = 0x00;
		packet.dstEndpoint = ZB_PACKET_SEND_DST_ENDPOINT;
		packet.srcEndpoint = ZB_PACKET_SEND_SRC_ENDPOINT;
		packet.len = 3;
		packet.data = new unsigned char[3];
		packet.data[0] = 0x01;
		packet.data[1] = 0x02;
		packet.data[2] = 0x04;
		packet.clusterID[0] = 0x00;
		packet.clusterID[1] = 0x00;
		packet.options = 0x00;
		packet.radius = 0x00;
		packet.transID = 0x00;
		zigbee.send(packet);
		//Serial.println("zigbeeApp run...");
	}
	PT_END(&pt);
}


void ZigbeeInApp::run()
{
//	exeTask();
//	return;

	if( ! zigbee.isDataComing())
		return;
	ZBPacketReceive packet;
	zigbee.receive(packet);
	//收到有效信息
	if(packet.len != 0 && packet.cmd1 == 0x44 && packet.cmd2 == 0x81){
		int dataLen = packet.data[16];
		if(dataLen > 3){
			AppMsg msg;
			int appID = packet.data[17] + 256*packet.data[18];
			msg.len = dataLen-2;
			msg.data = new unsigned char[dataLen-2];
			for(unsigned int i=0;i<dataLen-2;i++){
				msg.data[i] = packet.data[19+i];
			}
			sendMsg(msg, appID);
		}
	}
}