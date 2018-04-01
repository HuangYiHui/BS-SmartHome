#ifndef _BS_SAMPLE_SYSTEM_H_
#define _BS_SAMPLE_SYSTEM_H_

//µ÷Ê¹ÓÃ
#include "Arduino.h"

#include "ISystem.h"
#include "LinkedList.h"

class SampleSystem : public ISystem
{
public:
	~SampleSystem();
	virtual	void init();
	virtual	void start();
	virtual	void stop();
	virtual	void reset();
	virtual void installApp(IApp* app);
	virtual void sendAppMsg(AppMsg& msg, unsigned char appID);

protected:
	LinkedList<IApp*> appList;
};

#endif

