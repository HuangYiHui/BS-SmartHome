#ifndef _BS_IRREMOTE_DEVICE_H_
#define _BS_IRREMOTE_DEVICE_H_

#include "SampleDevice.h"
#include "IRremote.h"

class IRRemoteDevice : public SampleDevice, public IRrecv
{
public:
	IRRemoteDevice(unsigned int deviceID, devicePin pin);
	void init();
};

#endif