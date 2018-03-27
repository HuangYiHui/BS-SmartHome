#ifndef _BS_HEAT_SENSOR_DEVICE_H_
#define _BS_HEAT_SENSOR_DEVICE_H_

#include "SensorDevice.h"
#include "DHT11Device.h"

class HeatSensorDevice : public SensorDevice
{
public:
	HeatSensorDevice(unsigned int deviceID, DHT11Device& dht11);
	void start();
	float getSensorValue();
private:
	DHT11Device& dht11;
};

#endif