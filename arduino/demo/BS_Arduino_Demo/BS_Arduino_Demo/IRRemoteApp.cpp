#include "IRRemoteApp.h"

//因为IRremote库与Tone库冲突，这里选择性编译
#ifdef CUR_SYSTEM_IN

IRRemoteApp::IRRemoteApp(unsigned int appID, IRRemoteDevice& irRemote) : SampleApp(appID), irRemote(irRemote)
{
	state = APP_STATE_UNREADY;
}

void IRRemoteApp::init()
{
	irRemote.ready();
	irRemote.start();

	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void IRRemoteApp::run()
{
	runTask();
}

int IRRemoteApp::runTask()
{
	if(irRemote.getState() == DEVICE_STATE_WORKING)
	{
		PT_BEGIN(&pt);
		while(true)
		{
			decode_results results;
			PT_WAIT_UNTIL(&pt, irRemote.decode(&results));
			irRemote.resume();
			Serial.print("irRemote : ");
			Serial.println(results.value);

			PT_YIELD(&pt);
		}
		PT_END(&pt);
	}
	else{
		return 2;
	}
}

#endif