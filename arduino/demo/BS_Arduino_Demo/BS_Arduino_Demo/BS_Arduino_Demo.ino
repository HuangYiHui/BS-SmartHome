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

#ifdef CUR_SYSTEM_IN

void setup() {

//	curSystem.installApp(&zigbeeApp);
//	curSystem.installApp(&test2App);
//	curSystem.installApp(&test3App);

	//�豸��ʼ��
	Serial.begin(SERAIL_BAUD_RATE);
	lcd.begin();
	alarm.begin();
	zigbee.setZDType(CUR_ZB_DEVICE_TYPE);

	lcd.print("lcd print...");

	curSystem.init();
}

#else

void setup() {

	curSystem.installApp(&zigbeeApp);

	temperatureApp.setUploadInterval(10000);
	curSystem.installApp(&temperatureApp);

	humidityApp.setUploadInterval(11000);
	curSystem.installApp(&humidityApp);

	heatApp.setUploadInterval(12000);
	curSystem.installApp(&heatApp);

	fc28App.setUploadInterval(13000);
	curSystem.installApp(&fc28App);	

	gy30App.setUploadInterval(14000);
	curSystem.installApp(&gy30App);
	
	pm25App.setUploadInterval(15000);
	curSystem.installApp(&pm25App);
	
	//�豸��ʼ��
	Serial.begin(SERAIL_BAUD_RATE);
	pinMode(13, OUTPUT);
	zigbee.setZDType(CUR_ZB_DEVICE_TYPE);

	curSystem.init();
}

#endif


void loop() {
	curSystem.start();
}
