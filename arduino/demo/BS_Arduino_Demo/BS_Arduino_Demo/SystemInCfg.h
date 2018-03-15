#ifndef _SYSTEM_IN_CFG_h_
#define _SYSTEM_IN_CFG_h_

#define SYSTEM_ADDR_IN		0x0031	//ϵͳ��ַ��zigbeeͨ��ʱʹ�������ַ��ΪԴ��ַ
#define CUR_ZB_DEVICE_TYPE	ZB_DEVICE_TYPE_COORDINATOR	//zigbee�豸����

/*
Ӧ��ID����
00 - 2f ����
30 - 6f In���
70 - af	Out���	
b0 - ef Pi���
f0 - ff ����
*/

#define ZIGBEE_APP_ID			0x0030
#define MQ2_APP_ID				0x0031
#define DHT11_APP_ID			0x0032
#define FIRESENSOR_APP_ID		0x0033
#define IRREMOTE_APP_ID			0x0034

#define TEST1_APP_ID			0x00f0
#define TEST2_APP_ID			0x00f1
#define TEST3_APP_ID			0x00f2

#endif