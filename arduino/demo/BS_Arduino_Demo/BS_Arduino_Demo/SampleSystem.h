#ifndef _BS_SAMPLE_SYSTEM_H_
#define _BS_SAMPLE_SYSTEM_H_

//µ÷Ê¹ÓÃ
#include "Arduino.h"

#include "ISystem.h"
#include "LinkedList.h"

class SampleSystem : public ISystem
{
public:
	SampleSystem(unsigned int systemID);
	~SampleSystem();
	virtual	void init();
	virtual	void start();
	virtual	void stop();
	virtual	void reset();
	virtual unsigned int getSystemID();
	virtual	systemState getState();
	virtual void installApp(IApp* app);
	virtual void unInstallApp(unsigned int appID);
	virtual void sendAppMsg(AppMsg& msg, unsigned int appID);

protected:
	systemState state;
	LinkedList<IApp*> appList;

private:
	const unsigned int systemID;
};

#endif

/*
dstAddr
dstEndpoint
len
data

srcAddr
srcEndpoint
len
data
*/

