#include "LightAdjustApp.h"

LightAdjustApp::LightAdjustApp(GY30Device& gy30, LEDDevice& led1, LEDDevice& led2) : gy30(gy30), led1(led1), led2(led2)
{
	state = DEVICE_STATE_CLOSED;
}

void LightAdjustApp::init()
{
	gy30.ready();
	gy30.start();

	led1.ready();
	led1.start();

	led2.ready();
	led2.start();

	state = APP_STATE_READY;
}

void LightAdjustApp::exeCmd()
{
	if(hasNextCommand()){
		Command command = nextCommand();
		if(command.cmd == CMD_OPEN_DEVICE){
			gy30.open();
			led1.open();
			led2.open();
		}else if(command.cmd == CMD_INIT_DEVICE){
			gy30.init();
			led1.init();
			led2.init();
		}else if(command.cmd == CMD_START_DEVICE){
			gy30.start();
			led1.start();
			led2.start();
		}else if(command.cmd == CMD_STOP_DEVICE){
			gy30.stop();
			led1.stop();
			led2.stop();
		}else if(command.cmd == CMD_CLASE_DEVICE){
			gy30.close();
			led1.close();
			led2.close();
		}
	}
}

int LightAdjustApp::exeTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_TIMER_DELAY(&pt,500);
		Serial.print("lux :");
		Serial.println(gy30.getLighteness());
		if(gy30.getState() == DEVICE_STATE_WORKING && gy30.getLighteness() < 100)
		{
			led1.light();
			led2.light();
		}
		else
		{
			led1.extinguish();
			led2.extinguish();
		}
		PT_YIELD(&pt);
	}
	PT_END(&pt);
}