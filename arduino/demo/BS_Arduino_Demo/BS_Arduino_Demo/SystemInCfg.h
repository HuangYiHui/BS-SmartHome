#ifndef _SYSTEM_IN_CFG_h_
#define _SYSTEM_IN_CFG_h_

#include "cfg.h"

#define SYSTEM_ADDR_IN		0x0031	//系统地址，zigbee通信时使用这个地址作为源地址
#define CUR_ZB_DEVICE_TYPE	ZB_DEVICE_TYPE_COORDINATOR	//zigbee设备类型

#define ZIGBEE_APP_ID			0x31
#define MQ2_APP_ID				0x32
#define DHT11_APP_ID			0x33
#define FIRESENSOR_APP_ID		0x34
#define IRREMOTE_APP_ID			0x35

#define TEST1_APP_ID			0xf1
#define TEST2_APP_ID			0x78
#define TEST3_APP_ID			0xf3

#endif