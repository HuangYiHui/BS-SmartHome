#include "HeatSensorDevice.h"

HeatSensorDevice::HeatSensorDevice(unsigned int deviceID, DHT11Device& dht11) : 
	SensorDevice(deviceID),
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
	return dht11.readHeatIndex();
}