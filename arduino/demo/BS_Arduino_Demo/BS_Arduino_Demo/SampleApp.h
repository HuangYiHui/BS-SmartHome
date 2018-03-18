#ifndef _BS_SAMPLE_APP_H_
#define _BS_SAMPLE_APP_H_

#include "IApp.h"
#include "LinkedList.h"
#include "SystemAPI.h"
#include "SystemCfg.h"
#include "ZigbeeAppCmd.h"
#include "Tool.h"

extern SystemAPI API;
class SampleApp : public IApp
{
public:
	SampleApp(unsigned int appID);
	~SampleApp();
	virtual	void init();
	virtual	void run();
	virtual	void stop();
	virtual	void reset();
	virtual appState getState();
	virtual unsigned int getAppID();
	virtual void receiveMsg(AppMsg& msg);

protected:
	appState state;
	const unsigned int appID;
	LinkedList<AppMsg*> msgList;
	virtual void sendMsg(AppMsg& msg, unsigned int appID);
	virtual void uploadDataByZigbee(AppMsg& msg);
};

#endif