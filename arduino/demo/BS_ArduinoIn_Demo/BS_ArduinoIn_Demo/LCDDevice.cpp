#include "LCDDevice.h"

LCDDevice::LCDDevice(
	unsigned short RST, 
	unsigned short CE, 
	unsigned short DC, 
	unsigned short DIN, 
	unsigned short CLK) 
			:
	Nokia_5110(RST, CE, DC, DIN, CLK)
{}