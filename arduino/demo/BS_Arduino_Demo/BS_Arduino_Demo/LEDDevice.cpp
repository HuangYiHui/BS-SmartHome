#include "LEDDevice.h"

LEDDevice::LEDDevice(devicePin pin)
{
	this->pin = pin;
	state = DEVICE_STATE_CLOSED;
}

void LEDDevice::init()
{
	pinMode(pin, OUTPUT);
	digitalWrite(pin, LOW);
	state = DEVICE_STATE_READY;
}

void LEDDevice::light()
{
	digitalWrite(pin, HIGH);
}

void LEDDevice::extinguish()
{
	digitalWrite(pin, LOW);
}