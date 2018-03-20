#ifndef _BS_SMART_HOME_SYSTEM_H_
#define _BS_SMART_HOME_SYSTEM_H_

#include "SampleSystem.h"
#include "SystemCfg.h"
#include "SystemAPI.h"

#include "ZigbeeDevice.h"
#include "SensorDevice.h"
#include "DHT11Device.h"
#include "TemperatureSensorDevice.h"
#include "HumiditySensorDevice.h"
#include "HeatSensorDevice.h"
#include "SimpleSensorDevice.h"
#include "SimpleExecuterDevice.h"
#include "LCDDevice.h"
#include "IRRemoteDevice.h"

#include "ZigbeeApp.h"
#include "SensorApp.h"
#include "SimpleExecuterApp.h"
#include "DangerAlarmApp.h"
#include "IRRemoteApp.h"
#include "LCDApp.h"
#include "SensorAppCmd.h"


class SmartHomeSystem : public SampleSystem
{
public:
	SmartHomeSystem();
	~SmartHomeSystem();
	void init();
private:
	ZigbeeDevice* zigbee;
	DHT11Device* dht11;
	TemperatureSensorDevice* temperatureSensor;
	HumiditySensorDevice* humiditySensor;
	HeatSensorDevice* heatSensor;
	SimpleExecuterDevice* switch1;
	SimpleExecuterDevice* switch2;
	SimpleExecuterDevice* switch3;
	SimpleExecuterDevice* switch4;
	SimpleExecuterDevice* alarm;
	SimpleSensorDevice* mq2;
	SimpleSensorDevice* fireSensor;
	LCDDevice* lcd;
	IRRemoteDevice* irRemote;
};

#endif