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
#include "cfg.h"

#ifdef CUR_SYSTEM_IN

#include "SystemIn.h"
SystemIn systemIn;
void setup() {
	systemIn.init();
}
void loop() {
	systemIn.start();
	while(true);
}

#else

#include "SystemOut.h"
SystemOut systemOut;
void setup() {
	systemOut.init();
}
void loop() {
	systemOut.start();
	while(true);
}

#endif
