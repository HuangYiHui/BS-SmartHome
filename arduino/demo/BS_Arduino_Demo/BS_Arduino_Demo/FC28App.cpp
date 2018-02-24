#include "FC28App.h"

FC28App::FC28App(FC28Device& fc28) : fc28(fc28)
{
	state = APP_STATE_UNREADY;
}

void FC28App::init()
{
	fc28.ready();
	fc28.start();
	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void FC28App::exeCmd()
{
	if(hasNextCommand()){
		Command command = nextCommand();
		if(command.cmd == CMD_OPEN_DEVICE){
			fc28.open();
		}else if(command.cmd == CMD_INIT_DEVICE){
			fc28.init();
		}else if(command.cmd == CMD_START_DEVICE){
			fc28.start();
		}else if(command.cmd == CMD_STOP_DEVICE){
			fc28.stop();
		}else if(command.cmd == CMD_CLASE_DEVICE){
			fc28.close();
		}
	}
}
	
int FC28App::exeTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_WAIT_UNTIL(&pt, fc28.getState() == DEVICE_STATE_WORKING);
		PT_TIMER_DELAY(&pt,1000);
		Serial.print("solid humidity : ");
		Serial.println(fc28.getHumidity());

		PT_YIELD(&pt);
	}
	PT_END(&pt);
}