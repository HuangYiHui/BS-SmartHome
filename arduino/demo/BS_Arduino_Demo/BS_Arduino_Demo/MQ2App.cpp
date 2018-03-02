#include "MQ2App.h"

MQ2App::MQ2App(unsigned int appID, MQ2Device& mq2) : SampleApp(appID), mq2(mq2)
{
	state = APP_STATE_UNREADY;
}

void MQ2App::init()
{
	mq2.ready();
	mq2.start();

	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void MQ2App::run()
{
	runTask();
}

int MQ2App::runTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_WAIT_UNTIL(&pt, mq2.getState() == DEVICE_STATE_WORKING);
		PT_TIMER_DELAY(&pt,1000);
		Serial.println("MQ2 Working 1...");
		PT_TIMER_DELAY(&pt,1000);
		Serial.println("MQ2 Working 2...");
		PT_YIELD(&pt);
	}
	PT_END(&pt);
}