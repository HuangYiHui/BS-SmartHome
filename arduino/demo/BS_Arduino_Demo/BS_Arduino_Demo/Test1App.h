#ifndef _BS_TEST1_APP_H_
#define _BS_TEST1_APP_H_

#include "Arduino.h"
#include "SampleApp.h"
#include "pt.h"

class Test1App : public SampleApp
{
public:
	void init();
	void run();
private:
	int exeTask();
	struct pt pt;
};

#endif