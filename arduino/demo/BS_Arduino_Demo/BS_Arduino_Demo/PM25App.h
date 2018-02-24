#ifndef _BS_PM25_APP_H_
#define _BS_PM25_APP_H_

#include "pt.h"
#include "WithCommandApp.h"
#include "PM25Device.h"

class PM25App : public WithCommandApp
{
public:
	PM25App(PM25Device& pm25);
	void init();
private:
	void exeCmd();
	int exeTask();
	PM25Device& pm25;
	struct pt pt;
};
#endif