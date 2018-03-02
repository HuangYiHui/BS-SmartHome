#include "FC28App.h"

FC28App::FC28App(unsigned int appID, FC28Device& fc28) : SampleApp(appID), fc28(fc28)
{
	state = APP_STATE_UNREADY;
}

void FC28App::init()
{
	fc28.ready();
	fc28.start();
	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void FC28App::run()
{
	runTask();
}

int FC28App::runTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_WAIT_UNTIL(&pt, fc28.getState() == DEVICE_STATE_WORKING);
		PT_TIMER_DELAY(&pt,1000);
		Serial.print("solid humidity : ");
		Serial.println(fc28.getHumidity());

		PT_YIELD(&pt);
	}
	PT_END(&pt);
}