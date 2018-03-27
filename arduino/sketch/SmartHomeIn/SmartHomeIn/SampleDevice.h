#ifndef _BS_SAMPLE_DEVICE_H_
#define _BS_SAMPLE_DEVICE_H_

#include "IDevice.h"
#include "Arduino.h"

class SampleDevice : public IDevice
{
public:
	SampleDevice(unsigned int deviceID);
	virtual	void start();
	virtual	void stop();
	virtual unsigned int getDeviceID();
protected:
	const unsigned int deviceID;
};
#endif