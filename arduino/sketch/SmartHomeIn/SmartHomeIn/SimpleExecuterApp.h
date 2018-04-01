#ifndef _BS_SIMPLE_EXECUTER_APP_H_
#define _BS_SIMPLE_EXECUTER_APP_H_

#include "SampleApp.h"
#include "SimpleExecuterDevice.h"
#include "SimpleExecuterAppCmd.h"
#include "LCDAppCmd.h"
#include "LinkedList.h"

class SimpleExecuterApp : public SampleApp
{
public:
	SimpleExecuterApp();
	~SimpleExecuterApp();
	void addExecuter(SimpleExecuterDevice* executer);
	void init();
	void appMsgReceivedCallback(AppMsg& msg);
	void noticeLCDSocketStateChange(SimpleExecuterDevice* executer);
private:
	LinkedList<SimpleExecuterDevice*> executerList;
};

#endif