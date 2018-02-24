#include "FC28Device.h"

FC28Device::FC28Device(devicePin pin)
{
	this->pin = pin;
	state = DEVICE_STATE_CLOSED;
}

void FC28Device::init()
{
	pinMode(pin, INPUT);
	state = DEVICE_STATE_READY;
}

unsigned char FC28Device::getHumidity()
{
	return (analogRead(pin)/10.23);
}