#include "SimpleExecuterDevice.h"

SimpleExecuterDevice::SimpleExecuterDevice(unsigned char executerID, unsigned char pin, unsigned char logicLevelOpen)
{
	this->executerID = executerID;
	this->pin = pin;
	this->logicLevelOpen = logicLevelOpen;
	this->isSimpleExecuterOpened = false;
}

unsigned char SimpleExecuterDevice::getExecuterID()
{
	return executerID;
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