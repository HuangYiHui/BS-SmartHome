#include "TemperatureSensorDevice.h"

TemperatureSensorDevice::TemperatureSensorDevice(unsigned int deviceID, DHT11Device& dht11,unsigned int sensorValueIndex) : 
	SensorDevice(deviceID, sensorValueIndex),
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