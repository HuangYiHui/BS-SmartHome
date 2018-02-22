#include "FireSensorApp.h"

FireSensorApp::FireSensorApp(FireSensorDevice& fireSensor) : fireSensor(fireSensor)
{
	state = APP_STATE_UNREADY;
}

void FireSensorApp::init()
{
	fireSensor.ready();
	fireSensor.start();

	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void FireSensorApp::exeCmd()
{
	if(hasNextCommand()){
		Command command = nextCommand();
		if(command.cmd == CMD_OPEN_DEVICE){
			fireSensor.open();
		}else if(command.cmd == CMD_INIT_DEVICE){
			fireSensor.init();
		}else if(command.cmd == CMD_START_DEVICE){
			fireSensor.start();
		}else if(command.cmd == CMD_STOP_DEVICE){
			fireSensor.stop();
		}else if(command.cmd == CMD_CLASE_DEVICE){
			fireSensor.close();
		}
	}
}

int FireSensorApp::exeTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_WAIT_UNTIL(&pt, fireSensor.getState() == DEVICE_STATE_WORKING);
		PT_TIMER_DELAY(&pt,1000);

		if(fireSensor.hasFire()){
			Serial.println("fire!!!");
		}
		else{
			Serial.println("no fire...");
		}

		PT_YIELD(&pt);
	}
	PT_END(&pt);
}