#include "Debuger.h"
/*
void Debuger::printZBPacketReceive(ZBPacketReceive& packet)
{
}
*/
void Debuger::printAppMsgReceive(AppMsgReceive& msg)
{
	Serial.println("------MsgReceive-----------");
	Serial.print("srcAddr:");
	Serial.println(msg.srcAddr, HEX);
	Serial.print("srcEndpoint:");
	Serial.println(msg.srcEndpoint, HEX);
	Serial.print("len:");
	Serial.println(msg.len, HEX);
	Serial.print("data:");
	for(unsigned int i=0;i<msg.len;i++){
		Serial.print(msg.data[i], HEX);
		Serial.print(",");
	}
	Serial.println();
	Serial.println("------MsgReceive-----------");
}

void printAppMsgSend(AppMsgSend& msg)
{
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
}