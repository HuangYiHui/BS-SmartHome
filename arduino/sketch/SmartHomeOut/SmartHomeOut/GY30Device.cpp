#include "GY30Device.h"

GY30Device::GY30Device(unsigned char sensorID) : SensorDevice(sensorID)
{
}

//注意，如果GY30的电源未接，程序可能卡在这里
void GY30Device::start()
{
	Wire.begin(); //初始化I2C总线
    Wire.beginTransmission(35);
	//取消测试每个方法
    bhSensor.Set_To_Max_Resolution_Measurement();
}

float GY30Device::getSensorValue()
{
	if(bhSensor.Read_I2C_To_Buffer() == 2)
		return bhSensor.Get_Read_Lux();
	else
		return 0;
}