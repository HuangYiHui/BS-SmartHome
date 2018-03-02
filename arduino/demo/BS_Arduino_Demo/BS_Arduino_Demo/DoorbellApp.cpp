#include "DoorbellApp.h"

//因为IRremote库与Tone库冲突，这里选择性编译
#ifndef CUR_SYSTEM_IN

DoorbellApp::DoorbellApp(unsigned int appID, TouchSensorDevice& touchSensor, SpeakerDevice& speaker) : 
	SampleApp(appID), 
	touchSensor(touchSensor), 
	speaker(speaker)
{
	state = DEVICE_STATE_CLOSED;
}

void DoorbellApp::init()
{
	touchSensor.ready();
	touchSensor.start();
	speaker.ready();
	speaker.start();

	PT_INIT(&pt);
	state = APP_STATE_READY;
}

void DoorbellApp::run()
{
	runTask();
}

int DoorbellApp::runTask()
{
	if(touchSensor.isTouching()){
		PT_INIT(&pt);
	}
	PT_BEGIN(&pt);
	while(true)
	{
		PT_WAIT_UNTIL(&pt, touchSensor.isTouching() == true);
		
		speaker.speak(262, 125);
		PT_TIMER_DELAY(&pt,162);
		speaker.noSpeak();

		speaker.speak(196, 125);
		PT_TIMER_DELAY(&pt,162);
		speaker.noSpeak();

		speaker.speak(196, 250);
		PT_TIMER_DELAY(&pt,325);
		speaker.noSpeak();

		speaker.speak(220, 250);
		PT_TIMER_DELAY(&pt,325);
		speaker.noSpeak();

		speaker.speak(196, 125);
		PT_TIMER_DELAY(&pt,162);
		speaker.noSpeak();

		PT_YIELD(&pt);
	}
	PT_END(&pt);
}

#endif