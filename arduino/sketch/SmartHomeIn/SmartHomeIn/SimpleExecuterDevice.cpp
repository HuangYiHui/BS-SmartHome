#include "SimpleExecuterDevice.h"

SimpleExecuterDevice::SimpleExecuterDevice(unsigned int deviceID, devicePin pin, unsigned char logicLevelOpen) : SampleDevice(deviceID)
{
	this->pin = pin;
	this->logicLevelOpen = logicLevelOpen;
	this->isSimpleExecuterOpened = false;
}

void SimpleExecuterDevice::start()
{
	pinMode(pin, OUTPUT);
	if(logicLevelOpen == HIGH)
		digitalWrite(pin, LOW);
	else
		digitalWrite(pin, HIGH);

	this->isSimpleExecuterOpened = false;
}

void SimpleExecuterDevice::openExecuter()
{
	digitalWrite(pin, logicLevelOpen);
	this->isSimpleExecuterOpened = true;
}

void SimpleExecuterDevice::closeExecuter()
{
	if(logicLevelOpen == HIGH)
		digitalWrite(pin, LOW);
	else
		digitalWrite(pin, HIGH);

	this->isSimpleExecuterOpened = false;
}

boolean SimpleExecuterDevice::isOpened()
{
	return this->isSimpleExecuterOpened;
}