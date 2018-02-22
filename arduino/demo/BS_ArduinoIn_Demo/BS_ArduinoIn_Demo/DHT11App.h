#ifndef _BS_DHT11_APP_H_
#define _BS_DHT11_APP_H_

#include "pt.h"
#include "WithCommandApp.h"
#include "DHT11Device.h"

class DHT11App : public WithCommandApp
{
public:
	DHT11App(DHT11Device& dht11);
	void init();
private:
	void exeCmd();
	int exeTask();
	DHT11Device& dht11;
	struct pt pt;
};
#endif