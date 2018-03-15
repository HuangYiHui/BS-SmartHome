/*
 Name:		test1.ino
 Created:	2018/2/17 21:11:30
 Author:	ahui
*/

#include "ZBC.h"

void printCmd(ZBCmd& cmd)
{
	for(int i=0;i<cmd.len;i++)
	{
		Serial.print(cmd.cmd[i], HEX);
		Serial.print(",");
	}
	Serial.println();
}

void test1()
{
	ZBCfg cfg;

	ZBCmd cmd1;
	ZBC::chanlistCfg(cfg.channel, &cmd1);
	Serial.print("chanlistCfg : ");
	printCmd(cmd1);

	ZBCmd cmd2;
	ZBC::PANIDCfg(cfg.panID, &cmd2);
	Serial.print("PANIDCfg : ");
	printCmd(cmd2);

	ZBCmd cmd3;
	ZBC::deviceTypeCfg(0x00, &cmd3);
	Serial.print("deviceTypeCfg : ");
	printCmd(cmd3);

	ZBCmd cmd4;
	ZBAppReg reg;
	reg.endPoint = 0x78;
	ZBC::appRegister(reg, &cmd4);
	Serial.print("appRegister : ");
	printCmd(cmd4);

	ZBCmd cmd5;
	ZBPacketSend packet;
	packet.dstAddr[0] = 0x01;
	packet.dstAddr[1] = 0x02;
	packet.dstEndpoint = 0x03;
	packet.srcEndpoint = 0x04;
	packet.clusterID[0] = 0x05;
	packet.clusterID[1] = 0x06;
	packet.options = 0x07;
	packet.radius = 0x08;
	packet.transID = 0x09;
	packet.len = 0x03;
	packet.data = new unsigned char[3];
	packet.data[0] = 0x01;
	packet.data[1] = 0x02;
	packet.data[2] = 0x03;
	ZBC::packetSend(packet, &cmd5);
	Serial.print("packetSend : ");
	printCmd(cmd5);

	while(true);
}

void test2(){
	byte bs[] = {
		0xFE, 0x19, 0x44, 0x81, 0x00, 
		0x01, 0x00, 0x02, 0x34, 0x12, 
		0x56, 0x78, 0x00, 0x00, 0x00, 
		0x12, 0x34, 0x56, 0x78, 0x00, //c6
		0x08, 
		0x00, 0x01, 0x00, 0x0d, 0xc2, 0xf6, 0xe6, 0x66,
		0x6f};
	Serial.write(bs, 35);
	delay(5000);
}

void test3(){
	unsigned int appID = 0x1234;
	unsigned char b1 = 0x12;
	unsigned char b2 = 0x34;
	unsigned char b3 = appID / 256;
	unsigned char b4 = appID % 256;
	unsigned int value = 256 * b3 + b4;
	if(appID == value){
		Serial.println("==");
	}else{
		Serial.println("!=");
	}
	while(true);
}
unsigned long cTime;
void setup() {
	Serial.begin(19200);
//	test();
	cTime = millis();
}

void loop() {
	test3();
}

