#include "SampleApp.h"

unsigned int SampleApp::appIDSeed = 0;

SampleApp::SampleApp() : appID(SampleApp::getOneAppID())
{
	state = APP_STATE_UNREADY;
}

SampleApp::~SampleApp()
{
	while(msgList.size()>0)
	{
		AppMsg* msg = msgList.remove(0);
		delete msg;
	}
}

void SampleApp::init()
{
	state = APP_STATE_READY;
}

void SampleApp::run()
{
	state = APP_STATE_WORKING;
}

void SampleApp::stop()
{
	state = APP_STATE_READY;
}

void SampleApp::reset()
{
	state = APP_STATE_UNREADY;
}

appState SampleApp::getState()
{
	return state;
}

unsigned int SampleApp::getAppID()
{
	return appID;
}

unsigned int SampleApp::getOneAppID()
{
	return ++appIDSeed;
}

void SampleApp::sendMsg(AppMsg& msg)
{
	API.sendAppMsg(msg, appID);
}

void SampleApp::receiveMsg(AppMsg& msg)
{
	msgList.add(new AppMsg(msg));
}