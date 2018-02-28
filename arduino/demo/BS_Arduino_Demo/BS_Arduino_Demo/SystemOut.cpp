#include "SystemOut.h"

//因为IRremote库与Tone库冲突，这里选择性编译
#ifndef CUR_SYSTEM_IN

DHT11Device SystemOut::dht11(PIN_DHT11_DATA);
TouchSensorDevice SystemOut::touchSensor(PIN_TOUCH_SENSOR_IN);
SpeakerDevice SystemOut::speaker(PIN_SPEAKER_OUT);
FC28Device SystemOut::fc28(PIN_FC28_IN);
GY30Device SystemOut::gy30;
LEDDevice SystemOut::led1(PIN_LED1_OUT);
LEDDevice SystemOut::led2(PIN_LED2_OUT);
PM25Device SystemOut::pm25(PIN_PM25_LED, PIN_PM25_VO);
ZigbeeDevice SystemOut::zigbee;

SystemOut::SystemOut() : 
	dht11App(dht11), 
	doorbellApp(touchSensor, speaker), 
	fc28App(fc28), 
	lightAdjustApp(gy30, led1, led2), 
	pm25App(pm25),
	zigbeeApp(zigbee)
{
	state = SYSTEM_STATE_UNREADY;
}

void SystemOut::init()
{
	//设备初始化
	Serial.begin(SERAIL_BAUD_RATE);

	//应用初始化
	dht11App.init();
	doorbellApp.init();
	fc28App.init();
	lightAdjustApp.init();
	pm25App.init();
	zigbeeApp.init();

	//其他
	state = SYSTEM_STATE_READY;
}

void SystemOut::start()
{
	state = SYSTEM_STATE_WORKING;
	while(true)
	{
		/*
		dht11App.run();
		doorbellApp.run();
		fc28App.run();
		lightAdjustApp.run();
		pm25App.run();*/
		zigbeeApp.run();
		//zigbee.test1();
	}
}
void SystemOut::stop()
{
	dht11App.stop();
	doorbellApp.stop();
	fc28App.stop();
	lightAdjustApp.stop();
	pm25.stop();
	zigbeeApp.stop();

	state = SYSTEM_STATE_READY;
}

void SystemOut::reset()
{
	dht11App.reset();
	doorbellApp.reset();
	fc28App.reset();
	lightAdjustApp.reset();
	pm25.reset();
	zigbeeApp.reset();

	state = SYSTEM_STATE_UNREADY;
}

#endif