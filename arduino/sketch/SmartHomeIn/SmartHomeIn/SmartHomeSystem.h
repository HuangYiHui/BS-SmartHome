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
#include "THHUpdateApp.h"

class SmartHomeSystem : public SampleSystem
{
public:
	SmartHomeSystem();
	void init();
private:
	LCDDevice lcd;
	ZigbeeDevice zigbee;
	DHT11Device dht11;
	TemperatureSensorDevice temperatureSensor;
	HumiditySensorDevice humiditySensor;
	HeatSensorDevice heatSensor;
	SimpleExecuterDevice socket1;
	SimpleExecuterDevice socket2;
	SimpleExecuterDevice socket3;
	SimpleExecuterDevice alarm;
	SimpleSensorDevice mq2;
	SimpleSensorDevice fireSensor;
	IRRemoteDevice irRemote;
	
	ZigbeeApp zigbeeApp;
	LCDApp lcdApp;
	SensorApp sensorApp;
	SimpleExecuterApp simpleExecuterApp;
	DangerAlarmApp dangerAlarmApp;
	IRRemoteApp irRemoteApp;
	THHUpdateApp thhUpdateApp;
};

#endif