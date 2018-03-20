#include "SimpleExecuterDevice.h"

SimpleExecuterDevice::SimpleExecuterDevice(unsigned int deviceID, devicePin pin, unsigned char logicLevelOpen) : SampleDevice(deviceID)
{
	this->pin = pin;
	this->logicLevelOpen = logicLevelOpen;
	this->isSwitchOpened = false;
	state = DEVICE_STATE_CLOSED;
}

void SimpleExecuterDevice::init()
{
	pinMode(pin, OUTPUT);
	if(logicLevelOpen == HIGH)
		digitalWrite(pin, LOW);
	else
		digitalWrite(pin, HIGH);

	this->isSwitchOpened = false;

	state = DEVICE_STATE_READY;
}

void SimpleExecuterDevice::openExecuter()
{
	digitalWrite(pin, logicLevelOpen);
	this->isSwitchOpened = true;
}

void SimpleExecuterDevice::closeExecuter()
{
	if(logicLevelOpen == HIGH)
		digitalWrite(pin, LOW);
	else
		digitalWrite(pin, HIGH);

	this->isSwitchOpened = false;
}

boolean SimpleExecuterDevice::isOpened()
{
	return this->isSwitchOpened;
}