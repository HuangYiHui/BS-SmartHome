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

void SampleSystem::sendAppMsg(AppMsg& msg, unsigned int appID)
{
	IApp* app = NULL;
	for(int i=0;i<appList.size();i++)
	{
		app = appList.get(i);
		if(app->getAppID() == appID){
			app->receiveMsg(msg);
		}
	}
}