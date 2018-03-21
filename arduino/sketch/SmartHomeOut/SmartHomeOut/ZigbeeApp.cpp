#include "ZigbeeApp.h"

//zigbeeʹ��ע��
//�豸������ȷ��Ŀ���ַ�Ƿ���ȷ��endpoint�Ƿ�ע��

ZigbeeApp::ZigbeeApp(unsigned int appID, ZigbeeDevice& zigbee) : SampleApp(appID), zigbee(zigbee)
{
	state = APP_STATE_UNREADY;
}

void ZigbeeApp::init()
{
	zigbee.begin();

	state = APP_STATE_READY;
}

void ZigbeeApp::receiveZigbeeMsg()
{
	if( ! zigbee.isDataComing())
		return;
	ZBPacketReceive packet;
	zigbee.receive(packet);
	//�յ���Ч��Ϣ
	if(packet.len != 0 && packet.cmd1 == 0x44 && packet.cmd2 == 0x81){
		unsigned int dataLen = packet.data[16];
		//����4��byte��ǰ2byte��appID,��2byte������
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

void ZigbeeApp::prcAppMsg()
{
	while(msgList.size() > 0){

		AppMsg* msg = msgList.remove(0);
		if(msg->len < 1){
			delete msg;
			return;
		}
		int cmd = msg->data[0] + 256 * msg->data[1];
		//�����ϴ�
		if(CMD_UPLOAD_DATA == cmd){
			//CMD_UPLOAD_DATA�������2��byte��cmd�⣬�������ֽ��������ϴ����־,��������1��byte,����Ҫ����5��byte
			if(msg->len < 5){
				delete msg;
				return;
			}
			
			ZBPacketSend packet;
			packet.dstAddr[0] = 0x00;
			packet.dstAddr[1] = 0x00;
			packet.dstEndpoint = ZB_PACKET_SEND_DST_ENDPOINT;
			packet.srcEndpoint = ZB_PACKET_SEND_SRC_ENDPOINT;
			packet.clusterID[0] = ZB_PACKET_SEND_CLUSTER_ID0;
			packet.clusterID[1] = ZB_PACKET_SEND_CLUSTER_ID1;
			packet.options = ZB_PACKET_SEND_OPTIONS;
			packet.radius = ZB_PACKET_SEND_RADIUS;
			packet.len = msg->len;
			packet.data = new unsigned char[msg->len];
			Tool::byteArrayCopy(msg->data, 0, packet.data, 0, msg->len);
			zigbee.send(packet);
		}else if(CMD_RSPONSE_TO_GET_EXECUTER_STATUS == cmd){
			if(msg->len != 7){
				delete msg;
				return;
			}
			ZBPacketSend packet;
			packet.dstAddr[0] = 0x00;
			packet.dstAddr[1] = 0x00;
			packet.dstEndpoint = ZB_PACKET_SEND_DST_ENDPOINT;
			packet.srcEndpoint = ZB_PACKET_SEND_SRC_ENDPOINT;
			packet.clusterID[0] = ZB_PACKET_SEND_CLUSTER_ID0;
			packet.clusterID[1] = ZB_PACKET_SEND_CLUSTER_ID1;
			packet.options = ZB_PACKET_SEND_OPTIONS;
			packet.radius = ZB_PACKET_SEND_RADIUS;
			packet.len = msg->len;
			packet.data = new unsigned char[msg->len];
			Tool::byteArrayCopy(msg->data, 0, packet.data, 0, msg->len);
	//		zigbee.send(packet);
		}
		delete msg;
	}
}

void ZigbeeApp::run()
{
	receiveZigbeeMsg();
	prcAppMsg();
}

