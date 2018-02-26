#ifndef _BS_ISYSTEM_H_
#define _BS_ISYSTEM_H_

typedef unsigned char systemState;

#define SYSTEM_STATE_UNREADY	0x31
#define SYSTEM_STATE_READY		0x32
#define SYSTEM_STATE_WORKING	0x33

class ISystem
{
public:
	virtual void init() = 0;
	virtual void start() = 0;
	virtual void stop() = 0;
	virtual void reset() = 0;
	virtual systemState getState() = 0;
};
#endif