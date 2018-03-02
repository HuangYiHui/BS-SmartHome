#ifndef _BS_DHT11_APP_H_
#define _BS_DHT11_APP_H_

#include "pt.h"
#include "SampleApp.h"
#include "DHT11Device.h"

class DHT11App : public SampleApp
{
public:
	DHT11App(unsigned int appID, DHT11Device& dht11);
	void init();
	void run();
private:
	void prcMsg();
	int runTask();
	DHT11Device& dht11;
	struct pt pt;
};
#endif