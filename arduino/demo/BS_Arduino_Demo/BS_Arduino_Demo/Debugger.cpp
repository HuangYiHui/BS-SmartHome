#include "Debugger.h"
/*
void Debuger::printZBPacketReceive(ZBPacketReceive& packet)
{
}
*/
void Debugger::printAppMsg(AppMsg& msg)
{
	Serial.println("------Msg-----------");
	Serial.print("len:");
	Serial.println(msg.len, HEX);
	Serial.print("data:");
	for(unsigned int i=0;i<msg.len;i++){
		Serial.print(msg.data[i], HEX);
		Serial.print(",");
	}
	Serial.println();
	Serial.println("------Msg-----------");
}