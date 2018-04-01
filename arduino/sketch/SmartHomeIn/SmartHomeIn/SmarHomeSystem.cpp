#include "SmartHomeSystem.h"

SmartHomeSystem::SmartHomeSystem() : 
	lcd(PIN_LCD_CS, PIN_LCD_RST, PIN_LCD_RS, PIN_LCD_SDA, PIN_LCD_SCK),
	zigbee(),
	dht11(PIN_DHT11_DATA),
	temperatureSensor(dht11),
	humiditySensor(dht11),
	heatSensor(dht11),
	socket1(EXECUTER_ID_SOCKET1, PIN_SWITCH1_OUT, LOGIC_LEVEL_OPEN_LOW),
	socket2(EXECUTER_ID_SOCKET2, PIN_SWITCH2_OUT, LOGIC_LEVEL_OPEN_LOW),
	socket3(EXECUTER_ID_SOCKET3, PIN_SWITCH3_OUT, LOGIC_LEVEL_OPEN_LOW),
	alarm(EXECUTER_ID_ALARM, PIN_ALARM_OUT, LOGIC_LEVEL_OPEN_HIGH),
	mq2(SENSOR_ID_HARMFUL_GAS, PIN_MQ2_DO, SENSOR_READ_MODE_ANALOG),
	fireSensor(SENSOR_ID_FIRE, PIN_FIRE_SENSOR_DO, SENSOR_READ_MODE_DIGITAL),
	irRemote(PIN_IR_REMOTE_OUT),

	zigbeeApp(zigbee),
	sensorApp(),
	simpleExecuterApp(),
	dangerAlarmApp(fireSensor, mq2, alarm),
	irRemoteApp(irRemote),
	lcdApp(lcd),
	thhUpdateApp(dht11)
{
	
}

void SmartHomeSystem::init()
{
	Serial.begin(SERAIL_BAUD_RATE);
	while (!Serial);

	sensorApp.addSensorTask(&temperatureSensor, 6000, true);
	sensorApp.addSensorTask(&humiditySensor, 6000, true);
	sensorApp.addSensorTask(&heatSensor, 6000, true);
	
	simpleExecuterApp.addExecuter(&socket1);
	simpleExecuterApp.addExecuter(&socket2);
	simpleExecuterApp.addExecuter(&socket3);

	installApp(&zigbeeApp);
	installApp(&lcdApp);
	installApp(&thhUpdateApp);
	installApp(&sensorApp);

	installApp(&simpleExecuterApp);
	installApp(&dangerAlarmApp);
	installApp(&irRemoteApp);

	SampleSystem::init();

//	Serial.print(F("inited memory = "));
//	Serial.println(freeMemory());
}
SmartHomeSystem curSystem;
SystemAPI API(&curSystem);