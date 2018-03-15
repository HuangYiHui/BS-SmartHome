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
#define ZIGBEE_APP_ID			0x0070
#define PM25_APP_ID				0x0071
#define DHT11_APP_ID			0x0072
#define FC28_APP_ID				0x0073
#define LIGHT_ADJUST_APP_ID		0x0074
#define DOORBELL_APP_ID			0x0075

#define TEST1_APP_ID			0x00f4
#define TEST2_APP_ID			0x00f1
#define TEST3_APP_ID			0x00f6

#endif