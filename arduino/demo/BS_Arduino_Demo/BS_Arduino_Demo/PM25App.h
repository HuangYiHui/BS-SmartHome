#ifndef _BS_PM25_APP_H_
#define _BS_PM25_APP_H_

#include "pt.h"
#include "SampleApp.h"
#include "PM25Device.h"

class PM25App : public SampleApp
{
public:
	PM25App(unsigned int appID, PM25Device& pm25);
	void init();
	void run();
private:
	int runTask();
	PM25Device& pm25;
	struct pt pt;
};
#endif