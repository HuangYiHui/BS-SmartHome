#ifndef _BS_MQ2_DEVICE_H_
#define _BS_MQ2_DEVICE_H_

#include "SampleDevice.h"

class MQ2Device : public SampleDevice
{
public:
	MQ2Device(devicePin pin);

	void init();

private:
	devicePin pin;
};

#endif