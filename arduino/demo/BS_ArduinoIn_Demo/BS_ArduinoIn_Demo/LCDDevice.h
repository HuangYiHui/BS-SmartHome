#ifndef _BS_LCD_DEVICE_H_
#define _BS_LCD_DEVICE_H_

#include "cfg.h"
#include "Nokia_5110.h"
#include "SampleDevice.h"

class LCDDevice : public SampleDevice, public Nokia_5110
{
public:
	LCDDevice(unsigned short RST, unsigned short CE, unsigned short DC, unsigned short DIN, unsigned short CLK);
};
#endif