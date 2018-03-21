#include "GY30Device.h"

GY30Device::GY30Device(unsigned int deviceID) : SensorDevice(deviceID)
{
	state = DEVICE_STATE_CLOSED;
}

//注意，如果GY30的电源未接，程序可能卡在这里
void GY30Device::init()
{
	Wire.begin(); //初始化I2C总线
    Wire.beginTransmission(35);
	//取消测试每个方法
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