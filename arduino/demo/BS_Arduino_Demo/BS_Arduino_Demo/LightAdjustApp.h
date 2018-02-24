#ifndef _BS_LIGHT_ADJUST_APP_H_
#define _BS_LIGHT_ADJUST_APP_H_

#include "pt.h"
#include "WithCommandApp.h"
#include "GY30Device.h"
#include "LEDDevice.h"

class LightAdjustApp : public WithCommandApp
{
public:
	LightAdjustApp(GY30Device& gy30, LEDDevice& led1, LEDDevice& led2);
	void init();
private:
	void exeCmd();
	int exeTask();
	GY30Device& gy30;
	LEDDevice& led1;
	LEDDevice& led2;
	struct pt pt;
};
#endif