#include "System.h"

MQ2Device System :: mq2(PIN_MQ2_DO);
LCDDevice System :: lcd(PIN_NOKIA5110_RST, PIN_NOKIA5110_CE, PIN_NOKIA5110_DC, PIN_NOKIA5110_DIN, PIN_NOKIA5110_CLK);
AlarmDevice System::alarm(PIN_ALARM_OUT);
DHT11Device System::dht11(PIN_DHT11_DATA);
FireSensorDevice System::fireSensor(PIN_FIRE_SENSOR_DO);
IRRemoteDevice System::irRemote(PIN_IR_REMOTE_OUT);

System::System() : mq2App(mq2), dht11App(dht11), fireSensorApp(fireSensor), irRemoteApp(irRemote)
{}

void System::init()
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

}

void System::start()
{
	while(true)
	{
		mq2App.run();
		dht11App.run();
		fireSensorApp.run();
		irRemoteApp.run();
	}
}
void System::stop()
{
	mq2App.stop();
	dht11App.stop();
	fireSensorApp.stop();
	irRemoteApp.stop();
}

void System::reset()
{
	mq2App.reset();
	dht11App.reset();
	fireSensorApp.reset();
	irRemoteApp.reset();
}