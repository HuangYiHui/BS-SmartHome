#ifndef _BS_SAMPLE_SYSTEM_H_
#define _BS_SAMPLE_SYSTEM_H_

#include "ISystem.h"

class SampleSystem : public ISystem
{
public:
	SampleSystem();
	virtual	void init();
	virtual	void start();
	virtual	void stop();
	virtual	void reset();
	virtual	systemState getState();
protected:
	systemState state;
};

#endif