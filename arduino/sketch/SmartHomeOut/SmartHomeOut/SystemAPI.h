#ifndef _BS_SYSTEM_API_H_
#define _BS_SYSTEM_API_H_

#include "ISystem.h"

class SystemAPI
{
public:
	SystemAPI(ISystem* curSystem);
	void sendAppMsg(AppMsg& appMsg, unsigned int appID);

private:
	ISystem* curSystem;
};

#endif