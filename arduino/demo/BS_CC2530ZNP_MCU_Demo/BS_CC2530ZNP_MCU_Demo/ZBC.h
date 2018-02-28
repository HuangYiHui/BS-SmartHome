#ifndef _BS_ZBC_H_
#define _BS_ZBC_H_

#include "string.h"

//zigbee设备类型
#define ZB_DEVICE_TYPE_COORDINATOR	0x00
#define ZB_DEVICE_TYPE_ROUTE		0x01
#define ZB_DEVICE_TYPE_ENDPOINT		0x02

//zigbee消息开始标识符
#define SOF 0xfe

//zigbee命令，存放原始字节zigbee命令
typedef struct ZBCmd
{
	unsigned char* cmd;
	unsigned char len;
	~ZBCmd()
	{
		delete[] cmd;
	}
}ZBCmd;

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

//zigbee命令类
//命令的定义参考zigbee协议栈中的“CC2530ZNP Interface Specification”文档
class ZBC
{
public:
	/********** SYS_RESET_REQ ************/
	//设备重启
	const static ZBCmd CMD_DEVICE_RESET;
	
	//串口bootloader重启
	const static ZBCmd CMD_BOOTLOADDER_RESET;

	/********** ZB_WRITE_CONFIGURATION -> ZCD_NV_STARTUP_OPTION ************/
	//使用上次的状态启动
	const static ZBCmd CMD_STARTUP_WITH_LAST_STATE;

	//不使用上次的状态启动，该命令会回复NV设置，采用默认配置启动
	const static ZBCmd CMD_STARTUP_WITHOUT_LAST_STATE;

	//信道设置
	static void chanlistCfg(unsigned char channel[4], ZBCmd* zbCmd);

	//网络号设置
	static void PANIDCfg(unsigned char panid[2], ZBCmd* zbCmd);

	//设置设备类型 协调器-0，路由器-1，终端-2
	static void deviceTypeCfg(unsigned char type, ZBCmd* zbCmd);

	/********** AF_REGISTER ************/
	//应用注册
	static void appRegister(ZBAppReg& reg, ZBCmd* zbCmd);

	/********** ZDO_STARTUP_FROM_APP ************/
	//启动应用，如果是协调器则建立网络，如何是路由器或终端则去连接网络
	const static struct ZBCmd CMD_STARTUP_FROM_APP;

	/********** AF_DATA_REQUEST ************/
	//数据发送
	static void packetSend(ZBPacketSend& packet, ZBCmd* zbCmd);

private:
	//设备重启
	const static unsigned char DEVICE_RESET[6];
	//串口bootloader重启
	const static unsigned char BOOTLOADDER_RESET[6];
	//使用上次的状态启动
	const static unsigned char STARTUP_WITH_LAST_STATE[8];
	//不使用上次的状态启动，该命令会回复NV设置，采用默认配置启动
	const static unsigned char STARTUP_WITHOUT_LAST_STATE[8];
	//启动应用，如果是协调器则建立网络，如何是路由器或终端则去连接网络
	const static unsigned char STARTUP_FROM_APP[6];

	//CRC校验和计算
	static unsigned char calCrc(const unsigned char *pMsg, unsigned char len);
};
#endif