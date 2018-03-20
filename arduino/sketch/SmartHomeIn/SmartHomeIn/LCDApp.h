#ifndef _BS_LCD_APP_H_
#define _BS_LCD_APP_H_

#include "SampleApp.h"
#include "LCDDevice.h"

class LCDApp : public SampleApp
{
public:
	LCDApp(unsigned int appID, LCDDevice& lcd);
	void init();
	void run();
private:
	LCDDevice& lcd;
};

#endif