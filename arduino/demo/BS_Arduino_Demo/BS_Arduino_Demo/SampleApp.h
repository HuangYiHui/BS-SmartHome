#ifndef _BS_SAMPLE_APP_H_
#define _BS_SAMPLE_APP_H_

#include "IApp.h"
#include "LinkedList.h"
#include "SystemAPI.h"
extern SystemAPI API;
//class IApp;
class SampleApp : public IApp
{
public:
	SampleApp();
	~SampleApp();
	virtual	void init();
	virtual	void run();
	virtual	void stop();
	virtual	void reset();
	virtual appState getState();
	virtual unsigned int getAppID();
	static unsigned int getOneAppID();	//生成一个appID,在一定程度上不会重复
	virtual void sendMsg(AppMsg& msg);
	virtual void receiveMsg(AppMsg& msg);

protected:
	appState state;
	const unsigned int appID;
	LinkedList<AppMsg*> msgList;

private:
	static unsigned int appIDSeed;
};

#endif