#ifndef _SYSTEM_OUT_CFG_h_
#define _SYSTEM_OUT_CFG_h_

#include "cfg.h"

#define SYSTEM_ADDR_OUT 0x0032
#define CUR_ZB_DEVICE_TYPE	ZB_DEVICE_TYPE_ROUTE

/*
应用ID分配
00 - 2f 保留
30 - 6f In结点
70 - af	Out结点	
b0 - ef Pi结点
f0 - ff 保留
*/
#define ZIGBEE_APP_ID			0x70
#define PM25_APP_ID				0x71
#define DHT11_APP_ID			0x72
#define FC28_APP_ID				0x73
#define LIGHT_ADJUST_APP_ID		0x74
#define DOORBELL_APP_ID			0x75

#define TEST1_APP_ID			0xf4
#define TEST2_APP_ID			0xf5
#define TEST3_APP_ID			0xf6

#endif