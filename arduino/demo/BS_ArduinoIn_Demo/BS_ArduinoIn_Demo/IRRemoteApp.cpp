#include "IRRemoteApp.h"

IRRemoteApp::IRRemoteApp(IRRemoteDevice& irRemote) : irRemote(irRemote)
{
	state = APP_STATE_UNREADY;
}

void IRRemoteApp::init()
{
	irRemote.ready();
	irRemote.start();

	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void IRRemoteApp::exeCmd()
{
	if(hasNextCommand()){
		Command command = nextCommand();
		if(command.cmd == CMD_OPEN_DEVICE){
			irRemote.open();
		}else if(command.cmd == CMD_INIT_DEVICE){
			irRemote.init();
		}else if(command.cmd == CMD_START_DEVICE){
			irRemote.start();
		}else if(command.cmd == CMD_STOP_DEVICE){
			irRemote.stop();
		}else if(command.cmd == CMD_CLASE_DEVICE){
			irRemote.close();
		}
	}
}

int IRRemoteApp::exeTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_WAIT_UNTIL(&pt, irRemote.getState() == DEVICE_STATE_WORKING);
		PT_TIMER_DELAY(&pt,1000);

		decode_results results;
		PT_WAIT_UNTIL(&pt, irRemote.decode(&results));
		Serial.print("irRemote : ");
		Serial.println(results.value);

		PT_YIELD(&pt);
	}
	PT_END(&pt);
}