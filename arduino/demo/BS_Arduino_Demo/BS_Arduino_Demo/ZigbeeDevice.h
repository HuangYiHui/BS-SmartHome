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

#include "Arduino.h"
#include "ZBC.h"
#include "SampleDevice.h"
#include "LCDDevice.h"

//zigbee����
typedef struct ZBCfg
{
	unsigned char channel[4];	//�ŵ�
	unsigned char panID[2];		//�����
	unsigned char zdType;		//zigbee�豸����
	ZBCfg()
	{
		//����0x00000800�ŵ���Ĭ��Ҳ��0x00000800�ŵ�
		channel[0] = 0x00;
		channel[1] = 0x08;
		channel[2] = 0x00;
		channel[3] = 0x00;

		//����Ĭ�������Ϊ1234
		panID[0] = 0x34;
		panID[1] = 0x12;

		//����Ĭ���豸����Ϊ·����
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
	void setZDType(unsigned char zdType);	//����zigbee�豸���ͣ��豸�����ڡ��ú궨��
	void setAppRegs(ZBAppReg* appRegs, unsigned int count);	//����Ӧ��ע����Ϣ
	void sendReceiveTimeout(unsigned int timeout);	//���ý������ݰ���ʱʱ�䣬��λΪms
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