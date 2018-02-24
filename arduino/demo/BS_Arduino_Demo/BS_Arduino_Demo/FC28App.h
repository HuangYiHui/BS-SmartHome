#ifndef _BS_FC28_APP_H_
#define _BS_FC28_APP_H_

#include "pt.h"
#include "WithCommandApp.h"
#include "FC28Device.h"

class FC28App : public WithCommandApp
{
public:
	FC28App(FC28Device& fc28);
	void init();
private:
	void exeCmd();
	int exeTask();
	FC28Device& fc28;
	struct pt pt;
};
#endif