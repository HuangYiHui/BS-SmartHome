#ifndef _BS_SAMPLE_APP_H_
#define _BS_SAMPLE_APP_H_

#include "IApp.h"
#include "SystemAPI.h"
#include "SystemCfg.h"
#include "ZigbeeAppCmd.h"
#include "Tool.h"

extern SystemAPI API;

class SampleApp : public IApp
{
public:
	void setAppID(unsigned char appID);
	virtual	void init();
	virtual	void run();
	virtual	void stop();
	virtual	void reset();
	virtual unsigned char getAppID();
	virtual void appMsgReceivedCallback(AppMsg& msg);

protected:
	unsigned char appID;
	virtual void sendMsg(AppMsg& msg, unsigned char appID);
	virtual void sendMsgToZigbee(AppMsg& msg);
};

#endif