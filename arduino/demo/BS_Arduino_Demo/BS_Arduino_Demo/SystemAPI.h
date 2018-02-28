#ifndef _BS_SYSTEM_API_H_
#define _BS_SYSTEM_API_H_

//��ʹ��
#include "Arduino.h"

#include "ISystem.h"
#include "AppMsg.h"

class SystemAPI
{
public:
	SystemAPI(ISystem* curSystem);
	void sendAppMsg(AppMsg& appMsg, unsigned char appID);
	unsigned int getSystemID();
private:
	ISystem* curSystem;
};

#endif