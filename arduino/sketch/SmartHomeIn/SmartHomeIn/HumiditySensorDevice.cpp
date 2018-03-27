#include "HumiditySensorDevice.h"

HumiditySensorDevice::HumiditySensorDevice(unsigned int deviceID, DHT11Device& dht11) : 
	SensorDevice(deviceID),
	dht11(dht11)
{
}

float HumiditySensorDevice::getSensorValue()
{
	return dht11.readHumidity();
}

void HumiditySensorDevice::start()
{
	dht11.start();
}