#ifndef _BS_FIRE_ALARM_APP_H_
#define _BS_FIRE_ALARM_APP_H_

#include "SystemCfg.h"
#include "SampleApp.h"
#include "SimpleSensorDevice.h"
#include "SimpleExecuterDevice.h"

class FireAlarmApp : public SampleApp
{
public:
	FireAlarmApp(unsigned int appID, SimpleSensorDevice& fireSensor, SimpleExecuterDevice& alarm);
	void init();
	void run();
private:
	SimpleSensorDevice& fireSensor;
	SimpleExecuterDevice& alarm;
};
#endif