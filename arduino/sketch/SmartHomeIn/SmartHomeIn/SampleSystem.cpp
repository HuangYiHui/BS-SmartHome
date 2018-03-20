#include "SampleSystem.h"

SampleSystem::~SampleSystem()
{
	while(appList.size()>0){
		IApp* app = appList.remove(0);
		delete app;
		app = NULL;
	}
}

void SampleSystem::init()
{
	for(int i=0;i<appList.size();i++){
		(appList.get(i))->init();
	}
}

void SampleSystem::start()
{
	while(true)
	{
		for(int i=0;i<appList.size();i++){
			(appList.get(i))->run();
		//	Serial.print(appList.get(i)->getAppID(), HEX);
		//	Serial.print("run memory=");
		//	Serial.println(freeMemory());
		}
	}
}

void SampleSystem::stop()
{
	for(int i=0;i<appList.size();i++)
		(appList.get(i))->stop();
}

void SampleSystem::reset()
{
	for(int i=0;i<appList.size();i++)
		(appList.get(i))->reset();
}

void SampleSystem::installApp(IApp* app)
{
	appList.add(app);	
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