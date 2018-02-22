#include "IRRemoteDevice.h"

IRRemoteDevice::IRRemoteDevice(devicePin pin) : IRrecv(pin)
{}

void IRRemoteDevice::init()
{
	enableIRIn();
}