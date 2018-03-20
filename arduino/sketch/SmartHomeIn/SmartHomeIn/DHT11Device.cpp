#include "DHT11Device.h"

DHT11Device::DHT11Device(unsigned int deviceID, devicePin pin) : SampleDevice(deviceID)
{
	this->pin = pin;
	state = DEVICE_STATE_CLOSED;
}

void DHT11Device::begin()
{
	SampleDevice::begin();
}

float DHT11Device::readTemperature()
{
	dht11.read(pin);
	return dht11.temperature;
}

float DHT11Device::readHumidity()
{
	dht11.read(pin);
	return dht11.humidity;
}

float DHT11Device::readHeatIndex()
{
	dht11.read(pin);
	float t = dht11.temperature;
	float h = dht11.humidity;
	t = t * 1.8 + 32;
	float hi = 0.5 * (t + 61.0 + ((t - 68.0) * 1.2) + (h * 0.094));

	if (hi > 79) {
	hi = -42.379 +
		2.04901523 * t +
		10.14333127 * h +
		-0.22475541 * t*h +
		-0.00683783 * pow(t, 2) +
		-0.05481717 * pow(h, 2) +
		0.00122874 * pow(t, 2) * h +
		0.00085282 * t*pow(h, 2) +
		-0.00000199 * pow(t, 2) * pow(h, 2);

	if((h < 13) && (t >= 80.0) && (t <= 112.0))
	hi -= ((13.0 - h) * 0.25) * sqrt((17.0 - abs(t - 95.0)) * 0.05882);

	else if((h > 85.0) && (t >= 80.0) && (t <= 87.0))
	hi += ((h - 85.0) * 0.1) * ((87.0 - t) * 0.2);
	}

	hi = (hi - 32) * 0.55555;
	return hi;
}