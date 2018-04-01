#include "DHT11Device.h"

DHT11Device::DHT11Device(unsigned char pin)
{
	this->pin = pin;
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
	return calcHeatIndex(t, h);
}

float DHT11Device::calcHeatIndex(float t, float h)
{
	float hi = 1.98*t + 0.047*h +24.8;
	float powt = pow(t, 2);
	float powh = pow(h, 2);
	if (hi > 79) {
	hi = -42.379 +
		2.04901523 * t +
		10.14333127 * h +
		-0.22475541 * t*h +
		-0.00683783 * powt +
		-0.05481717 * powh +
		0.00122874 * powt * h +
		0.00085282 * t*powh +
		-0.00000199 * powt * powh;

	if((h < 13) && (t >= 80.0) && (t <= 112.0))
	hi -= ((13.0 - h) * 0.25) * sqrt((17.0 - abs(t - 95.0)) * 0.05882);

	else if((h > 85.0) && (t >= 80.0) && (t <= 87.0))
	hi += ((h - 85.0) * 0.1) * ((87.0 - t) * 0.2);
	}

	hi = (hi - 32) * 0.55555;
	return hi;
}

void DHT11Device::readSensorValue(float results[3])
{
	if(results != NULL){
		dht11.read(pin);
		results[0] = dht11.temperature;
		results[1] = dht11.humidity;
		results[2] = calcHeatIndex(results[0], results[1]);
	}
}