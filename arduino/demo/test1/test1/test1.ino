#include "LinkedList.h"


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

void setup() {
	Serial.begin(19200);
}

void loop() {
  // put your main code here, to run repeatedly:
	LinkedList<AppMsg*> msgList;
	msgList.add(NULL);
	Serial.println(msgList.size());
	//Serial.println(123);
}