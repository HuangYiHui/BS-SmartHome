#ifndef _BS_SAMPLE_APP_H_
#define _BS_SAMPLE_APP_H_

#include "IApp.h"

class SampleApp : public IApp
{
public:
	SampleApp();
	virtual	void init();
	virtual	void run();
	virtual	void stop();
	virtual	void reset();
	virtual appState getState();
protected:
	appState state;
};

#endif