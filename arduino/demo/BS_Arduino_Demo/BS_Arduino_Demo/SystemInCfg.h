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

#define APP_ID_ZIGBEE			0x0030
#define APP_ID_IN_TEMPERATURE	0x0031
#define APP_ID_IN_HUMIDITY		0x0032
#define APP_ID_IN_HEAT			0x0033

#define APP_ID_MQ2				0x0034
#define APP_ID_DHT11			0x0035
#define APP_ID_FIRESENSOR		0x0036
#define APP_ID_IRREMOTE			0x0037

#define APP_ID_TEST1			0x00f0
#define APP_ID_TEST2			0x00f1
#define APP_ID_TEST3			0x00f2

#endif