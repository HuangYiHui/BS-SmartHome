#include "ZigbeeApp.h"

ZigbeeApp::ZigbeeApp(ZigbeeDevice& zigbee):zigbee(zigbee)
{
	zbPacketTransID = 0;
	state = APP_STATE_UNREADY;
}

void ZigbeeApp::init()
{
	zigbee.setZDType(ZB_DEVICE_TYPE_COORDINATOR);
	ZBAppReg appRegs[1];
	appRegs[0] = ZBAppReg();
	zigbee.setAppRegs(appRegs, 1);
	zigbee.ready();
	zigbee.start();
	PT_INIT(&pt);

	//调试用
	pinMode(13, OUTPUT);

	state = APP_STATE_READY;
}

/*
void printDataPacket(DataPacket& dataPacket)
{
	Serial.println("------DataPacket---------");
	for(int i=0;i<dataPacket.len;i++)
	{
		Serial.print(dataPacket.data[i], HEX);
		Serial.print(',');
	}
	Serial.println("------DataPacket---------");
}
*/

int ZigbeeApp::exeTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		//PT_WAIT_UNTIL(&pt, zigbee.isDataComing() == true);
		//if(zigbee.isDataComing() == true){
			ZBPacketReceive packet;
			zigbee.receive(&packet);
			//收到有效信息
			if(packet.len != 0){
				
				//Serial.println("good msg");
				/*
				for(int i=0;i<3;i++){
					digitalWrite(13, HIGH);
					delay(200);
					digitalWrite(13, LOW);
					delay(200);
				}*/
			}
			/*
			else{
				//Serial.println("bad msg");
				for(int i=0;i<10;i++){
					digitalWrite(13, HIGH);
					delay(50);
					digitalWrite(13, LOW);
					delay(50);
				}
			}
			*/
			delay(1000);
		//}
	}
	PT_END(&pt);
}


void ZigbeeApp::run()
{
	/*
	state = APP_STATE_WORKING;
	pinMode(13, OUTPUT);
	while(true){
		ZBPacketSend packet;
		packet.dstAddr[0] = 0xff;
		packet.dstAddr[1] = 0xff;
		packet.dstEndpoint = 0x01;
		packet.srcEndpoint = 0x01;
		packet.clusterID[0] = 0x01;
		packet.clusterID[1] = 0x01;
		packet.transID = zbPacketTransID++;
		packet.options = 0x00;
		packet.radius = 0x00;
		packet.len = 0x03;
		packet.data = new unsigned char[3];
		packet.data[0] = 56;
		packet.data[1] = 56;
		packet.data[2] = 56;
		zigbee.sendPacket(packet);

		for(int i=0;i<3;i++){
			digitalWrite(13, HIGH);
			delay(200);
			digitalWrite(13, LOW);
			delay(200);
		}

		delay(1000);
		
	}
	*/

	exeTask();
}

/*
AppMsg ZigbeeApp::resolveMsg(ZBPacketReceive& dataPacket)
{
	AppMsg msg;
	msg.srcSystemAddr = *((unsigned int *)&(dataPacket.data[6]));
	msg.srcAppAddr = dataPacket.data[8];
	msg.dataLen = dataPacket.data[18];
	msg.data = new unsigned char[dataPacket.data[18]];
	for(unsigned char i; i<dataPacket.data[18]; i++)
	{
		msg.data[i] = dataPacket.data[19+i];
	}

	return msg;
}
*/