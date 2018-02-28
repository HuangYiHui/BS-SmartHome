#include "Test2App.h"

void Test2App::init()
{
	PT_INIT(&pt);
	Serial.print("test2 appID:");
	Serial.println(appID);
}

void Test2App::run()
{
	exeTask();
}

int Test2App::exeTask()
{
	PT_BEGIN(&pt);
	while(true){
		PT_TIMER_DELAY(&pt, 100);
		Serial.println("Test2 run...");
		
		if(msgList.size()>0){
			AppMsg* msg = msgList.remove(0);
			Serial.println("have msg");
			Serial.print("addr:");
			Serial.println(msg->addr, HEX);
			Serial.print("endpoint:");
			Serial.println(msg->endpoint, HEX);
			Serial.print("len:");
			Serial.println(msg->len, HEX);
			Serial.print("data:");
			for(unsigned int i=0;i<msg->len;i++)
			{
				Serial.print(msg->data[i], HEX);
				Serial.print(",");
			}
			delete msg;
			Serial.println();
			
		}else{
			Serial.println("no msg");
		}
		
		Serial.println();

		//PT_YIELD(&pt);
	}
	PT_END(&pt);
}