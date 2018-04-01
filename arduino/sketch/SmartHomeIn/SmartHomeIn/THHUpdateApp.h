#ifndef _BS_THH_UPDATA_APP_H_
#define _BS_THH_UPDATA_APP_H_

#include "SampleApp.h"
#include "pt.h"
#include "DHT11Device.h"
#include "LCDAppCmd.h"

class THHUpdateApp : public SampleApp
{
private:
	DHT11Device& dht11;
	struct pt pt;
	int runUpdateTask();
	void sendToLCD(float temperature, float humidity, float heat);
public:
	THHUpdateApp(DHT11Device& dht11);
	void init();
	void run();
};

#endif