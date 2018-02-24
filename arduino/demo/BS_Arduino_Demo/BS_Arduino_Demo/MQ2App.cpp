#include "MQ2App.h"

MQ2App::MQ2App(MQ2Device& mq2) : mq2(mq2)
{
	state = APP_STATE_UNREADY;
}

void MQ2App::init()
{
	mq2.ready();
	mq2.start();

	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void MQ2App::exeCmd()
{
	if(hasNextCommand()){
		Command command = nextCommand();
		if(command.cmd == CMD_OPEN_DEVICE){
			mq2.open();
		}else if(command.cmd == CMD_INIT_DEVICE){
			mq2.init();
		}else if(command.cmd == CMD_START_DEVICE){
			mq2.start();
		}else if(command.cmd == CMD_STOP_DEVICE){
			mq2.stop();
		}else if(command.cmd == CMD_CLASE_DEVICE){
			mq2.close();
		}
	}
}

int MQ2App::exeTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_WAIT_UNTIL(&pt, mq2.getState() == DEVICE_STATE_WORKING);
		PT_TIMER_DELAY(&pt,1000);
		Serial.println("MQ2 Working 1...");
		PT_TIMER_DELAY(&pt,1000);
		Serial.println("MQ2 Working 2...");
		PT_YIELD(&pt);
	}
	PT_END(&pt);
}