#include "SystemIn.h"

//因为IRremote库与Tone库冲突，这里选择性编译
#ifdef CUR_SYSTEM_IN

MQ2Device SystemIn :: mq2(PIN_MQ2_DO);
LCDDevice SystemIn :: lcd(PIN_NOKIA5110_RST, PIN_NOKIA5110_CE, PIN_NOKIA5110_DC, PIN_NOKIA5110_DIN, PIN_NOKIA5110_CLK);
AlarmDevice SystemIn::alarm(PIN_ALARM_OUT);
DHT11Device SystemIn::dht11(PIN_DHT11_DATA);
FireSensorDevice SystemIn::fireSensor(PIN_FIRE_SENSOR_DO);
IRRemoteDevice SystemIn::irRemote(PIN_IR_REMOTE_OUT);
ZigbeeDevice SystemIn::zigbee;

SystemIn::SystemIn() : SampleSystem(SYSTEM_ADDR)
{
	/*
	installApp(new MQ2App(mq2));
	installApp(new DHT11App(dht11));
	installApp(new FireSensorApp(fireSensor));
	installApp(new IRRemoteApp(irRemote));
	installApp(new MQ2App(mq2));
*/
	zigbee.setZDType(ZB_DEVICE_TYPE_COORDINATOR);
	installApp(new ZigbeeApp(zigbee));
	

	//installApp(new Test1App());
	installApp(new Test2App());

	state = SYSTEM_STATE_UNREADY;
}

void SystemIn::init()
{
	//设备初始化
	Serial.begin(SERAIL_BAUD_RATE);
	lcd.ready();
	alarm.ready();

	SampleSystem::init();

	//其他
	//pinMode(13, OUTPUT);
	//zigbee.setZDType(ZB_DEVICE_TYPE_COORDINATOR);
	//state = SYSTEM_STATE_READY;
}

#endif