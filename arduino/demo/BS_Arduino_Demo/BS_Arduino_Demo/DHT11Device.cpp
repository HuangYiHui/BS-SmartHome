#include "DHT11Device.h"

DHT11Device::DHT11Device(devicePin pin) : DHT(pin, DHT11) 
{
	state = DEVICE_STATE_CLOSED;
}

void DHT11Device::begin()
{
	SampleDevice::begin();
	DHT::begin();
}