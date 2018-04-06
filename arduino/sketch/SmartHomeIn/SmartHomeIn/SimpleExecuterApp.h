#ifndef _BS_SIMPLE_EXECUTER_APP_H_
#define _BS_SIMPLE_EXECUTER_APP_H_

#include "SampleApp.h"
#include "SimpleExecuterDevice.h"
#include "SimpleExecuterAppCmd.h"
#include "LCDAppCmd.h"
#include "LinkedList.h"
#include "pt.h"

class SimpleExecuterApp : public SampleApp
{
public:
	SimpleExecuterApp();
	~SimpleExecuterApp();
	void addExecuter(SimpleExecuterDevice* executer);
	void init();
	void appMsgReceivedCallback(AppMsg& msg);
	void noticeLCDSocketStateChange(SimpleExecuterDevice* executer);
	void run();
	void setUploadInterval(unsigned int uploadInterval);
private:
	struct pt pt;
	unsigned int uploadInterval;
	LinkedList<SimpleExecuterDevice*> executerList;
	int runCirCularlyUploadSensorValueTask();
	void uploadExecuterValue(SimpleExecuterDevice* executer);
	SimpleExecuterDevice* findExecuter(unsigned char executerID);
};

#endif