
//��ΪIRremote����Tone���ͻ������ѡ���Ա���
#ifdef CUR_SYSTEM_IN

#include "IRRemoteDevice.h"

IRRemoteDevice::IRRemoteDevice(devicePin pin) : IRrecv(pin)
{}

void IRRemoteDevice::init()
{
	enableIRIn();
}

#endif