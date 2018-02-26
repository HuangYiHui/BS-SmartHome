#ifndef _BS_ZIGBEE_DEVICE_H
#define _BS_ZIGBEE_DEVICE_H

/*
数据格式：SOF - lenght - cmd1 - cmd2 - data - FCS
SOF为开始标识，一个字节，恒定为0xfe
lenght表示后续数据data长度，一个字节
cmd1和cmd2都是一个字节
data表示长度为lenght的数据
fcs为lenght、cmd1、cmd2和data的异或校验
*/

#include "Arduino.h"
#include "ZBC.h"

#define ZB_DEVICE_TYPE_COORDINATOR 0x00
#define ZB_DEVICE_TYPE_ROUTE 0x01
#define ZB_DEVICE_TYPE_ENDPOINT 0x02

#define SOF 0xfe

	//unsigned char dstAddr[2];	//目标地址
	//unsigned char dstEndpoint;	//目标端点
	//unsigned char srcAddr[2];	//来源地址
	//unsigned char srcEndpoint;	//来源端点

//信息包，用于表示zigbee接收到的原始信息包
//当len为0的时候表示数据包无效
typedef struct ZBPacketReceive
{
	unsigned char len;			//数据长度
	unsigned char* data;		//数据
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

		if(cFcs == fcs)
			return true;
		else
			return false;
	}
}ZBPacketRecive;


typedef struct ZBCfg
{
	unsigned char channel[4];	//信道
	unsigned char panID[2];		//网络号
	unsigned char zdType;		//zigbee设备类型
	ZBCfg()
	{
		//设置0x00000800信道，默认也是0x00000800信道
		channel[0] = 0x00;
		channel[1] = 0x08;
		channel[2] = 0x00;
		channel[3] = 0x00;

		//设置默认网络号为1234
		panID[0] = 0x34;
		panID[1] = 0x12;

		//设置默认设备类型为路由器
		zdType = ZB_DEVICE_TYPE_ROUTE;
	}
	void clone(ZBCfg& cfg)
	{
		channel[0] = cfg.channel[0];
		channel[1] = cfg.channel[1];
		channel[2] = cfg.channel[2];
		channel[3] = cfg.channel[3];

		panID[0] = cfg.panID[0];
		panID[1] = cfg.panID[1];

		zdType = cfg.zdType;
	}
}ZBCfg;

class ZigbeeDevice
{
public:
	ZigbeeDevice();
	ZigbeeDevice(ZBCfg& cfg);
	void setChannel(unsigned char channel[4]);
	void setPANID(unsigned char panID[2]);
	void setZDType(unsigned char zdType);	//设置zigbee设备类型，设备类型在↑用宏定义
	void setAppReg(ZBAppReg& appReg);
	void sendReceiveTimeout(unsigned int timeout);	//设置接收数据包超时时间，单位为ms
	void init();
	ZBPacketReceive receivePacket();
	void sendPacket(ZBPacketSend& packet);

private:
	unsigned int receiveTimeout;
	ZBCfg cfg;
	ZBAppReg appReg;
	unsigned char calCrc(unsigned char beginValue, unsigned char *pMsg, unsigned char len);
	unsigned char readByte();
};

#endif