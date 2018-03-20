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

#define DEVICE_ID_ZIGBEE				0x0030
#define DEVICE_ID_IN_DHT11				0x0031
#define DEVICE_ID_IN_TEMPERATURE_SENSOR	0x0032
#define DEVICE_ID_IN_HUMIDITY_SENSOR	0x0033
#define DEVICE_ID_IN_HEAT_SENSOR		0x0034
#define DEVICE_ID_HARMFUL_GAS_SENSOR	0x0035
#define DEVICE_ID_SWITCH1			0x0036
#define DEVICE_ID_SWITCH2			0x0037
#define DEVICE_ID_SWITCH3			0x0038
#define DEVICE_ID_SWITCH4			0x0039
#define DEVICE_ID_LCD				0x003a
#define DEVICE_ID_ALARM				0x003b
#define DEVICE_ID_FIRE_SENSOR		0x003c
#define DEVICE_ID_IR_REMOTE			0x003d

#define APP_ID_ZIGBEE			0x0030
#define APP_ID_IN_TEMPERATURE	0x0031
#define APP_ID_IN_HUMIDITY		0x0032
#define APP_ID_IN_HEAT			0x0033

#define APP_ID_MQ2				0x0034
#define APP_ID_DHT11			0x0035
#define APP_ID_FIRE_ALARM		0x0036
#define APP_ID_IRREMOTE			0x0037

#define APP_ID_SWITCH1			0x0038
#define APP_ID_SWITCH2			0x0039
#define APP_ID_SWITCH3			0x003a
#define APP_ID_SWITCH4			0x003b

#define APP_ID_TEST1			0x00f0
#define APP_ID_TEST2			0x00f1
#define APP_ID_TEST3			0x00f2

#endif