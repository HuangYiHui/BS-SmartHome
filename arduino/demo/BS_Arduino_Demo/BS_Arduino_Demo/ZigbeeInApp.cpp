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

	state = APP_STATE_READY;
}

void ZigbeeInApp::receiveZigbeeMsg()
{
	if( ! zigbee.isDataComing())
		return;
	ZBPacketReceive packet;
	zigbee.receive(packet);
	//收到有效信息
	if(packet.len != 0 && packet.cmd1 == 0x44 && packet.cmd2 == 0x81){
		unsigned int dataLen = packet.data[16];
		//至少4个byte，前2byte作appID,后2byte作命令
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

void ZigbeeInApp::prcAppMsg()
{
	if(msgList.size() < 1)
		return;
	AppMsg* msg = msgList.remove(0);
	if(msg->len < 1){
		delete msg;
		return;
	}
	int cmd = msg->data[0] + 256 * msg->data[1];
	//数据上传
	if(CMD_UPLOAD_DATA == cmd){
		//CMD_UPLOAD_DATA命令，除了2个byte的cmd外，后两个字节作数据上传项标志,数据至少1个byte,所以要大于5个byte
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
		zigbee.send(packet);
	}
	delete msg;
}

void ZigbeeInApp::run()
{
	receiveZigbeeMsg();
	prcAppMsg();
}

