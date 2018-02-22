#ifndef _BS_COMMAND_H_
#define _BS_COMMAND_H_

#define CMD_NULL 0

typedef struct Command
{
	Command()
	{
		cmd = CMD_NULL;
	}
	unsigned int cmd;
} Command;

#endif