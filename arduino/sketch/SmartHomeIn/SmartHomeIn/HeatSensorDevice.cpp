#include "HeatSensorDevice.h"

HeatSensorDevice::HeatSensorDevice(DHT11Device& dht11) : SensorDevice(SENSOR_ID_IN_HEAT), dht11(dht11)
{}

float HeatSensorDevice::getSensorValue()
{
	return dht11.readHeatIndex();
}

void HeatSensorDevice::start(){
	dht11.start();
}