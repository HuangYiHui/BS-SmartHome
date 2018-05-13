#include "SmartHomeSystem.h"

SmartHomeSystem::SmartHomeSystem()
		:
	zigbee(),
	dht11(PIN_DHT11_DATA),
	temperatureSensor(dht11),
	humiditySensor(dht11),
	heatSensor(dht11),
	fc28(SENSOR_ID_SOLID_HUMIDITY, PIN_FC28_IN),
	gy30(SENSOR_ID_LIGHT_INTENSITY),
	pm25(SENSOR_ID_DUST_DENSITY, PIN_PM25_LED, PIN_PM25_VO),

	zigbeeApp(zigbee),
	sensorApp(),
	noticeOutSensorValueApp(dht11, pm25, gy30, fc28)
{}


void SmartHomeSystem::init()
{
	Serial.begin(SERAIL_BAUD_RATE);
	while (!Serial);

	sensorApp.addSensorTask(&temperatureSensor, 30000, true);
	sensorApp.addSensorTask(&humiditySensor, 30000, true);
	sensorApp.addSensorTask(&heatSensor, 30000, true);
	sensorApp.addSensorTask(&gy30, 60000, true);
	sensorApp.addSensorTask(&fc28, 60000, true);
	sensorApp.addSensorTask(&pm25, 60000, true);

	installApp(&zigbeeApp);
	installApp(&sensorApp);
	installApp(&noticeOutSensorValueApp);

	SampleSystem::init();

//	Serial.print("inited memory = ");
//	Serial.println(freeMemory());
}
SmartHomeSystem curSystem;
SystemAPI API(&curSystem);