#ifndef _BS_MQ2_APP_H_
#define _BS_MQ2_APP_H_

#include "cfg.h"
#include "WithCommandApp.h"
#include "pt.h"
#include "MQ2Device.h"

class MQ2App : public WithCommandApp
{
public:
	MQ2App(MQ2Device& mq2);
	void init();
private:
	void exeCmd();
	int exeTask();
	MQ2Device& mq2;
	struct pt pt;
};

#endif