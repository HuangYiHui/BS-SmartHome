#ifndef _BS_APP_MSG_H_
#define _BS_APP_MSG_H_

#include "Arduino.h"

//应用消息结构体
//app接收到的消息或发送的消息都用本结构体
//作发送时，addr表示目标地址，endpoint表示目标端点
//作接收时，addr表示源地址，endpoint表示源端点
typedef struct AppMsg
{
	unsigned int addr;
	unsigned char endpoint;
	unsigned int len;
	unsigned char* data;

	AppMsg()
	{
		len = 0;
		data = NULL;
	}

	AppMsg(AppMsg& msg)
	{
		clone(msg);
	}

	~AppMsg()
	{
		delete[] data;
	}

	void clone(AppMsg& msg)
	{
		addr = msg.addr;
		endpoint = msg.endpoint;
		cloneData(msg);
	}

	void cloneData(AppMsg& msg)
	{
		len = msg.len;
		data = new unsigned char[len];
		
		for(unsigned int i=0;i<len;i++)
			data[i] = msg.data[i];
	}

}AppMsg;

#endif