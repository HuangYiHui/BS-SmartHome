#include "IRRemoteDevice.h"

//��ΪIRremote����Tone���ͻ������ѡ���Ա���
#ifdef CUR_SYSTEM_IN

IRRemoteDevice::IRRemoteDevice(unsigned int deviceID, devicePin pin) : SampleDevice(deviceID), IRrecv(pin)
{}

void IRRemoteDevice::init()
{
	enableIRIn();
}

#endif