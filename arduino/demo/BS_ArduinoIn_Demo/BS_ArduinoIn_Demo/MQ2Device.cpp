#include "MQ2Device.h"

MQ2Device::MQ2Device(devicePin pin)
{
	this->pin = pin;
	state = DEVICE_STATE_CLOSED;
}

void MQ2Device::init()
{
	pinMode(pin, INPUT);
	state = DEVICE_STATE_READY;
}
