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
#include "CurSystem.h"

void setup() {
	curSystem.init();
}
void loop() {
	curSystem.start();
	while(true);
}
