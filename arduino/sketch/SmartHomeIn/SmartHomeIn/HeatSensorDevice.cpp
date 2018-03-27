#include "HeatSensorDevice.h"

HeatSensorDevice::HeatSensorDevice(unsigned int deviceID, DHT11Device& dht11) : 
	SensorDevice(deviceID),
	dht11(dht11)
{
}

float HeatSensorDevice::getSensorValue()
{
	return dht11.readHeatIndex();
}

void HeatSensorDevice::start(){
	dht11.start();
}