#ifndef _BS_WITH_COMMAND_APP_H_
#define _BS_WITH_COMMAND_APP_H_

#include "SampleApp.h"
#include "LinkedList.h"
#include "Command.h"

#define CMD_OPEN_DEVICE		0x31
#define CMD_INIT_DEVICE		0x32
#define CMD_START_DEVICE	0x33
#define CMD_STOP_DEVICE		0x34
#define CMD_CLASE_DEVICE	0x35

class WithCommandApp : public SampleApp
{
public:
	void run();
	void addCommand(Command Command);
	bool hasNextCommand();
	Command nextCommand();
	
protected:	
	virtual void exeCmd();
	virtual int exeTask();
	LinkedList<Command> commandList;
	
};

#endif