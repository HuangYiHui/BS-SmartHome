#include "LCDDevice.h"

LCDDevice::LCDDevice(unsigned char CS, unsigned char RST, unsigned char RS, unsigned char SDA, unsigned char SCK) : U8GLIB_MINI12864(SCK, SDA, CS, RS, RST)
{}

void LCDDevice::start()
{
	U8GLIB_MINI12864::begin();
}