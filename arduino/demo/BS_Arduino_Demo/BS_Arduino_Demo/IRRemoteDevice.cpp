#include "IRRemoteDevice.h"

//��ΪIRremote����Tone���ͻ������ѡ���Ա���
#ifdef CUR_SYSTEM_IN

IRRemoteDevice::IRRemoteDevice(devicePin pin) : IRrecv(pin)
{}

void IRRemoteDevice::init()
{
	enableIRIn();
}

#endif