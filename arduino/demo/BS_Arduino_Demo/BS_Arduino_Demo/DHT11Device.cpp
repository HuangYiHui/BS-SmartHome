#include "DHT11Device.h"

DHT11Device::DHT11Device(devicePin pin) : DHT(pin, DHT11) 
{
	state = DEVICE_STATE_CLOSED;
}

void DHT11Device::init()
{
	begin();
	state = DEVICE_STATE_READY;
}