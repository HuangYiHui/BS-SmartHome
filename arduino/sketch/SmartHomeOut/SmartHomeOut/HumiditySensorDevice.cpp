#include "HumiditySensorDevice.h"

HumiditySensorDevice::HumiditySensorDevice(DHT11Device& dht11) : SensorDevice(SENSOR_ID_OUT_HUMIDITY), dht11(dht11)
{}

float HumiditySensorDevice::getSensorValue()
{
	return dht11.readHumidity();
}

void HumiditySensorDevice::start()
{
	dht11.start();
}