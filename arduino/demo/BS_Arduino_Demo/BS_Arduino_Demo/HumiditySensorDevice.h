#ifndef _BS_HUMIDITY_SENSOR_DEVICE_H_
#define _BS_HUMIDITY_SENSOR_DEVICE_H_

#include "SensorDevice.h"
#include "DHT11Device.h"
#include "Arduino.h"

class HumiditySensorDevice : public SensorDevice
{
public:
	HumiditySensorDevice(unsigned int deviceID, DHT11Device& dht11, unsigned int sensorValueIndex);
	void begin();
	float getSensorValue();
private:
	DHT11Device& dht11;
};

#endif