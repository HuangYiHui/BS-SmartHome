#ifndef _BS_DHT11_DEVICE_H_
#define _BS_DHT11_DEVICE_H_

#include "IDevice.h"
#include "DHT11.h"

class DHT11Device : public SampleDevice
{
private:
	unsigned char pin;		//dht11��DATA����
	DHT11 dht11;
	float calcHeatIndex(float t, float h);		//�ȶȼ���
public:
	DHT11Device(unsigned char pin);
	float readTemperature();		//��ȡ�¶�
	float readHumidity();			//��ȡʪ��
	float readHeatIndex();			//��ȡ�ȶ�
	//һ���԰�˳���ȡ�¶ȡ�ʪ�Ⱥ��ȶȵ�����
	void readSensorValue(float* results);
};

#endif