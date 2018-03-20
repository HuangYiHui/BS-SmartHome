#include "SmartHomeSystem.h"

SmartHomeSystem::SmartHomeSystem()
{
	zigbee = new ZigbeeDevice (DEVICE_ID_IN_ZIGBEE);
	dht11 = new DHT11Device (DEVICE_ID_IN_DHT11, PIN_DHT11_DATA);
	temperatureSensor = new TemperatureSensorDevice (DEVICE_ID_IN_TEMPERATURE_SENSOR, *dht11);
	humiditySensor = new HumiditySensorDevice (DEVICE_ID_IN_HUMIDITY_SENSOR, *dht11);
	heatSensor = new HeatSensorDevice (DEVICE_ID_IN_HEAT_SENSOR, *dht11);

	switch1 = new SimpleExecuterDevice (DEVICE_ID_SWITCH1, PIN_SWITCH1_OUT, LOGIC_LEVEL_OPEN_HIGH);
	switch2 = new SimpleExecuterDevice (DEVICE_ID_SWITCH2, PIN_SWITCH2_OUT, LOGIC_LEVEL_OPEN_HIGH);
	switch3 = new SimpleExecuterDevice (DEVICE_ID_SWITCH3, PIN_SWITCH3_OUT, LOGIC_LEVEL_OPEN_HIGH);
	switch4 =new SimpleExecuterDevice (DEVICE_ID_SWITCH4, PIN_SWITCH4_OUT, LOGIC_LEVEL_OPEN_HIGH);

	alarm = new SimpleExecuterDevice (DEVICE_ID_ALARM, PIN_ALARM_OUT, LOGIC_LEVEL_OPEN_HIGH);
	mq2 = new SimpleSensorDevice (DEVICE_ID_HARMFUL_GAS_SENSOR, PIN_MQ2_DO, SENSOR_READ_MODE_ANALOG);
	fireSensor =new SimpleSensorDevice (DEVICE_ID_FIRE_SENSOR, PIN_FIRE_SENSOR_DO, SENSOR_READ_MODE_DIGITAL);
	lcd = new LCDDevice (DEVICE_ID_LCD, PIN_NOKIA5110_RST, PIN_NOKIA5110_CE, PIN_NOKIA5110_DC, PIN_NOKIA5110_DIN, PIN_NOKIA5110_CLK);
	irRemote = new IRRemoteDevice (DEVICE_ID_IR_REMOTE, PIN_IR_REMOTE_OUT);
}

SmartHomeSystem::~SmartHomeSystem()
{
	delete zigbee;
	delete dht11;
	delete temperatureSensor;
	delete humiditySensor;
	delete heatSensor;
	delete switch1;
	delete switch2;
	delete switch3;
	delete switch4;
	delete alarm;
	delete mq2;
	delete fireSensor;
	delete lcd;
	delete irRemote;
}

void SmartHomeSystem::init()
{
	Serial.begin(SERAIL_BAUD_RATE);

	ZigbeeApp* zigbeeApp = new ZigbeeApp(APP_ID_ZIGBEE, *zigbee);
	SensorApp* sensorApp = new SensorApp(APP_ID_SENSOR);
	sensorApp->addSensorTask(temperatureSensor, 3000, true);
	sensorApp->addSensorTask(humiditySensor, 3000, true);
	sensorApp->addSensorTask(heatSensor, 3000, true);
	SimpleExecuterApp* switchsApp = new SimpleExecuterApp(APP_ID_SWITCHS);
	switchsApp->addExecuter(switch1);
	switchsApp->addExecuter(switch2);
	switchsApp->addExecuter(switch3);
	switchsApp->addExecuter(switch4);
	DangerAlarmApp* dangerAlarmApp = new DangerAlarmApp(APP_ID_DANGER_ALARM, *fireSensor, *mq2, *alarm);
	IRRemoteApp* irRemoteApp = new IRRemoteApp(APP_ID_IRREMOTE, *irRemote);
	LCDApp* lcdApp = new LCDApp(APP_ID_LCD, *lcd);

	installApp(zigbeeApp);
	installApp(sensorApp);
	installApp(switchsApp);
	installApp(dangerAlarmApp);
	installApp(irRemoteApp);
	installApp(lcdApp);

	SampleSystem::init();

//	Serial.print("inited memory = ");
//	Serial.println(freeMemory());
}
SmartHomeSystem curSystem;
SystemAPI API(&curSystem);