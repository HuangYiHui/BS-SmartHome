#ifndef _BS_DHT11_DEVICE_H_
#define _BS_DHT11_DEVICE_H_

#include "SampleDevice.h"
#include "DHT11.h"

class DHT11Device : public SampleDevice
{
private:
	char pin;
	DHT11 dht11;

public:
	DHT11Device(unsigned int deviceID, devicePin pin);
	void begin();
	float readTemperature();
	float readHumidity();
	float readHeatIndex();
};

#endif