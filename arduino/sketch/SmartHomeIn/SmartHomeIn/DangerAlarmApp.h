#ifndef _BS_DANGER_ALARM_APP_H_
#define _BS_DANGER_ALARM_APP_H_

#include "SystemCfg.h"
#include "SampleApp.h"
#include "SimpleSensorDevice.h"
#include "SimpleExecuterDevice.h"
#include "LCDAppCmd.h"
#include "DangerAlarmAppCmd.h"

class DangerAlarmApp : public SampleApp
{
public:
	DangerAlarmApp(SimpleSensorDevice& fireSensor, SimpleSensorDevice& harmfulGasSensor, SimpleExecuterDevice& alarm);
	void init();
	void run();
private:
	bool lastStateDanger;
	SimpleSensorDevice& fireSensor;
	SimpleSensorDevice& harmfulGasSensor;
	SimpleExecuterDevice& alarm;
	void noticeLCDIsDanger(bool isDanger);
	void uploadSensorValue(SimpleSensorDevice& sensor);
};
#endif