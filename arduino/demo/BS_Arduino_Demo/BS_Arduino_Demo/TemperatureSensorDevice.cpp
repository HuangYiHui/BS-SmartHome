#include "TemperatureSensorDevice.h"

TemperatureSensorDevice::TemperatureSensorDevice(DHT11Device& dht11,unsigned int sensorValueIndex) : 
	SensorDevice(sensorValueIndex),
	dht11(dht11)
{
	state = DEVICE_STATE_CLOSED;
}
	
void TemperatureSensorDevice::begin()
{
	dht11.begin();
	SensorDevice::begin();
}

float TemperatureSensorDevice::getSensorValue()
{
	return dht11.readTemperature();
}