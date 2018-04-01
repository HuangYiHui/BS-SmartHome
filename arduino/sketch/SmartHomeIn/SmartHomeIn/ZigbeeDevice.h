#ifndef _BS_ZIGBEE_DEVICE_H
#define _BS_ZIGBEE_DEVICE_H

/*
用ZBAppReg注册过的endpoint，才能接收到目标是对应endpoint的其他zigbee的信息包，否则zigbee会丢弃该数据包
*/

/*
数据格式：SOF - lenght - cmd1 - cmd2 - data - FCS
SOF为开始标识，一个字节，恒定为0xfe
lenght表示后续数据data长度，一个字节
cmd1和cmd2都是一个字节
data表示长度为lenght的数据
fcs为lenght、cmd1、cmd2和data的异或校验
*/

#include "IDevice.h"
#include "Tool.h"

#define SOF 0xfe

//信息包，用于表示zigbee接收到的原始信息包
//当len为0的时候表示数据包无效
typedef struct ZBPacketReceive
{
	unsigned char len;		//数据长度
	unsigned char* data;	//数据
	unsigned char cmd1;
	unsigned char cmd2;
	ZBPacketReceive()
	{
		len = 0;
		cmd1 = 0x00;
		cmd2 = 0x00;
		data = NULL;
	}
	void reset()
	{
		len = 0;
		cmd1 = 0x00;
		cmd2 = 0x00;
		delete[] data;
		data = NULL;
	}
	~ZBPacketReceive()
	{
		delete[] data;
	}

	bool validate(unsigned char cFcs)
	{
		//初始值设为len字段的值
		unsigned char fcs = len;
		fcs ^= cmd1;
		fcs ^= cmd2;
		for(unsigned char i=0;i<len;i++)
			fcs ^= data[i];
		//Serial.print("fcs:");
		//Serial.print(fcs, HEX);
		if(cFcs == fcs)
			return true;
		else
			return false;
	}
}ZBPacketRecive;

//zigbee用于发送的信息包
//srcEndpoint一定得是用ZBAppReg注册过的endpoint，才能从这个endpoint发送消息出去，否则zigbee会丢弃这个数据包

typedef struct ZBPacketSend
{
	unsigned char dstAddr[2];
	unsigned char dstEndpoint;
	unsigned char srcEndpoint;
	unsigned char clusterID[2];
	unsigned char transID;
	unsigned char options;
	unsigned char radius;
	unsigned char len;
	unsigned char* data;

	~ZBPacketSend()
	{
		delete[] data;
		data = NULL;
	}

}ZBPacketSend;


const unsigned char CMD_DEVICE_RESET_BYTES[6] PROGMEM = {SOF, 0x01, 0x41, 0x00, 0x00, 0x40};
const unsigned char CMD_STARTUP_WITHOUT_LAST_STATE_BYTES[8] PROGMEM = {SOF, 0x03, 0x26, 0x05, 0x03, 0x01, 0x03, 0x21};
const unsigned char CMD_ZDO_DIRECT_CB_BYTES[8] PROGMEM = {SOF, 0x03, 0x26, 0x05, 0x8f, 0x01, 0x01, 0xaf};
//信道使用0x00000800
//const unsigned char CMD_CHANNEL_SET_BYTES[11] PROGMEM = {SOF, 0x06, 0x26, 0x05, 0x84, 0x04, 0x00, 0x08, 0x00, 0x00, 0xad};
//工作子网为0xffff
//const unsigned char CMD_PANID_SET_BYTES[9] PROGMEM = {SOF, 0x04, 0x26, 0x05, 0x83, 0x02, 0xff, 0xff, 0xa6};
//设备类型0x01,路由器
const unsigned char CMD_DEVICE_TYPE_SET_BYTES[8] PROGMEM = {SOF, 0x03, 0x26, 0x05, 0x87, 0x01, 0x01, 0xa7};
//应用注册
//const unsigned char CMD_APP_REGISTER_BYTES[14] PROGMEM = {SOF, 0x09, 0x24, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78};
const unsigned char CMD_APP_REGISTER_BYTES[18] PROGMEM = {SOF, 0x0d, 0x24, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x7C};
//开始应用
const unsigned char CMD_STARTUP_FROM_APP_BYTES[7] PROGMEM = {SOF, 0x02, 0x25, 0x40, 0x00, 0x00, 0x67};

class ZigbeeDevice : public SampleDevice
{
private:
	int readByte();
	unsigned char calCrc(const unsigned char *pMsg, unsigned char len);
	void getPacketSendBytes(ZBPacketSend& packet, unsigned char* bs);
	unsigned int receiveTimeout;	//接收超时，单位ms
	void receive(ZBPacketReceive& packet, unsigned int timeout);
	void sendFlashCmdBytes(unsigned int address, unsigned int len);
	bool startUpWithoutLastState();
	bool restart();
	bool setDeviceType();
	bool setDirectCB();
	bool registerApp();
	
public:
	ZigbeeDevice();
	void start();
	bool isDataComing();
	void receive(ZBPacketReceive& packet);
	void send(ZBPacketSend& packet);
	void setReceiveTimeout(unsigned int receiveTimeout);
	bool startFromApp();
};

#endif