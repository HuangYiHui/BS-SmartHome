/*
 Name:		BS_Arduino_Demo.ino
 Created:	2018/2/22 13:27:24
 Author:	ahui
*/

/*
条件编译宏，在项目->属性->c/c++->预处理器->预处理器定义中定义
CUR_SYSTEM_IN	- 表示当前系统为室内的
CUR_SYSTEM_OUT	- 表示当前系统为室外的
*/
#include "CurSystem.h"

#ifdef CUR_SYSTEM_IN

void setup() {

	curSystem.installApp(&zigbeeApp);
	curSystem.installApp(&test2App);
//	curSystem.installApp(&test3App);

	//设备初始化
	Serial.begin(SERAIL_BAUD_RATE);
	lcd.ready();
	lcd.start();
	alarm.ready();
	zigbee.setZDType(CUR_ZB_DEVICE_TYPE);

	lcd.print("lcd print...");

	curSystem.init();
}

#else

void setup() {

	curSystem.installApp(&zigbeeApp);
	curSystem.installApp(&test2App);

	//设备初始化
	Serial.begin(SERAIL_BAUD_RATE);
	pinMode(13, OUTPUT);
	zigbee.setZDType(CUR_ZB_DEVICE_TYPE);

	curSystem.init();
}

#endif


void loop() {
	curSystem.start();
}
