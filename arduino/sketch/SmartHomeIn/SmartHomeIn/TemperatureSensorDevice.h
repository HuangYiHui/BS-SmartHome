#ifndef _BS_TEMPERATURE_SENSOR_DEVICE_H_
#define _BS_TEMPERATURE_SENSOR_DEVICE_H_

#include "SensorDevice.h"
#include "DHT11Device.h"

class TemperatureSensorDevice : public SensorDevice
{
public:
	TemperatureSensorDevice(unsigned int deviceID, DHT11Device& dht11);
	void start();
	float getSensorValue();
private:
	DHT11Device& dht11;
};

#endif