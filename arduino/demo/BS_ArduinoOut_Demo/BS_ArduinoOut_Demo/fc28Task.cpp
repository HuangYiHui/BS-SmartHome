#include "fc28Task.h"

static struct pt pt;

void initFC28Task()
{
	pinMode(PIN_FC28, INPUT);
	PT_INIT(&pt);
}

static int run()
{
	PT_BEGIN(&pt);
	while (1)
	{
		PT_TIMER_DELAY(&pt,1500);

		Serial.print("solid humidity : ");
		Serial.println(analogRead(PIN_FC28)/10.23);
	}
	PT_END(&pt);
}

void runFC28Task()
{
	run();
}