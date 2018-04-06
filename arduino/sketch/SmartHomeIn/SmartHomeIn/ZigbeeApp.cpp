#include "ZigbeeApp.h"

//zigbeeʹ��ע��
//�豸������ȷ��Ŀ���ַ�Ƿ���ȷ��endpoint�Ƿ�ע��

ZigbeeApp::ZigbeeApp(ZigbeeDevice& zigbee) : zigbee(zigbee)
{
	this->appID = APP_ID_IN_ZIGBEE;

	isOnline = false;
}

void ZigbeeApp::init()
{
	zigbee.start();
	PT_INIT(&ptQueryIsOnline);
}

void ZigbeeApp::noticeLCDIsOnline(bool isOnline)
{
	AppMsg msg;
	msg.len = 2;
	msg.data = new unsigned char[2];
	msg.data[0] = CMD_NOTICE_ZIGBEE_ONLINE;

	if(isOnline){
		msg.data[1] = FLAG_ONLINE;
	}else{
		msg.data[1] = FLAG_OFFLINE;
	}

	sendMsg(msg, APP_ID_LCD);
}

int ZigbeeApp::runQueryIsOnlineTask()
{
	PT_BEGIN(&ptQueryIsOnline);
	while(true)
	{
		if(isOnline)
			isOnline = false;
		else{
			noticeLCDIsOnline(false);
		//	zigbee.startFromApp();
		}

		queryIsZigbeeOnline();

		PT_TIMER_DELAY(&ptQueryIsOnline, 5000);
	}
	PT_END(&ptQueryIsOnline);
}

void ZigbeeApp::queryIsZigbeeOnline()
{
	ZBPacketSend packet;
	packet.dstEndpoint = ZB_PACKET_SEND_DST_ENDPOINT;
	packet.srcEndpoint = ZB_PACKET_SEND_SRC_ENDPOINT;
	packet.clusterID[0] = ZB_PACKET_SEND_CLUSTER_ID0;
	packet.clusterID[1] = ZB_PACKET_SEND_CLUSTER_ID1;
	packet.options = ZB_PACKET_SEND_OPTIONS;
	packet.radius = ZB_PACKET_SEND_RADIUS;
	packet.dstAddr[0] = 0x00;
	packet.dstAddr[1] = 0x00;
	packet.len = 1;
	packet.data = new unsigned char[1];
	packet.data[0] = CMD_QUERY_ZIGBEE_IS_ONLINE;
	zigbee.send(packet);
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
	packet.transID = 0x00;
	packet.options = ZB_PACKET_SEND_OPTIONS;
	packet.radius = ZB_PACKET_SEND_RADIUS;

	unsigned char cmd = msg.data[0];
	//�����ϴ�
	if(CMD_UPLOAD_DATA == cmd){
		//CMD_UPLOAD_DATA�������1��byte��cmd�⣬��1���ֽ��������ϴ����־,��������1��byte,����Ҫ����5��byte
		if(msg.len < 3)
			return;

		packet.dstAddr[0] = 0x00;
		packet.dstAddr[1] = 0x00;
		packet.len = msg.len;
		
		packet.data = new unsigned char[msg.len];
		Tool::byteArrayCopy(msg.data, 0, packet.data, 0, msg.len);
		zigbee.send(packet);
	}
	/*
	else if(CMD_RSPONSE_TO_GET_EXECUTER_STATUS == cmd){
		if(msg.len != 7)
			return;
		packet.dstAddr[0] = 0x00;
		packet.dstAddr[1] = 0x00;
		packet.len = msg.len;
		packet.data = new unsigned char[msg.len];
		Tool::byteArrayCopy(msg.data, 0, packet.data, 0, msg.len);
		zigbee.send(packet);
	}*/

}

/*
void ZigbeeApp::responseOnline(unsigned char address0,unsigned char address1)
{
	ZBPacketSend packet;
	packet.dstEndpoint = ZB_PACKET_SEND_DST_ENDPOINT;
	packet.srcEndpoint = ZB_PACKET_SEND_SRC_ENDPOINT;
	packet.clusterID[0] = ZB_PACKET_SEND_CLUSTER_ID0;
	packet.clusterID[1] = ZB_PACKET_SEND_CLUSTER_ID1;
	packet.options = ZB_PACKET_SEND_OPTIONS;
	packet.radius = ZB_PACKET_SEND_RADIUS;
	packet.dstAddr[0] = address0;
	packet.dstAddr[1] = address1;
	packet.len = 2;
	packet.data = new unsigned char[2];
	packet.data[0] = CMD_RESPONSE_ONLINE % 256;
	zigbee.send(packet);
}*/

void ZigbeeApp::receiveZigbeeMsg()
{
	if( ! zigbee.isDataComing())
		return;
	ZBPacketReceive packet;
	zigbee.receive(packet);
	//�յ���Ч��Ϣ
	if(packet.len != 0 && packet.cmd1 == 0x44 && packet.cmd2 == 0x81){
		unsigned int dataLen = packet.data[16];
		if(dataLen<1)
			return;
		unsigned char cmd = packet.data[17];

		if(cmd == CMD_SEND_MSG_TO_APP){
			//����4��byte��ǰ2byte��appID,��2byte������
			if(dataLen < 3)
				return;
			AppMsg msg;
			unsigned char appID = packet.data[18];
			msg.len = dataLen-2;
			msg.data = new unsigned char[msg.len];
			for(unsigned int i=0;i<dataLen-2;i++){
				msg.data[i] = packet.data[19+i];
			}
			sendMsg(msg, appID);
		}else if(cmd == CMD_RESPONSE_ZIGBEE_ONLINE){
			isOnline = true;
			noticeLCDIsOnline(true);
		}else if(cmd == CMD_OUT_SENSOR_VALUES_COMING){
			if(dataLen != 25)
				return;
			AppMsg msg;
			msg.len = 25;
			msg.data = new unsigned char[25];
			msg.data[0] = CMD_NOTICE_OUT_SENSOR_VALUES;
			for(int i=0;i<24;i++){
				msg.data[1+i] = packet.data[18+i];
			}
			sendMsg(msg, APP_ID_LCD);
		}else if(cmd == CMD_ZIGBEE_APP_UPLAOD_ALL_DEVICE_VALUE){
			AppMsg msg;
			msg.len = 1;
			msg.data = new unsigned char[1];
			msg.data[0] = CMD_UPLOAD_ALL_DEVICE_VALUE;
			sendMsg(msg, APP_ID_SIMPLE_EXECUTER);
			sendMsg(msg, APP_ID_IN_SENSOR);
		}
	}
}

void ZigbeeApp::run()
{
	receiveZigbeeMsg();
	runQueryIsOnlineTask();
}

