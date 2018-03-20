#include "IRRemoteDevice.h"

//因为IRremote库与Tone库冲突，这里选择性编译
#ifdef CUR_SYSTEM_IN

IRRemoteDevice::IRRemoteDevice(unsigned int deviceID, devicePin pin) : SampleDevice(deviceID), IRrecv(pin)
{}

void IRRemoteDevice::init()
{
	enableIRIn();
}

#endif