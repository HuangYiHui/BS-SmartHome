#include "SimpleExecuterDevice.h"

SimpleExecuterDevice::SimpleExecuterDevice(devicePin pin, unsigned char logicLevelOpen)
{
	this->pin = pin;
	this->logicLevelOpen = logicLevelOpen;
	state = DEVICE_STATE_CLOSED;
}

void SimpleExecuterDevice::init()
{
	pinMode(pin, OUTPUT);
	state = DEVICE_STATE_READY;
}

void SimpleExecuterDevice::openSwitch()
{
	digitalWrite(pin, logicLevelOpen);
}

void SimpleExecuterDevice::closeSwitch()
{
	if(logicLevelOpen == HIGH)
		digitalWrite(pin, LOW);
	else
		digitalWrite(pin, HIGH);
}