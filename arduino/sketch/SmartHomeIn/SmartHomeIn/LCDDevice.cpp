#include "LCDDevice.h"

LCDDevice::LCDDevice(unsigned char CS, 
					 unsigned char RST, 
					 unsigned char RS, 
					 unsigned char SDA, 
					 unsigned char SCK,
					 unsigned char ledPin) : U8GLIB_MINI12864(SCK, SDA, CS, RS, RST)
{
	this->ledPin = ledPin;
}

void LCDDevice::start()
{
	U8GLIB_MINI12864::begin();
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
}

void LCDDevice::brightScreen()
{
	digitalWrite(ledPin, HIGH);
}
void LCDDevice::darkScreen()
{
	digitalWrite(ledPin, LOW);
}