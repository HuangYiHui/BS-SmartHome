#include "IRRemoteApp.h"

IRRemoteApp::IRRemoteApp(IRRemoteDevice& irRemote) : irRemote(irRemote)
{
	this->appID = APP_ID_IRREMOTE;
}

void IRRemoteApp::init()
{
	irRemote.start();
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