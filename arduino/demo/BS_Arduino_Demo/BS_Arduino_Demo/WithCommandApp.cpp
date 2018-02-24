#include "WithCommandApp.h"

void WithCommandApp::run()
{
	state = APP_STATE_WORKING;
	exeCmd();
	exeTask();
}

void WithCommandApp::addCommand(Command command)
{
	commandList.add(command);
}

bool WithCommandApp::hasNextCommand()
{
	if(commandList.size() > 0)
		return true;
	else 
		return false;
}

Command WithCommandApp::nextCommand()
{
	return commandList.remove(0);
}

void WithCommandApp::exeCmd()
{}


int WithCommandApp::exeTask()
{

/*
按pt.h中定义
#define PT_WAITING 0
#define PT_EXITED  1
#define PT_ENDED   2
#define PT_YIELDED 3
*/
	return 2;
}