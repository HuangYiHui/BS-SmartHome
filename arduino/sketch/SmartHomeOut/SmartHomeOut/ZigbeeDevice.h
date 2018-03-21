#ifndef _BS_ZIGBEE_DEVICE_H
#define _BS_ZIGBEE_DEVICE_H

/*
��ZBAppRegע�����endpoint�����ܽ��յ�Ŀ���Ƕ�Ӧendpoint������zigbee����Ϣ��������zigbee�ᶪ�������ݰ�
*/

/*
���ݸ�ʽ��SOF - lenght - cmd1 - cmd2 - data - FCS
SOFΪ��ʼ��ʶ��һ���ֽڣ��㶨Ϊ0xfe
lenght��ʾ��������data���ȣ�һ���ֽ�
cmd1��cmd2����һ���ֽ�
data��ʾ����Ϊlenght������
fcsΪlenght��cmd1��cmd2��data�����У��
*/

#include "SampleDevice.h"

#define SOF 0xfe

//��Ϣ�������ڱ�ʾzigbee���յ���ԭʼ��Ϣ��
//��lenΪ0��ʱ���ʾ���ݰ���Ч
typedef struct ZBPacketReceive
{
	unsigned char len;		//���ݳ���
	unsigned char* data;	//����
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
		//��ʼֵ��Ϊlen�ֶε�ֵ
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

//Ӧ��ע����Ϣ�ṹ��
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

//zigbee���ڷ��͵���Ϣ��
//srcEndpointһ��������ZBAppRegע�����endpoint�����ܴ����endpoint������Ϣ��ȥ������zigbee�ᶪ��������ݰ�

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