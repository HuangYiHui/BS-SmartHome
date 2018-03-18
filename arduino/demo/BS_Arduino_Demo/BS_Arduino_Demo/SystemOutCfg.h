#ifndef _SYSTEM_OUT_CFG_h_
#define _SYSTEM_OUT_CFG_h_

#define SYSTEM_ADDR_OUT 0x0032
#define CUR_ZB_DEVICE_TYPE	ZB_DEVICE_TYPE_ROUTE

/*
Ӧ��ID����
00 - 2f ����
30 - 6f In���
70 - af	Out���	
b0 - ef Pi���
f0 - ff ����
*/
#define APP_ID_ZIGBEE			0x0070
#define APP_ID_PM25				0x0071
#define APP_ID_OUT_TEMPERATURE	0x0072
#define APP_ID_OUT_HUMIDITY		0x0073
#define APP_ID_OUT_HEAT			0x0074
#define APP_ID_FC28				0x0075
#define APP_ID_GY30				0x0078

#define APP_ID_TEST1			0x00f4
#define APP_ID_TEST2			0x00f1
#define APP_ID_TEST3			0x00f6


#endif