#include "HeatSensorDevice.h"

HeatSensorDevice::HeatSensorDevice(DHT11Device& dht11,unsigned int sensorValueIndex) : 
	SensorDevice(sensorValueIndex),
	dht11(dht11)
{
	state = DEVICE_STATE_CLOSED;
}
	
void HeatSensorDevice::begin()
{
	dht11.begin();
	SensorDevice::begin();
}

float HeatSensorDevice::getSensorValue()
{
	float t = dht11.readTemperature();
	float h = dht11.readTemperature();
	return dht11.computeHeatIndex(t, h, false);
}