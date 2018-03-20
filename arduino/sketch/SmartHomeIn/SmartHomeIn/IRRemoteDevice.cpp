#include "IRRemoteDevice.h"

IRRemoteDevice::IRRemoteDevice(unsigned int deviceID, devicePin pin) : SampleDevice(deviceID), IRrecv(pin)
{}

void IRRemoteDevice::init()
{
	enableIRIn();
}