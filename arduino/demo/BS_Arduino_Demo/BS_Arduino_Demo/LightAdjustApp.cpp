#include "LightAdjustApp.h"

LightAdjustApp::LightAdjustApp(unsigned int appID, GY30Device& gy30, LEDDevice& led1, LEDDevice& led2) : 
	SampleApp(appID), 
	gy30(gy30), 
	led1(led1), 
	led2(led2)
{
	state = DEVICE_STATE_CLOSED;
}

void LightAdjustApp::init()
{
	gy30.begin();

	led1.begin();

	led2.begin();

	state = APP_STATE_READY;
}

void LightAdjustApp::run()
{
	runTask();
}

int LightAdjustApp::runTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_TIMER_DELAY(&pt,500);
		Serial.print("lux :");
		Serial.println(gy30.getSensorValue());
		if(gy30.getState() == DEVICE_STATE_WORKING && gy30.getSensorValue() < 100)
		{
			led1.light();
			led2.light();
		}
		else
		{
			led1.extinguish();
			led2.extinguish();
		}
		PT_YIELD(&pt);
	}
	PT_END(&pt);
}