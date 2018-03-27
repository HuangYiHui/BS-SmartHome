#ifndef _BS_LCD_DEVICE_H_
#define _BS_LCD_DEVICE_H_

#include "SystemCfg.h"
#include "U8glib.h"
#include "SampleDevice.h"

class LCDDevice : public SampleDevice, public U8GLIB_MINI12864
{
public:
	LCDDevice(
		unsigned int deviceID,
		unsigned char CS,
		unsigned char RST,
		unsigned char RS,
		unsigned char SDA,
		unsigned char SCK);
	void start();
	void printStr(unsigned int x, unsigned y, char * cs);
};
#endif