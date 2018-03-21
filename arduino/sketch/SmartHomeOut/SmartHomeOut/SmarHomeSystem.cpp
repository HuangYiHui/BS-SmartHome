#include "SmartHomeSystem.h"

SmartHomeSystem::SmartHomeSystem()
{
	zigbee = new ZigbeeDevice (DEVICE_ID_OUT_ZIGBEE);
	dht11 = new DHT11Device (DEVICE_ID_OUT_DHT11, PIN_DHT11_DATA);
	temperatureSensor = new TemperatureSensorDevice (DEVICE_ID_OUT_TEMPERATURE_SENSOR, *dht11);
	humiditySensor = new HumiditySensorDevice (DEVICE_ID_OUT_HUMIDITY_SENSOR, *dht11);
	heatSensor = new HeatSensorDevice (DEVICE_ID_OUT_HEAT_SENSOR, *dht11);
	fc28 = new SimpleSensorDevice(DEVICE_ID_SOLID_HUMIDITY_SENSOR, PIN_FC28_IN, SENSOR_READ_MODE_ANALOG);
	gy30 = new GY30Device(DEVICE_ID_LIGHT_INTENSITY_SENSOR);
	pm25 = new PM25Device(DEVICE_ID_DUST_DENSITY_SENSOR, PIN_PM25_LED, PIN_PM25_VO);
}

SmartHomeSystem::~SmartHomeSystem()
{
	delete zigbee;
	delete dht11;
	delete temperatureSensor;
	delete humiditySensor;
	delete heatSensor;
	delete fc28;
	delete gy30;
	delete pm25;
}

void SmartHomeSystem::init()
{
	Serial.begin(SERAIL_BAUD_RATE);

	ZigbeeApp* zigbeeApp = new ZigbeeApp(APP_ID_ZIGBEE, *zigbee);
	SensorApp* sensorApp = new SensorApp(APP_ID_SENSOR);
	sensorApp->addSensorTask(temperatureSensor, 5100, true);
	sensorApp->addSensorTask(humiditySensor, 5200, true);
	sensorApp->addSensorTask(heatSensor, 5300, true);
	sensorApp->addSensorTask(gy30, 5400, true);
	sensorApp->addSensorTask(fc28, 5500, true);
	sensorApp->addSensorTask(pm25, 5600, true);

	installApp(zigbeeApp);
	installApp(sensorApp);

	SampleSystem::init();

//	Serial.print("inited memory = ");
//	Serial.println(freeMemory());
}
SmartHomeSystem curSystem;
SystemAPI API(&curSystem);