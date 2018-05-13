#ifndef _BS_LCD_DEVICE_H_
#define _BS_LCD_DEVICE_H_

#include "SystemCfg.h"
#include "U8glib.h"
#include "IDevice.h"

class LCDDevice : public SampleDevice, public U8GLIB_MINI12864
{
public:
	LCDDevice(
		unsigned char CS,
		unsigned char RST,
		unsigned char RS,
		unsigned char SDA,
		unsigned char SCK, 
		unsigned char ledPin);
	void brightScreen();
	void darkScreen();
	void start();
private:
	unsigned char ledPin;
};
#endif