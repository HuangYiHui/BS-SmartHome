#include "DoorbellApp.h"

DoorbellApp::DoorbellApp(TouchSensorDevice& touchSensor, SpeakerDevice& speaker) : touchSensor(touchSensor), speaker(speaker)
{
	state = DEVICE_STATE_CLOSED;
}

void DoorbellApp::init()
{
	touchSensor.ready();
	touchSensor.start();
	speaker.ready();
	speaker.start();

	PT_INIT(&pt);
	state = APP_STATE_READY;
}

void DoorbellApp::exeCmd()
{
	if(hasNextCommand()){
		Command command = nextCommand();
		if(command.cmd == CMD_OPEN_DEVICE){
			touchSensor.open();
			speaker.open();
		}else if(command.cmd == CMD_INIT_DEVICE){
			touchSensor.init();
			speaker.init();
		}else if(command.cmd == CMD_START_DEVICE){
			touchSensor.start();
			speaker.start();
		}else if(command.cmd == CMD_STOP_DEVICE){
			touchSensor.stop();
			speaker.stop();
		}else if(command.cmd == CMD_CLASE_DEVICE){
			touchSensor.close();
			speaker.close();
		}
	}
}
	
int DoorbellApp::exeTask()
{
	if(touchSensor.isTouching()){
		PT_INIT(&pt);
	}
	PT_BEGIN(&pt);
	while(true)
	{
		PT_WAIT_UNTIL(&pt, touchSensor.isTouching() == true);
		
		speaker.speak(262, 125);
		PT_TIMER_DELAY(&pt,162);
		speaker.noSpeak();

		speaker.speak(196, 125);
		PT_TIMER_DELAY(&pt,162);
		speaker.noSpeak();

		speaker.speak(196, 250);
		PT_TIMER_DELAY(&pt,325);
		speaker.noSpeak();

		speaker.speak(220, 250);
		PT_TIMER_DELAY(&pt,325);
		speaker.noSpeak();

		speaker.speak(196, 125);
		PT_TIMER_DELAY(&pt,162);
		speaker.noSpeak();

		PT_YIELD(&pt);
	}
	PT_END(&pt);
}