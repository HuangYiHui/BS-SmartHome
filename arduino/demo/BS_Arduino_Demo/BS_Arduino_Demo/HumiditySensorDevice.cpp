#include "HumiditySensorDevice.h"

HumiditySensorDevice::HumiditySensorDevice(unsigned int deviceID, DHT11Device& dht11,unsigned int sensorValueIndex) : 
	SensorDevice(deviceID, sensorValueIndex),
	dht11(dht11)
{
	state = DEVICE_STATE_CLOSED;
}
	
void HumiditySensorDevice::begin()
{
	dht11.begin();
	SensorDevice::begin();
}

float HumiditySensorDevice::getSensorValue()
{
	return dht11.readHumidity();
}