#include "ZigbeeApp.h"

//zigbee使用注意
//设备类型正确、目标地址是否正确，endpoint是否注册

ZigbeeApp::ZigbeeApp(ZigbeeDevice& zigbee) : zigbee(zigbee)
{
	this->appID = APP_ID_OUT_ZIGBEE;
}

void ZigbeeApp::init()
{
	zigbee.start();
}

void ZigbeeApp::receiveZigbeeMsg()
{
	if( ! zigbee.isDataComing())
		return;
	ZBPacketReceive packet;
	zigbee.receive(packet);
	//收到有效信息
	if(packet.len != 0 && packet.cmd1 == 0x44 && packet.cmd2 == 0x81){
		unsigned int dataLen = packet.data[16];
		if(dataLen<1)
			return;
		unsigned char cmd = packet.data[17];
		if(cmd == CMD_ZIGBEE_APP_UPLAOD_ALL_DEVICE_VALUE){
			AppMsg msg;
			msg.len = 1;
			msg.data = new unsigned char[1];
			msg.data[0] = CMD_UPLOAD_ALL_DEVICE_VALUE;
			sendMsg(msg, APP_ID_OUT_SENSOR);
		}
	}
}

void ZigbeeApp::appMsgReceivedCallback(AppMsg& msg)
{
	if(msg.len < 1)
		return;

	ZBPacketSend packet;
	packet.dstEndpoint = ZB_PACKET_SEND_DST_ENDPOINT;
	packet.srcEndpoint = ZB_PACKET_SEND_SRC_ENDPOINT;
	packet.clusterID[0] = ZB_PACKET_SEND_CLUSTER_ID0;
	packet.clusterID[1] = ZB_PACKET_SEND_CLUSTER_ID1;
	packet.options = ZB_PACKET_SEND_OPTIONS;
	packet.radius = ZB_PACKET_SEND_RADIUS;

	unsigned char cmd = msg.data[0];
	//数据上传
	if(CMD_UPLOAD_DATA == cmd){
		if(msg.len != 7)
			return;
		packet.dstAddr[0] = 0x00;
		packet.dstAddr[1] = 0x00;
		packet.len = msg.len;
		packet.data = new unsigned char[msg.len];
		Tool::byteArrayCopy(msg.data, 0, packet.data, 0, msg.len);
		zigbee.send(packet);
	}else if(CMD_OUT_SENSOR_VALUES_COMING == cmd){
		if(msg.len != 25)
			return;
		packet.dstAddr[0] = 0x00;
		packet.dstAddr[1] = 0x00;
		packet.len = 25;
		packet.data = new unsigned char[25];
		for(int i=0;i<25;i++){
			packet.data[i] = msg.data[i];
		}
		zigbee.send(packet);
	}
}

void ZigbeeApp::run()
{
	receiveZigbeeMsg();
}

