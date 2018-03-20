#include "DangerAlarmApp.h"

DangerAlarmApp::DangerAlarmApp(unsigned int appID, SimpleSensorDevice& fireSensor, SimpleSensorDevice& harmfulGasSensor, SimpleExecuterDevice& alarm) 
	: 
	SampleApp(appID), 
	fireSensor(fireSensor),
	harmfulGasSensor(harmfulGasSensor),
	alarm(alarm)
{
	state = APP_STATE_UNREADY;
}

void DangerAlarmApp::init()
{
	fireSensor.begin();
	alarm.begin();
	state = APP_STATE_READY;
}

void DangerAlarmApp::run()
{
	//сп╩П
	if(fireSensor.getSensorValue() == 0){
		alarm.openExecuter();
	}else{
		alarm.closeExecuter();
	}
}
