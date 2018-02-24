
//因为IRremote库与Tone库冲突，这里选择性编译
#ifdef CUR_SYSTEM_IN

#include "SystemIn.h"

MQ2Device SystemIn :: mq2(PIN_MQ2_DO);
LCDDevice SystemIn :: lcd(PIN_NOKIA5110_RST, PIN_NOKIA5110_CE, PIN_NOKIA5110_DC, PIN_NOKIA5110_DIN, PIN_NOKIA5110_CLK);
AlarmDevice SystemIn::alarm(PIN_ALARM_OUT);
DHT11Device SystemIn::dht11(PIN_DHT11_DATA);
FireSensorDevice SystemIn::fireSensor(PIN_FIRE_SENSOR_DO);
IRRemoteDevice SystemIn::irRemote(PIN_IR_REMOTE_OUT);

SystemIn::SystemIn() : mq2App(mq2), dht11App(dht11), fireSensorApp(fireSensor), irRemoteApp(irRemote)
{
	state = SYSTEM_STATE_UNREADY;
}

void SystemIn::init()
{
	//设备初始化
	Serial.begin(SERAIL_BAUD_RATE);
	lcd.ready();
	alarm.ready();

	//应用初始化
	mq2App.init();
	dht11App.init();
	fireSensorApp.init();
	irRemoteApp.init();

	//其他
	lcd.print("Hi there");
    lcd.println(":D");
    lcd.setCursor(0, 5);
    lcd.println("1 2 3 ...");

	state = SYSTEM_STATE_READY;
}

void SystemIn::start()
{
	state = SYSTEM_STATE_WORKING;
	while(true)
	{
		mq2App.run();
		dht11App.run();
		fireSensorApp.run();
		irRemoteApp.run();
	}
}
void SystemIn::stop()
{
	mq2App.stop();
	dht11App.stop();
	fireSensorApp.stop();
	irRemoteApp.stop();

	state = SYSTEM_STATE_READY;
}

void SystemIn::reset()
{
	mq2App.reset();
	dht11App.reset();
	fireSensorApp.reset();
	irRemoteApp.reset();

	state = SYSTEM_STATE_UNREADY;
}

#endif