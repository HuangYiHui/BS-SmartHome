
#ifndef _BS_ZIGBEE_APP_H_
#define _BS_ZIGBEE_APP_H_

#include "ZigbeeDevice.h"

typedef struct
{
	unsigned int srcSystemAddr;
	unsigned char srcAppAddr;
	unsigned char dataLen;
	unsigned char* data;
}AppMsg;

class ZigbeeApp
{
public:
	ZigbeeApp(ZigbeeDevice& zigbee);
	void init();
	void run();
private:
	unsigned char transID;
	ZigbeeDevice& zigbee;
	AppMsg resolveMsg(ZBPacketReceive& dataPacket);
};

#endif