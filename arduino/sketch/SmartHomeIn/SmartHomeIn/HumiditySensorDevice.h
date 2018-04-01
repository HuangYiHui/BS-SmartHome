#ifndef _BS_HUMIDITY_SENSOR_DEVICE_H_
#define _BS_HUMIDITY_SENSOR_DEVICE_H_

#include "SensorDevice.h"
#include "DHT11Device.h"

class HumiditySensorDevice : public SensorDevice
{
public:
	HumiditySensorDevice(DHT11Device& dht11);
	float getSensorValue();
	void start();
private:
	DHT11Device& dht11;
};

#endif