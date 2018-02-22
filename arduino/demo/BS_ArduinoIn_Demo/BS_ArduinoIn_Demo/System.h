#ifndef _BS_SYSTEM_H_
#define _BS_SYSTEM_H_

#include "cfg.h"

#include "pinDef.h"

#include "LCDDevice.h"
#include "AlarmDevice.h"
#include "MQ2Device.h"
#include "DHT11Device.h"
#include "FireSensorDevice.h"
#include "IRRemoteDevice.h"

#include "MQ2App.h"
#include "DHT11App.h"
#include "FireSensorApp.h"
#include "IRRemoteApp.h"

class System
{
public:
	System();
	void init();
	void start();
	void stop();
	void reset();

	//系统设备
	static LCDDevice lcd;
	static AlarmDevice alarm;
	static MQ2Device mq2;
	static DHT11Device dht11;
	static FireSensorDevice fireSensor;
	static IRRemoteDevice irRemote;

private:
	MQ2App mq2App;
	DHT11App dht11App;
	FireSensorApp fireSensorApp;
	IRRemoteApp irRemoteApp;
};

#endif