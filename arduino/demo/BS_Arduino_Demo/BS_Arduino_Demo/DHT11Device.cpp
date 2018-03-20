#include "DHT11Device.h"

DHT11Device::DHT11Device(unsigned int deviceID, devicePin pin) : SampleDevice(deviceID), DHT(pin, DHT11) 
{
	state = DEVICE_STATE_CLOSED;
}

void DHT11Device::begin()
{
	SampleDevice::begin();
	DHT::begin();
}