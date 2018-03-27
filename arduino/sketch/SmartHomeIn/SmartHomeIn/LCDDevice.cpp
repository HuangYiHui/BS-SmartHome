#include "LCDDevice.h"

LCDDevice::LCDDevice(
	unsigned int deviceID,
	unsigned char CS,
	unsigned char RST,
	unsigned char RS,
	unsigned char SDA,
	unsigned char SCK) 
			:
	SampleDevice(deviceID),
	U8GLIB_MINI12864(SCK, SDA, CS, RS, RST)
	//SCK,SDA,CS,RS,RST
{}

void LCDDevice::printStr(unsigned int x, unsigned y, char * cs)
{
	firstPage();
	do {
	drawStr(x, y, cs);
	} while ( nextPage() );
	
}

void LCDDevice::start()
{
	U8GLIB_MINI12864::begin();
}