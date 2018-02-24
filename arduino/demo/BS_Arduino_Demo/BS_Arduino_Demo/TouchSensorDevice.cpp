#include "TouchSensorDevice.h"

TouchSensorDevice::TouchSensorDevice(devicePin pin)
{
	this->pin = pin;
}

void TouchSensorDevice::init()
{
	pinMode(pin, INPUT);

	state = DEVICE_STATE_READY;
}

bool TouchSensorDevice::isTouching()
{
	if(digitalRead(pin)==1)
		return true;
	else
		return false;
}