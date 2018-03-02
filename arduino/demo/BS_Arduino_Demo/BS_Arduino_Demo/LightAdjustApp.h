#ifndef _BS_LIGHT_ADJUST_APP_H_
#define _BS_LIGHT_ADJUST_APP_H_

#include "pt.h"
#include "SampleApp.h"
#include "GY30Device.h"
#include "LEDDevice.h"

class LightAdjustApp : public SampleApp
{
public:
	LightAdjustApp(unsigned int appID, GY30Device& gy30, LEDDevice& led1, LEDDevice& led2);
	void init();
	void run();
private:
	int runTask();
	GY30Device& gy30;
	LEDDevice& led1;
	LEDDevice& led2;
	struct pt pt;
};
#endif