#ifndef _BS_DHT11_DEVICE_H_
#define _BS_DHT11_DEVICE_H_

#include "IDevice.h"
#include "DHT11.h"

class DHT11Device : public SampleDevice
{
private:
	unsigned char pin;
	DHT11 dht11;
	float calcHeatIndex(float t, float h);
public:
	DHT11Device(unsigned char pin);
	float readTemperature();
	float readHumidity();
	float readHeatIndex();
	void readSensorValue(float* results);
};

#endif