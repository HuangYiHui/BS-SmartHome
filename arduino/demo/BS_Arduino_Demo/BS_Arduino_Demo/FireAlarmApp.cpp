#include "FireAlarmApp.h"

FireAlarmApp::FireAlarmApp(unsigned int appID, SimpleSensorDevice& fireSensor) : SampleApp(appID), fireSensor(fireSensor)
{
	state = APP_STATE_UNREADY;
}

void FireAlarmApp::init()
{
	fireSensor.begin();
	state = APP_STATE_READY;
}

void FireAlarmApp::run()
{
	if(fireSensor.getSensorValue() == 1){
		Serial.println("fire");
	}else{
		Serial.println("no fire");
	}
}
