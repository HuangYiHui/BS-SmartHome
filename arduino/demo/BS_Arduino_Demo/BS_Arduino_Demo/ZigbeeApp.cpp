#include "ZigbeeApp.h"

//zigbee使用注意
//设备类型正确、目标地址是否正确，endpoint是否注册

ZigbeeApp::ZigbeeApp(unsigned int appID, ZigbeeDevice& zigbee) : SampleApp(appID), zigbee(zigbee)
{
	zbPacketTransID = 0;
	state = APP_STATE_UNREADY;
}

void ZigbeeApp::init()
{
	ZBAppReg appRegs[1];
	appRegs[0] = ZBAppReg();
	appRegs[0].endPoint = ZIGBEE_REGISTER_ENDPOINT;
	zigbee.setAppRegs(appRegs, 1);

	zigbee.ready();
	zigbee.start();
	PT_INIT(&pt);

	//调试用
	pinMode(13, OUTPUT);

	state = APP_STATE_READY;
}


int ZigbeeApp::exeTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_TIMER_DELAY(&pt, 2000);
		ZBPacketSend packet;
		packet.dstAddr[0] = 0x00;
		packet.dstAddr[1] = 0x00;
		packet.dstEndpoint = ZIGBEE_REGISTER_ENDPOINT;
		packet.srcEndpoint = ZIGBEE_REGISTER_ENDPOINT;
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


void ZigbeeApp::run()
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

		//Debuger::printAppMsgSend(msg);
		/*
		Serial.println("------MsgSend-----------");
	Serial.print("srcAddr:");
	Serial.println(msg.srcAddr, HEX);
	Serial.print("srcEndpoint:");
	Serial.println(msg.srcEndpoint, HEX);
	Serial.print("dstAddr:");
	Serial.println(msg.dstAddr, HEX);
	Serial.print("dstEndpoint:");
	Serial.println(msg.dstEndpoint, HEX);
	Serial.print("len:");
	Serial.println(msg.len, HEX);
	Serial.print("data:");
	for(unsigned int i=0;i<msg.len;i++){
		Serial.print(msg.data[i], HEX);
		Serial.print(",");
	}
	Serial.println();
	Serial.println("------MsgSend-----------");
	*/
		for(int i=0;i<3;i++){
			digitalWrite(13, HIGH);
			delay(100);
			digitalWrite(13, LOW);
			delay(100);
		}
	}

	//exeTask();
}