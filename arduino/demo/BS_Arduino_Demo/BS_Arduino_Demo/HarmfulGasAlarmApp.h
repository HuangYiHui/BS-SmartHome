#ifndef _BS_HARMFUL_GAS_ALARM_APP_H_
#define _BS_HARMFUL_GAS_ALARM_APP_H_

#include "SystemCfg.h"
#include "SampleApp.h"
#include "SimpleSensorDevice.h"

class HarmfulGasAlarmApp : public SampleApp
{
public:
	HarmfulGasAlarmApp(unsigned int appID, SimpleSensorDevice& mq2);
	void init();
	void run();
private:
	SimpleSensorDevice& mq2;
};

#endif