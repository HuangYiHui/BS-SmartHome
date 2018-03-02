#include "SystemAPI.h"

SystemAPI::SystemAPI(ISystem* curSystem)
{
	this->curSystem = curSystem;
}

void SystemAPI::sendAppMsg(AppMsgSend& appMsg)
{
	curSystem->sendAppMsg(appMsg);
}

unsigned int SystemAPI::getSystemID()
{
	return curSystem->getSystemID();
}

