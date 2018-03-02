#include "SampleSystem.h"

SampleSystem::SampleSystem(unsigned int systemID) : systemID(systemID)
{
	state = SYSTEM_STATE_UNREADY;
}

SampleSystem::~SampleSystem()
{
	while(appList.size()>0)
		delete appList.remove(0);
}

void SampleSystem::init()
{
	for(int i=0;i<appList.size();i++)
		(appList.get(i))->init();

	state = SYSTEM_STATE_READY;
}

void SampleSystem::start()
{
	state = SYSTEM_STATE_WORKING;

	while(true)
	{
		for(int i=0;i<appList.size();i++){
			(appList.get(i))->run();
		}
	}
}

void SampleSystem::stop()
{
	for(int i=0;i<appList.size();i++)
		(appList.get(i))->stop();

	state = SYSTEM_STATE_READY;
}

void SampleSystem::reset()
{
	for(int i=0;i<appList.size();i++)
		(appList.get(i))->reset();

	state = SYSTEM_STATE_UNREADY;
}

unsigned int SampleSystem::getSystemID()
{
	return systemID;
}

systemState SampleSystem::getState()
{
	return state;
}

void SampleSystem::installApp(IApp* app)
{
	appList.add(app);	
}

void SampleSystem::unInstallApp(unsigned int appID)
{
	for(int i=0; i<appList.size(); i++)
	{
		IApp* app = appList.get(i);
		if((app->getAppID() == appID)){
			appList.remove(i);
			delete app;
		}
	}
}

void SampleSystem::sendAppMsg(AppMsgSend& msgSend)
{
	AppMsgReceive msgReceive(msgSend);
	
	//不是发到本地的信息，由zigbee发送出去
	//否则直接发送到本地app
	if(msgSend.dstAddr != systemID){
		//zigbee发送
		//Serial.println("zigbee send");
	}
	else{
		IApp* app = NULL;
		for(int i=0;i<appList.size();i++)
		{
			app = appList.get(i);
			if(app->getAppID() == msgSend.dstEndpoint){
				app->receiveMsg(msgReceive);
			}
		}
	}
	
}