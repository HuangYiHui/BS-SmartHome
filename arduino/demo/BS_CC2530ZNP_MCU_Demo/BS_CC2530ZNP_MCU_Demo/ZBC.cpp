#include "ZBC.h"

unsigned char ZBC::calcFCS(const unsigned char *pMsg, unsigned char len)
{
	unsigned char result = 0;
	while (len--)
	{
		result ^= *pMsg++;
	}
	return result;
}

const unsigned char ZBC::DEVICE_RESET[6] = {0xfe, 0x01, 0x41, 0x00, 0x00, 0x40};
const unsigned char ZBC::BOOTLOADDER_RESET[6] = {0xfe, 0x01, 0x41, 0x00, 0x01, 0x41};
const unsigned char ZBC::STARTUP_WITH_LAST_STATE[8] = {0xfe, 0x03, 0x26, 0x05, 0x03, 0x01, 0x00, 0x22};
const unsigned char ZBC::STARTUP_WITHOUT_LAST_STATE[8] = {0xfe, 0x03, 0x26, 0x05, 0x03, 0x01, 0x03, 0x21};

const struct ZBCmd ZBC::CMD_DEVICE_RESET = {(unsigned char*)DEVICE_RESET, 6 };
const struct ZBCmd ZBC::CMD_BOOTLOADDER_RESET = {(unsigned char*)BOOTLOADDER_RESET, 6};
const struct ZBCmd ZBC::CMD_STARTUP_WITH_LAST_STATE = {(unsigned char*)STARTUP_WITH_LAST_STATE, 8};
const struct ZBCmd ZBC::CMD_STARTUP_WITHOUT_LAST_STATE = {(unsigned char*)STARTUP_WITHOUT_LAST_STATE, 8};

void ZBC::chanlistCfg(unsigned char channel[4], ZBCmd* zbCmd)
{
	zbCmd->len = 11;
	zbCmd->cmd = new unsigned char[11];
	zbCmd->cmd[0] = 0xfe;
	zbCmd->cmd[1] = 0x06;
	zbCmd->cmd[2] = 0x26;
	zbCmd->cmd[3] = 0x05;
	zbCmd->cmd[4] = 0x84;
	zbCmd->cmd[5] = 0x04;
	zbCmd->cmd[6] = channel[0];
	zbCmd->cmd[7] = channel[1];
	zbCmd->cmd[8] = channel[2];
	zbCmd->cmd[9] = channel[3];
	zbCmd->cmd[10] = calcFCS(&zbCmd->cmd[1], zbCmd->len-2);
}

void ZBC::PANIDCfg(unsigned char panid[2], ZBCmd* zbCmd)
{
	zbCmd->len = 9;
	zbCmd->cmd = new unsigned char[9];
	zbCmd->cmd[0] = 0xfe;
	zbCmd->cmd[1] = 0x04;
	zbCmd->cmd[2] = 0x26;
	zbCmd->cmd[3] = 0x05;
	zbCmd->cmd[4] = 0x83;
	zbCmd->cmd[5] = 0x02;
	zbCmd->cmd[6] = panid[0];
	zbCmd->cmd[7] = panid[1];
	zbCmd->cmd[8] = calcFCS(&zbCmd->cmd[1], zbCmd->len-2);
}

void ZBC::deviceTypeCfg(unsigned char type, ZBCmd* zbCmd)
{
	zbCmd->len = 8;
	zbCmd->cmd = new unsigned char[8];
	zbCmd->cmd[0] = 0xfe;
	zbCmd->cmd[1] = 0x03;
	zbCmd->cmd[2] = 0x26;
	zbCmd->cmd[3] = 0x05;
	zbCmd->cmd[4] = 0x87;
	zbCmd->cmd[5] = 0x01;
	zbCmd->cmd[6] = type;
	zbCmd->cmd[7] = calcFCS(&zbCmd->cmd[1], zbCmd->len-2);
}

void ZBC::appRegister(ZBAppReg& reg, ZBCmd* zbCmd)
{
	zbCmd->cmd = new unsigned char[77];
	zbCmd->cmd[0] = 0xfe;
	zbCmd->cmd[1] = 0x09 + reg.appNumInClusters + reg.appNumOutClusters;
	zbCmd->cmd[2] = 0x24;
	zbCmd->cmd[3] = 0x00;
	zbCmd->cmd[4] = reg.endPoint;
	zbCmd->cmd[5] = reg.appProfID[0];
	zbCmd->cmd[6] = reg.appProfID[1];
	zbCmd->cmd[7] = reg.appDeviceID[0];
	zbCmd->cmd[8] = reg.appDeviceID[1];
	zbCmd->cmd[9] = reg.endDevVer;
	zbCmd->cmd[10] = reg.latencyReq;
	zbCmd->cmd[11] = reg.appNumInClusters;
	memcpy(&zbCmd->cmd[12], reg.appInClusterList, sizeof(unsigned char)*reg.appNumInClusters);
	unsigned char index = 12 + reg.appNumInClusters;
	zbCmd->cmd[index] = reg.appNumOutClusters;
	index++;
	memcpy(&zbCmd->cmd[index], reg.appOutClusterList, sizeof(unsigned char)*reg.appNumOutClusters);
	index = index + reg.appNumOutClusters;
	zbCmd->len = index+1;
	zbCmd->cmd[zbCmd->len-1] = calcFCS(&zbCmd->cmd[1], zbCmd->len-2);
}

const unsigned char ZBC::STARTUP_FROM_APP[6] = {0xfe, 0x01, 0x25, 0x40, 0x00, 0x64};

const struct ZBCmd ZBC::CMD_STARTUP_FROM_APP = {(unsigned char*)STARTUP_FROM_APP, 6};

void ZBC::packetSend(ZBPacketSend& packet, ZBCmd* zbCmd)
{
	zbCmd->cmd = new unsigned char[143];
	zbCmd->cmd[0] = 0xfe;
	zbCmd->cmd[1] = 10 + packet.len;
	zbCmd->cmd[2] = 0x24;
	zbCmd->cmd[3] = 0x01;
	zbCmd->cmd[4] = packet.dstAddr[0];
	zbCmd->cmd[5] = packet.dstAddr[1];
	zbCmd->cmd[6] = packet.dstEndpoint;
	zbCmd->cmd[7] = packet.srcEndpoint;
	zbCmd->cmd[8] = packet.clusterID[0];
	zbCmd->cmd[9] = packet.clusterID[1];
	zbCmd->cmd[10] = packet.transID;
	zbCmd->cmd[11] = packet.options;
	zbCmd->cmd[12] = packet.radius;
	zbCmd->cmd[13] = packet.len;
	memcpy(&zbCmd->cmd[14], packet.data, sizeof(unsigned char)*packet.len);
	zbCmd->len = 15+packet.len;
	zbCmd->cmd[zbCmd->len-1] = calcFCS(&zbCmd->cmd[1], zbCmd->len-2);
}