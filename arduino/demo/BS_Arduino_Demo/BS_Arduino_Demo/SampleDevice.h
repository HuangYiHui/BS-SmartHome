#ifndef _BS_SAMPLE_DEVICE_H_
#define _BS_SAMPLE_DEVICE_H_

#include "IDevice.h"
#include "Arduino.h"

class SampleDevice : public IDevice
{
public:
	SampleDevice();
	virtual	void open();
	virtual	void init();
	virtual	void start();
	virtual	void stop();
	virtual void reset();
	virtual	void close();
	virtual	deviceState getState();
	virtual	void begin();	//����open->init->start
	virtual	void end();	////����stop->close
protected:
	deviceState state;
};
#endif