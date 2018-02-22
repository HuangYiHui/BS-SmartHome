#include "AlarmDevice.h"

AlarmDevice::AlarmDevice(devicePin pin)
{
	this->pin = pin;
	state = DEVICE_STATE_CLOSED;
}

void AlarmDevice::init()
{
	pinMode(pin, OUTPUT);
	state = DEVICE_STATE_READY;
}

void AlarmDevice::start()
{
	digitalWrite(pin, HIGH);
	state = DEVICE_STATE_WORKING;
}

void AlarmDevice::stop()
{
	digitalWrite(pin, LOW);
	state = DEVICE_STATE_READY;
}