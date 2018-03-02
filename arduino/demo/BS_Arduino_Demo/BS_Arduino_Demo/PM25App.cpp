#include "PM25App.h"

PM25App::PM25App(unsigned int appID, PM25Device& pm25) : SampleApp(appID), pm25(pm25)
{
	state = APP_STATE_UNREADY;
}

void PM25App::init()
{
	pm25.ready();
	pm25.start();
	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void PM25App::run()
{
	runTask();
}

int PM25App::runTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_TIMER_DELAY(&pt,1000);
		
		Serial.print("pm25 : ");
		Serial.print(pm25.getDustDensity());

		PT_YIELD(&pt);
	}
	PT_END(&pt);
}
