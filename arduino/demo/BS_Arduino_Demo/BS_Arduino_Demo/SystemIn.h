#include "cfg.h"

//因为IRremote库与Tone库冲突，这里选择性编译
#ifdef CUR_SYSTEM_IN

#ifndef _BS_SYSTEM_IN_H_
#define _BS_SYSTEM_IN_H_

#include "SampleSystem.h"
#include "inPinDef.h"

#include "LCDDevice.h"
#include "AlarmDevice.h"
#include "MQ2Device.h"
#include "DHT11Device.h"
#include "FireSensorDevice.h"
#include "IRRemoteDevice.h"
#include "ZigbeeDevice.h"

/*
#include "MQ2App.h"
#include "DHT11App.h"
#include "FireSensorApp.h"
#include "IRRemoteApp.h"*/
#include "ZigbeeApp.h"


//#include "Test1App.h"
#include "Test2App.h"

class SystemIn : public SampleSystem
{
public:
	SystemIn();
	void init();

	//系统设备
	static LCDDevice lcd;
	static AlarmDevice alarm;
	static MQ2Device mq2;
	static DHT11Device dht11;
	static FireSensorDevice fireSensor;
	static IRRemoteDevice irRemote;
	static ZigbeeDevice zigbee;
};

#endif
#endif