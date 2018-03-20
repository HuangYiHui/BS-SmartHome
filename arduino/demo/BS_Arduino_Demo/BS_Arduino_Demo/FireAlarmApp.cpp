#include "FireAlarmApp.h"

FireAlarmApp::FireAlarmApp(unsigned int appID, SimpleSensorDevice& fireSensor, SimpleExecuterDevice& alarm) 
	: 
	SampleApp(appID), 
	fireSensor(fireSensor),
	alarm(alarm)
{
	state = APP_STATE_UNREADY;
}

void FireAlarmApp::init()
{
	Serial.println("0000");
	fireSensor.begin();
	alarm.begin();
	state = APP_STATE_READY;
	Serial.println("1111");
}

void FireAlarmApp::run()
{
	Serial.println("222");
	Serial.println(fireSensor.getSensorValue());
	//сп╩П
	if(fireSensor.getSensorValue() == 0){
		alarm.openExecuter();
	}else{
		alarm.closeExecuter();
	}
}
