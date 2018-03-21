#include "GY30Device.h"

GY30Device::GY30Device(unsigned int deviceID) : SensorDevice(deviceID)
{
	state = DEVICE_STATE_CLOSED;
}

//ע�⣬���GY30�ĵ�Դδ�ӣ�������ܿ�������
void GY30Device::init()
{
	Wire.begin(); //��ʼ��I2C����
    Wire.beginTransmission(35);
	//ȡ������ÿ������
    bhSensor.Set_To_Max_Resolution_Measurement();
	state = DEVICE_STATE_READY;
}

float GY30Device::getSensorValue()
{
	Serial.println("5555");
	if(bhSensor.Read_I2C_To_Buffer() == 2)
		return bhSensor.Get_Read_Lux();
	else
		return 0;
}