#include "Test1App.h"

Test1App::Test1App(unsigned int appID) : SampleApp(appID)
{
	
}

void Test1App::init()
{
	PT_INIT(&pt);
	Serial.print("test1 appID:");
	Serial.println(appID);
}

void Test1App::run()
{
	exeTask();
}

int Test1App::exeTask()
{
	
	PT_BEGIN(&pt);

	while(true){
		
		PT_TIMER_DELAY(&pt,2000);
	
		
		AppMsgSend msg;
		msg.srcAddr = API.getSystemID();
		msg.dstAddr = API.getSystemID();
		msg.dstEndpoint = 0x78;
		msg.dstEndpoint = appID;
		msg.len = 3;
		msg.data = new unsigned char[3];
		msg.data[0] = 0x01;
		msg.data[1] = 0x02;
		msg.data[2] = 0x03;
		sendMsg(msg);

		Serial.println("Test1 send...");
	}
	PT_END(&pt);
	
}