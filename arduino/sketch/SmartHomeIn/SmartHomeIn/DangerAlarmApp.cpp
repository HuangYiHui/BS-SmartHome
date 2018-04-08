#include "DangerAlarmApp.h"

DangerAlarmApp::DangerAlarmApp(SimpleSensorDevice& fireSensor, SimpleSensorDevice& harmfulGasSensor, SimpleExecuterDevice& alarm) 
	: 
	fireSensor(fireSensor),
	harmfulGasSensor(harmfulGasSensor),
	alarm(alarm)
{
	this->appID = APP_ID_DANGER_ALARM;
}

void DangerAlarmApp::init()
{
	fireSensor.start();
	alarm.start();
}

void DangerAlarmApp::run()
{
	//сп╩П
	if(fireSensor.getSensorValue() == 0 ||
		harmfulGasSensor.getSensorValue() > 500
	){
		Serial.println("harmfulGasValue : ");
		Serial.println(harmfulGasSensor.getSensorValue());
		alarm.openExecuter();
		Serial.println("openExecuter");
	}else{
		alarm.closeExecuter();
	}
}
