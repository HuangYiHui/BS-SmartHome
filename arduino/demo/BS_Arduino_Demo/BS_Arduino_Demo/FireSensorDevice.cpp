#include "FireSensorDevice.h"

FireSensorDevice::FireSensorDevice(devicePin pin)
{
	this->pin = pin;
	state = DEVICE_STATE_CLOSED;
}

void FireSensorDevice::init()
{
	pinMode(pin, INPUT);
	state = DEVICE_STATE_READY;
}

bool FireSensorDevice::hasFire()
{
	if(digitalRead(pin) != 0)
		return false;
	else
		return true;
}