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

#include "Arduino.h"
#include "ZBC.h"
#include "SampleDevice.h"
#include "LCDDevice.h"

//zigbee配置
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

class ZigbeeDevice : public SampleDevice
{
public:
	ZigbeeDevice();
	ZigbeeDevice(ZBCfg& cfg);
	ZigbeeDevice(ZBAppReg* appRegs, unsigned int count);
	ZigbeeDevice(ZBCfg& cfg, ZBAppReg* appRegs, unsigned int appRegCount);
	~ZigbeeDevice();
	void setChannel(unsigned char channel[4]);
	void setPANID(unsigned char panID[2]);
	void setZDType(unsigned char zdType);	//设置zigbee设备类型，设备类型在↑用宏定义
	void setAppRegs(ZBAppReg* appRegs, unsigned int count);	//设置应用注册信息
	void sendReceiveTimeout(unsigned int timeout);	//设置接收数据包超时时间，单位为ms
	void init();
	void start();
	bool isDataComing();
	void receive(ZBPacketReceive& packet);
	void send(ZBPacketSend& packet);

private:
	unsigned int receiveTimeout;
	ZBCfg cfg;
	ZBAppReg* appRegs;
	unsigned int appRegCount;
	unsigned char calCrc(unsigned char beginValue, unsigned char *pMsg, unsigned char len);
	int readByte();
};

#endif