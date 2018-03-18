#ifndef _BS_HEAT_SENSOR_DEVICE_H_
#define _BS_HEAT_SENSOR_DEVICE_H_

#include "SensorDevice.h"
#include "DHT11Device.h"
#include "Arduino.h"

class HeatSensorDevice : public SensorDevice
{
public:
	HeatSensorDevice(DHT11Device& dht11, unsigned int sensorValueIndex);
	void begin();
	float getSensorValue();
private:
	DHT11Device& dht11;
};

#endif