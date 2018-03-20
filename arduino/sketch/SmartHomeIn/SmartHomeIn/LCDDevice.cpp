#include "LCDDevice.h"

LCDDevice::LCDDevice(
	unsigned int deviceID,
	unsigned short RST, 
	unsigned short CE, 
	unsigned short DC, 
	unsigned short DIN, 
	unsigned short CLK) 
			:
	SampleDevice(deviceID),
	Nokia_5110(RST, CE, DC, DIN, CLK)
{}