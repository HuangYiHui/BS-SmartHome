
//���������ɷ������͵ƹ����

#ifndef _BS_IRREMOTE_DEVICE_H_
#define _BS_IRREMOTE_DEVICE_H_

#include "Arduino.h"
#include "SampleDevice.h"
#include "dataDef.h"
#include "IRremote.h"

class IRRemoteDevice : public SampleDevice, public IRrecv
{
public:
	IRRemoteDevice(devicePin pin);
	void init();
};

#endif