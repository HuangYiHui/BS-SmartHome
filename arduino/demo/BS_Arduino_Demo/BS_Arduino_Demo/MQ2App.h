#ifndef _BS_MQ2_APP_H_
#define _BS_MQ2_APP_H_

#include "SystemCfg.h"
#include "SampleApp.h"
#include "pt.h"
#include "MQ2Device.h"

class MQ2App : public SampleApp
{
public:
	MQ2App(unsigned int appID, MQ2Device& mq2);
	void init();
	void run();
private:
	int runTask();
	MQ2Device& mq2;
	struct pt pt;
};

#endif