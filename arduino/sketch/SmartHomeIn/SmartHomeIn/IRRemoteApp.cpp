#include "IRRemoteApp.h"

IRRemoteApp::IRRemoteApp(unsigned int appID, IRRemoteDevice& irRemote) : SampleApp(appID), irRemote(irRemote)
{
	state = APP_STATE_UNREADY;
}

void IRRemoteApp::init()
{
	irRemote.begin();
	state = APP_STATE_READY;
}

void IRRemoteApp::run()
{
	decode_results results;
	if(irRemote.decode(&results))
	{
		irRemote.resume();
		Serial.print("irRemote : ");
		Serial.println(results.value);
	}
}