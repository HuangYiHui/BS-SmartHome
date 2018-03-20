#ifndef _BS_SIMPLE_EXECUTER_APP_H_
#define _BS_SIMPLE_EXECUTER_APP_H_

#include "SampleApp.h"
#include "SimpleExecuterDevice.h"
#include "SimpleExecuterAppCmd.h"

class SimpleExecuterApp : public SampleApp
{
public:
	SimpleExecuterApp(unsigned int appID);
	~SimpleExecuterApp();
	void addExecuter(SimpleExecuterDevice* executer);
	void init();
	void run();

private:
	LinkedList<SimpleExecuterDevice*> executerList;
};

#endif