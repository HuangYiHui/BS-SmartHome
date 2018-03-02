#ifndef _BS_APP_MSG_H_
#define _BS_APP_MSG_H_

#include "Arduino.h"


//用于app消息发送
typedef struct AppMsgSend
{
	unsigned int srcAddr;
	unsigned char srcEndpoint;
	unsigned int dstAddr;
	unsigned char dstEndpoint;
	unsigned int len;
	unsigned char* data;

	AppMsgSend()
	{
		len = 0;
		data = NULL;
	}

	AppMsgSend(AppMsgSend& msg)
	{
		clone(msg);
	}

	~AppMsgSend()
	{
		delete[] data;
	}

	void clone(AppMsgSend& msg)
	{
		srcAddr = msg.srcAddr;
		srcEndpoint = msg.srcEndpoint;
		dstAddr = msg.dstAddr;
		dstEndpoint = msg.dstEndpoint;
		cloneData(msg);
	}

	void cloneData(AppMsgSend& msg)
	{
		len = msg.len;
		data = new unsigned char[len];
		
		for(unsigned int i=0;i<len;i++)
			data[i] = msg.data[i];
	}

}AppMsgSend;

//用于app消息接收
typedef struct AppMsgReceive
{
	unsigned int srcAddr;
	unsigned char srcEndpoint;
	unsigned int len;
	unsigned char* data;

	AppMsgReceive()
	{
		len = 0;
		data = NULL;
	}

	AppMsgReceive(AppMsgSend& msgSend)
	{
		srcAddr = msgSend.srcAddr;
		srcEndpoint = msgSend.srcEndpoint;
		len = msgSend.len;
		data = new unsigned char[len];
		for(unsigned int i=0;i<len;i++)
			data[i] = msgSend.data[i];
	}

	AppMsgReceive(AppMsgReceive& msg)
	{
		clone(msg);
	}

	~AppMsgReceive()
	{
		delete[] data;
	}

	void clone(AppMsgReceive& msg)
	{
		srcAddr = msg.srcAddr;
		srcEndpoint = msg.srcEndpoint;
		cloneData(msg);
	}

	void cloneData(AppMsgReceive& msg)
	{
		len = msg.len;
		data = new unsigned char[len];
		
		for(unsigned int i=0;i<len;i++)
			data[i] = msg.data[i];
	}

}AppMsgReceive;


#endif