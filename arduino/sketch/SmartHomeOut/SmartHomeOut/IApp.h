#ifndef _BS_IAPP_H_
#define _BS_IAPP_H_

#include "Arduino.h"

//用于app消息发送
typedef struct AppMsg
{
	unsigned int len;
	unsigned char* data;

	AppMsg()
	{
		len = 0;
		data = NULL;
	}

	~AppMsg()
	{
		delete[] data;
	}

}AppMsg;

//应用层接口
class IApp
{
public:
	virtual void init() = 0;
	virtual void run() = 0;
	virtual void stop() = 0;
	virtual void reset() = 0;
	virtual unsigned char getAppID() = 0;
	virtual void appMsgReceivedCallback(AppMsg& msg) = 0;
};


#endif