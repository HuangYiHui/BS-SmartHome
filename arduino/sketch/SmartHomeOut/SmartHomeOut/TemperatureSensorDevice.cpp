#include "TemperatureSensorDevice.h"

TemperatureSensorDevice::TemperatureSensorDevice(DHT11Device& dht11) : SensorDevice(SENSOR_ID_OUT_TEMPERATURE), dht11(dht11)
{}
	
void TemperatureSensorDevice::start()
{
	dht11.start();
}

float TemperatureSensorDevice::getSensorValue()
{
	return dht11.readTemperature();
}