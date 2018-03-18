#include "HarmfulGasAlarmApp.h"

HarmfulGasAlarmApp::HarmfulGasAlarmApp(unsigned int appID, SimpleSensorDevice& mq2) : SampleApp(appID), mq2(mq2)
{
	state = APP_STATE_UNREADY;
}

void HarmfulGasAlarmApp::init()
{
	mq2.begin();
	state = APP_STATE_READY;
}

void HarmfulGasAlarmApp::run()
{
}
