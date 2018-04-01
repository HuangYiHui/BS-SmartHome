#ifndef _BS_IRREMOTE_DEVICE_H_
#define _BS_IRREMOTE_DEVICE_H_

#include "IDevice.h"
#include "IRremote.h"

class IRRemoteDevice : public SampleDevice, public IRrecv
{
public:
	IRRemoteDevice(unsigned char pin);
	void start();
};

#endif