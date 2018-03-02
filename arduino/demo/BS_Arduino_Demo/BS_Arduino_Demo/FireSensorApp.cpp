#include "FireSensorApp.h"

FireSensorApp::FireSensorApp(unsigned int appID, FireSensorDevice& fireSensor) : SampleApp(appID), fireSensor(fireSensor)
{
	state = APP_STATE_UNREADY;
}

void FireSensorApp::init()
{
	fireSensor.ready();
	fireSensor.start();

	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void FireSensorApp::run()
{
	runTask();
}

int FireSensorApp::runTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_WAIT_UNTIL(&pt, fireSensor.getState() == DEVICE_STATE_WORKING);
		PT_TIMER_DELAY(&pt,1000);

		if(fireSensor.hasFire()){
			Serial.println("fire!!!");
		}
		else{
			Serial.println("no fire...");
		}

		PT_YIELD(&pt);
	}
	PT_END(&pt);
}