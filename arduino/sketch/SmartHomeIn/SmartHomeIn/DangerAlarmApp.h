#ifndef _BS_DANGER_ALARM_APP_H_
#define _BS_DANGER_ALARM_APP_H_

#include "SystemCfg.h"
#include "SampleApp.h"
#include "SimpleSensorDevice.h"
#include "SimpleExecuterDevice.h"

class DangerAlarmApp : public SampleApp
{
public:
	DangerAlarmApp(unsigned int appID, SimpleSensorDevice& fireSensor, SimpleSensorDevice& harmfulGasSensor, SimpleExecuterDevice& alarm);
	void init();
	void run();
private:
	SimpleSensorDevice& fireSensor;
	SimpleSensorDevice& harmfulGasSensor;
	SimpleExecuterDevice& alarm;
};
#endif