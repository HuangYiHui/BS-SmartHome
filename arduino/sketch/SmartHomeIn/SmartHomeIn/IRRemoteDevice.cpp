#include "IRRemoteDevice.h"

IRRemoteDevice::IRRemoteDevice(unsigned char pin) : IRrecv(pin)
{}

void IRRemoteDevice::start()
{
	enableIRIn();
}