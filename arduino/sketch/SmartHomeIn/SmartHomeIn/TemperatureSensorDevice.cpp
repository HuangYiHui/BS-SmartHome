#include "TemperatureSensorDevice.h"

TemperatureSensorDevice::TemperatureSensorDevice(unsigned int deviceID, DHT11Device& dht11) : 
	SensorDevice(deviceID),
	dht11(dht11)
{
}
	
void TemperatureSensorDevice::start()
{
	dht11.start();
}

float TemperatureSensorDevice::getSensorValue()
{
	return dht11.readTemperature();
}