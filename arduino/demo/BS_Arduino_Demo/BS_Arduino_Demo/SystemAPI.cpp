#include "SystemAPI.h"

SystemAPI::SystemAPI(ISystem* curSystem)
{
	this->curSystem = curSystem;
}

void SystemAPI::sendAppMsg(AppMsg& appMsg, unsigned char appID)
{
	curSystem->sendAppMsg(appMsg, appID);
}

unsigned int SystemAPI::getSystemID()
{
	return curSystem->getSystemID();
}