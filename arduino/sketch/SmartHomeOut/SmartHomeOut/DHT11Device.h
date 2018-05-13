#ifndef _BS_DHT11_DEVICE_H_
#define _BS_DHT11_DEVICE_H_

#include "IDevice.h"
#include "DHT11.h"

class DHT11Device : public SampleDevice
{
private:
	unsigned char pin;		//dht11的DATA引脚
	DHT11 dht11;
	float calcHeatIndex(float t, float h);		//热度计算
public:
	DHT11Device(unsigned char pin);
	float readTemperature();		//读取温度
	float readHumidity();			//读取湿度
	float readHeatIndex();			//读取热度
	//一次性按顺序读取温度、湿度和热度到数组
	void readSensorValue(float* results);
};

#endif