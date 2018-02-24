#ifndef _BS_DHT11_DEVICE_H_
#define _BS_DHT11_DEVICE_H_

#include "SampleDevice.h"
#include "DHT.h"
#include "Arduino.h"

class DHT11Device : public SampleDevice, public DHT
{
public:
	DHT11Device(devicePin pin);
	void init();
};

#endif