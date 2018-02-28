#ifndef _BS_ZBC_H_
#define _BS_ZBC_H_

#include "string.h"

//zigbee�豸����
#define ZB_DEVICE_TYPE_COORDINATOR	0x00
#define ZB_DEVICE_TYPE_ROUTE		0x01
#define ZB_DEVICE_TYPE_ENDPOINT		0x02

//zigbee��Ϣ��ʼ��ʶ��
#define SOF 0xfe

//zigbee������ԭʼ�ֽ�zigbee����
typedef struct ZBCmd
{
	unsigned char* cmd;
	unsigned char len;
	~ZBCmd()
	{
		delete[] cmd;
	}
}ZBCmd;

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
	}

}ZBPacketSend;

//zigbee������
//����Ķ���ο�zigbeeЭ��ջ�еġ�CC2530ZNP Interface Specification���ĵ�
class ZBC
{
public:
	/********** SYS_RESET_REQ ************/
	//�豸����
	const static ZBCmd CMD_DEVICE_RESET;
	
	//����bootloader����
	const static ZBCmd CMD_BOOTLOADDER_RESET;

	/********** ZB_WRITE_CONFIGURATION -> ZCD_NV_STARTUP_OPTION ************/
	//ʹ���ϴε�״̬����
	const static ZBCmd CMD_STARTUP_WITH_LAST_STATE;

	//��ʹ���ϴε�״̬�������������ظ�NV���ã�����Ĭ����������
	const static ZBCmd CMD_STARTUP_WITHOUT_LAST_STATE;

	//�ŵ�����
	static void chanlistCfg(unsigned char channel[4], ZBCmd* zbCmd);

	//���������
	static void PANIDCfg(unsigned char panid[2], ZBCmd* zbCmd);

	//�����豸���� Э����-0��·����-1���ն�-2
	static void deviceTypeCfg(unsigned char type, ZBCmd* zbCmd);

	/********** AF_REGISTER ************/
	//Ӧ��ע��
	static void appRegister(ZBAppReg& reg, ZBCmd* zbCmd);

	/********** ZDO_STARTUP_FROM_APP ************/
	//����Ӧ�ã������Э�����������磬�����·�������ն���ȥ��������
	const static struct ZBCmd CMD_STARTUP_FROM_APP;

	/********** AF_DATA_REQUEST ************/
	//���ݷ���
	static void packetSend(ZBPacketSend& packet, ZBCmd* zbCmd);

private:
	//�豸����
	const static unsigned char DEVICE_RESET[6];
	//����bootloader����
	const static unsigned char BOOTLOADDER_RESET[6];
	//ʹ���ϴε�״̬����
	const static unsigned char STARTUP_WITH_LAST_STATE[8];
	//��ʹ���ϴε�״̬�������������ظ�NV���ã�����Ĭ����������
	const static unsigned char STARTUP_WITHOUT_LAST_STATE[8];
	//����Ӧ�ã������Э�����������磬�����·�������ն���ȥ��������
	const static unsigned char STARTUP_FROM_APP[6];

	//CRCУ��ͼ���
	static unsigned char calCrc(const unsigned char *pMsg, unsigned char len);
};
#endif