#include "cfg.h"
//因为IRremote库与Tone库冲突，这里选择性编译
#ifndef CUR_SYSTEM_IN

#ifndef _BS_SYSTEM_OUT_H_
#define _BS_SYSTEM_OUT_H_

#include "SampleSystem.h"
#include "cfg.h"
#include "outPinDef.h"

#include "DHT11Device.h"
#include "TouchSensorDevice.h"
#include "SpeakerDevice.h"
#include "FC28Device.h"
#include "GY30Device.h"
#include "LEDDevice.h"
#include "PM25Device.h"
#include "ZigbeeDevice.h"

#include "DHT11App.h"
#include "DoorbellApp.h"
#include "FC28App.h"
#include "LightAdjustApp.h"
#include "PM25App.h"
#include "ZigbeeApp.h"

class SystemOut : public SampleSystem
{
public:
	SystemOut();
	void init();
	void start();
	void stop();
	void reset();

	//系统设备
	static DHT11Device dht11;
	static TouchSensorDevice touchSensor;
	static SpeakerDevice speaker;
	static FC28Device fc28;
	static GY30Device gy30;
	static LEDDevice led1;
	static LEDDevice led2;
	static PM25Device pm25;
	static ZigbeeDevice zigbee;
private:
	DHT11App dht11App;
	DoorbellApp doorbellApp;
	FC28App fc28App;
	LightAdjustApp lightAdjustApp;
	PM25App pm25App;
	ZigbeeApp zigbeeApp;
};

#endif
#endif