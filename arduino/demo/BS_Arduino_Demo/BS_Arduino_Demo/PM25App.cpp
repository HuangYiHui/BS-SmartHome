#include "PM25App.h"

PM25App::PM25App(PM25Device& pm25) : pm25(pm25)
{
	state = APP_STATE_UNREADY;
}

void PM25App::init()
{
	pm25.ready();
	pm25.start();
	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void PM25App::exeCmd()
{
	if(hasNextCommand()){
		Command command = nextCommand();
		if(command.cmd == CMD_OPEN_DEVICE){
			pm25.open();
		}else if(command.cmd == CMD_INIT_DEVICE){
			pm25.init();
		}else if(command.cmd == CMD_START_DEVICE){
			pm25.start();
		}else if(command.cmd == CMD_STOP_DEVICE){
			pm25.stop();
		}else if(command.cmd == CMD_CLASE_DEVICE){
			pm25.close();
		}
	}
}
	
int PM25App::exeTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_TIMER_DELAY(&pt,1000);
		
		Serial.print("pm25 : ");
		Serial.print(pm25.getDustDensity());

		PT_YIELD(&pt);
	}
	PT_END(&pt);
}
