#include "ZigbeeApp.h"

ZigbeeApp::ZigbeeApp(ZigbeeDevice& zigbee):zigbee(zigbee)
{
}

void ZigbeeApp::init()
{
	//zigbee.setZDType(ZB_DEVICE_TYPE_COORDINATOR);
	zigbee.init();
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
void ZigbeeApp::run()
{
	ZBPacketSend packet;
	packet.dstAddr[0] = 0xff;
	packet.dstAddr[1] = 0xff;
	packet.dstEndpoint = 0x01;
	packet.srcEndpoint = 0x01;
	packet.clusterID[0] = 0x01;
	packet.clusterID[1] = 0x01;
	packet.transID = transID++;
	packet.options = 0x00;
	packet.radius = 0x00;
	packet.len = 0x03;
	packet.data = new unsigned char[3];
	packet.data[0] = 56;
	packet.data[1] = 56;
	packet.data[2] = 56;
	zigbee.sendPacket(packet);
	/*
	DataPacket dataPacket = zigbee.readDataPacket();
	if(dataPacket.len == 0)
		Serial.println("bad msg");
	else{
		Serial.println("good msg");
		AppMsg msg = resolveMsg(dataPacket);
		Serial.print("srcSystemAddr:");
		Serial.println(msg.srcSystemAddr, HEX);
		Serial.print("srcAppAddr:");
		Serial.println(msg.srcAppAddr, HEX);
		Serial.print("dataLen:");
		Serial.println(msg.dataLen, HEX);
		Serial.print("data:");
		for(int i=0;i<(msg.dataLen);i++){
			Serial.print(msg.data[i], HEX);
			Serial.print(',');
		}
		Serial.println();
		Serial.println("-------------");
	}
	*/
}

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