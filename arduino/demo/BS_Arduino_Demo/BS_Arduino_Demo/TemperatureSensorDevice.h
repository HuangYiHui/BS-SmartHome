#ifndef _BS_TEMPERATURE_SENSOR_DEVICE_H_
#define _BS_TEMPERATURE_SENSOR_DEVICE_H_

#include "SensorDevice.h"
#include "DHT11Device.h"
#include "Arduino.h"

class TemperatureSensorDevice : public SensorDevice
{
public:
	TemperatureSensorDevice(unsigned int deviceID, DHT11Device& dht11, unsigned int sensorValueIndex);
	void begin();
	float getSensorValue();
private:
	DHT11Device& dht11;
};

#endif