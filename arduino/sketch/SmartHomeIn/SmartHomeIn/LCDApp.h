#ifndef _BS_LCD_APP_H_
#define _BS_LCD_APP_H_

#include "SampleApp.h"
#include "LCDDevice.h"
#include "LCDAppCmd.h"
#include "pt.h"
#include "DHT11Device.h"

class LCDApp : public SampleApp
{
public:
	LCDApp(unsigned int appID, LCDDevice& lcd, DHT11Device& dht11);
	void init();
	void run();
private:
	int runUpdateInTHHTask();
	DHT11Device& dht11;
	LCDDevice& lcd;
	struct pt pt;
};

#endif