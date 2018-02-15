#include "gy30Task.h"

static struct pt pt;
BH1750xtra bhSensor;

void initGY30Task()
{
	pinMode(PIN_LED1, OUTPUT);
	digitalWrite(PIN_LED1, LOW);
	pinMode(PIN_LED2, OUTPUT);
	digitalWrite(PIN_LED2, LOW);
	Wire.begin(); //初始化I2C总线
    Wire.beginTransmission(35);
    //取消测试每个方法
    bhSensor.Set_To_Max_Resolution_Measurement(); 

	PT_INIT(&pt);
}

static int run()
{
	PT_BEGIN(&pt);
	while (1)
	{
		PT_TIMER_DELAY(&pt,1500);
		int8_t nBytesRead = bhSensor.Read_I2C_To_Buffer();
		if (nBytesRead != 2)  
			Serial.print("I2C reading error "); 
		else {
			int value = bhSensor.Get_Read_Lux();
			Serial.print(value); 
			Serial.println(" lx ");

			if(value < 100){
				digitalWrite(PIN_LED1, HIGH);
				digitalWrite(PIN_LED2, HIGH);
			} else{
				digitalWrite(PIN_LED1, LOW);
				digitalWrite(PIN_LED2, LOW);
			}
		}
	}
	PT_END(&pt);
}

void runGY30Task()
{
	run();
}