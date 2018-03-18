#include "SystemAPI.h"

SystemAPI::SystemAPI(ISystem* curSystem)
{
	this->curSystem = curSystem;
}

void SystemAPI::sendAppMsg(AppMsg& appMsg, unsigned int appID)
{
	curSystem->sendAppMsg(appMsg, appID);
}

unsigned int SystemAPI::getSystemID()
{
	return curSystem->getSystemID();
}