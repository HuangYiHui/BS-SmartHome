
#ifndef _BS_CURRENT_SYSTEM_H_
#define _BS_CURRENT_SYSTEM_H_

/*
条件编译宏，在项目->属性->c/c++->预处理器->预处理器定义中定义
CUR_SYSTEM_IN	- 表示当前系统为室内的
CUR_SYSTEM_OUT	- 表示当前系统为室外的
*/
#include "cfg.h"
#include "SampleSystem.h"
#include "SystemAPI.h"

#ifdef CUR_SYSTEM_IN

#include "inPinDef.h"

#include "LCDDevice.h"
#include "AlarmDevice.h"
#include "MQ2Device.h"
#include "DHT11Device.h"
#include "FireSensorDevice.h"
#include "IRRemoteDevice.h"
#include "ZigbeeDevice.h"

#include "MQ2App.h"
#include "DHT11App.h"
#include "FireSensorApp.h"
#include "IRRemoteApp.h"
#include "ZigbeeApp.h"
#include "Test1App.h"
#include "Test2App.h"
#include "Test3App.h"

#include "SystemInCfg.h"

MQ2Device mq2(PIN_MQ2_DO);
LCDDevice lcd(PIN_NOKIA5110_RST, PIN_NOKIA5110_CE, PIN_NOKIA5110_DC, PIN_NOKIA5110_DIN, PIN_NOKIA5110_CLK);
AlarmDevice alarm(PIN_ALARM_OUT);
DHT11Device dht11(PIN_DHT11_DATA);
FireSensorDevice fireSensor(PIN_FIRE_SENSOR_DO);
IRRemoteDevice irRemote(PIN_IR_REMOTE_OUT);
ZigbeeDevice zigbee;

ZigbeeApp zigbeeApp(ZIGBEE_APP_ID, zigbee);
Test2App test2App(0x78);
Test3App test3App(TEST3_APP_ID);

SampleSystem curSystem(SYSTEM_ADDR_IN);

#else

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
#include "Test2App.h"
#include "Test3App.h"

#include "SystemOutCfg.h"

DHT11Device dht11(PIN_DHT11_DATA);
TouchSensorDevice touchSensor(PIN_TOUCH_SENSOR_IN);
SpeakerDevice speaker(PIN_SPEAKER_OUT);
FC28Device fc28(PIN_FC28_IN);
GY30Device gy30;
LEDDevice led1(PIN_LED1_OUT);
LEDDevice led2(PIN_LED2_OUT);
PM25Device pm25(PIN_PM25_LED, PIN_PM25_VO);
ZigbeeDevice zigbee;

ZigbeeApp zigbeeApp(ZIGBEE_APP_ID, zigbee);
Test2App test2App(0x78);
Test3App test3App(TEST3_APP_ID);

SampleSystem curSystem(SYSTEM_ADDR_OUT);

#endif


SystemAPI API(&curSystem);

#endif
