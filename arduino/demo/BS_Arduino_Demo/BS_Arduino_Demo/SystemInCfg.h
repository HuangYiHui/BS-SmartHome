#ifndef _SYSTEM_IN_CFG_h_
#define _SYSTEM_IN_CFG_h_

#define SYSTEM_ADDR_IN		0x0031	//系统地址，zigbee通信时使用这个地址作为源地址
#define CUR_ZB_DEVICE_TYPE	ZB_DEVICE_TYPE_COORDINATOR	//zigbee设备类型

/*
应用ID分配
00 - 2f 保留
30 - 6f In结点
70 - af	Out结点	
b0 - ef Pi结点
f0 - ff 保留
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