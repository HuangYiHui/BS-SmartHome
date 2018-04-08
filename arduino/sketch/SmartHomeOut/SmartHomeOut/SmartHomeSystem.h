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
#include "FC28Device.h"
#include "GY30Device.h"
#include "PM25Device.h"

#include "ZigbeeApp.h"
#include "SensorApp.h"
#include "SensorAppCmd.h"
#include "NoticeOutSensorValueApp.h"

class SmartHomeSystem : public SampleSystem
{
public:
	SmartHomeSystem();
	void init();
private:
	ZigbeeDevice zigbee;
	DHT11Device dht11;
	TemperatureSensorDevice temperatureSensor;
	HumiditySensorDevice humiditySensor;
	HeatSensorDevice heatSensor;
	FC28Device fc28;
	GY30Device gy30;
	PM25Device pm25;

	ZigbeeApp zigbeeApp;
	NoticeOutSensorValueApp noticeOutSensorValueApp;
	SensorApp sensorApp;
};

#endif