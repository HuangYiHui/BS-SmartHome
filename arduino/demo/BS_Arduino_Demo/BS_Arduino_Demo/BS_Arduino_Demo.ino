/*
 Name:		BS_Arduino_Demo.ino
 Created:	2018/2/22 13:27:24
 Author:	ahui
*/

/*
��������꣬����Ŀ->����->c/c++->Ԥ������->Ԥ�����������ж���
CUR_SYSTEM_IN	- ��ʾ��ǰϵͳΪ���ڵ�
CUR_SYSTEM_OUT	- ��ʾ��ǰϵͳΪ�����
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
