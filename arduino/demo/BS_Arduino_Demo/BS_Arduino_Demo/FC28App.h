#ifndef _BS_FC28_APP_H_
#define _BS_FC28_APP_H_

#include "pt.h"
#include "SampleApp.h"
#include "FC28Device.h"

class FC28App : public SampleApp
{
public:
	FC28App(unsigned int appID, FC28Device& fc28);
	void init();
	void run();
private:
	int runTask();
	FC28Device& fc28;
	struct pt pt;
};
#endif