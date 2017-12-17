
//SCL-A5
//SDA-A4
//ADO-空

#include <bh1750xtra.h>
#include <Wire.h>

BH1750xtra bhSensor;

void setup() {
    uint8_t error;
    Serial.begin(9600);
    Wire.begin(); //初始化I2C总线
    Wire.beginTransmission(35);
    //取消测试每个方法
    bhSensor.Set_To_Max_Resolution_Measurement(); 
    delay(1000);
}

void loop() {
    int8_t nBytesRead = bhSensor.Read_I2C_To_Buffer();
    if (nBytesRead != 2)  
		Serial.print("I2C reading error "); 
	else {
		int value = bhSensor.Get_Read_Lux();
        Serial.print(value); 
		Serial.println(" lx ");
    }
    delay(1000);
}

