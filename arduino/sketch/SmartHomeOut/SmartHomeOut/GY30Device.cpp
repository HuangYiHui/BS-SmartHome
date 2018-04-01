#include "GY30Device.h"

GY30Device::GY30Device(unsigned char sensorID) : SensorDevice(sensorID)
{
}

//ע�⣬���GY30�ĵ�Դδ�ӣ�������ܿ�������
void GY30Device::start()
{
	Wire.begin(); //��ʼ��I2C����
    Wire.beginTransmission(35);
	//ȡ������ÿ������
    bhSensor.Set_To_Max_Resolution_Measurement();
}

float GY30Device::getSensorValue()
{
	if(bhSensor.Read_I2C_To_Buffer() == 2)
		return bhSensor.Get_Read_Lux();
	else
		return 0;
}