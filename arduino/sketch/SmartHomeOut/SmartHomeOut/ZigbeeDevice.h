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

#include "SampleDevice.h"

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

//应用注册信息结构体
typedef struct ZBAppReg
{
	unsigned char endPoint;
	unsigned char appProfID[2];
	unsigned char appDeviceID[2];
	unsigned char endDevVer;
	unsigned char latencyReq;
	unsigned char appNumInClusters;
	unsigned char appInClusterList[32];
	unsigned char appNumOutClusters;
	unsigned char appOutClusterList[32];
	ZBAppReg()
	{
		endPoint = 0x01;
		appProfID[0] = 0x00;
		appProfID[1] = 0x00;
		appDeviceID[0] = 0x00;
		appDeviceID[0] = 0x00;
		endDevVer = 0x00;
		latencyReq = 0x00;
		appNumInClusters = 0x00;
		appNumOutClusters = 0x00;
	}

	void clone(ZBAppReg& ar)
	{
		endPoint = ar.endPoint;
		appProfID[0] = ar.appProfID[0];
		appProfID[1] = ar.appProfID[1];
		appDeviceID[0] = ar.appDeviceID[0];
		appDeviceID[1] = ar.appDeviceID[1];
		endDevVer = ar.endDevVer;
		latencyReq = ar.latencyReq;
		appNumInClusters = ar.appNumInClusters;
		for(unsigned char i=0;i<32;i++)
			appInClusterList[i] = ar.appInClusterList[i];
		appNumOutClusters = ar.appNumOutClusters;
		for(unsigned char i=0;i<32;i++)
			appOutClusterList[i] = ar.appOutClusterList[i];
	}
}ZBAppReg;

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


class ZigbeeDevice : public SampleDevice
{
private:
	int readByte();
	unsigned char calCrc(const unsigned char *pMsg, unsigned char len);
	void getPacketSendBytes(ZBPacketSend& packet, unsigned char* bs);

public:
	ZigbeeDevice(unsigned int deviceID);
	void init();
	void start();
	bool isDataComing();
	void receive(ZBPacketReceive& packet);
	void send(ZBPacketSend& packet);

};

#endif