#include "Test3App.h"

Test3App::Test3App(unsigned int appID) : SampleApp(appID)
{
}

void Test3App::init()
{
	PT_INIT(&pt);
	Serial.print("test3 appID: 0x");
	Serial.println(appID, HEX);
}

void Test3App::run()
{
	runTask();
}

int Test3App::runTask()
{
	PT_BEGIN(&pt);
	while(true){
		PT_TIMER_DELAY(&pt, 1000);
		Serial.println("test3 app run");
	}
	PT_END(&pt);
}