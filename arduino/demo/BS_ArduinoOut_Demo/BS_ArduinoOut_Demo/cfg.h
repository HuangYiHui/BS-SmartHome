
#ifndef _BS_CFG_H_
#define _BS_CFG_H_

#include "DHT.h"

//引脚定义
#define PIN_TOUCH_SENSOR	2	//触摸传感器引脚
#define PIN_BELL	11	//扬声器引脚
#define PIN_DHT11	9	//温湿度传感器DHT11引脚
#define PIN_PM25_LED	10	//pm2.5(GP2Y1014AU)led引脚
#define PIN_PM25_VO	A2	//pm2.5(GP2Y1014AU)VO引脚
#define PIN_FC28	A3	//土壤湿度传感器引脚
#define PIN_GY30_SCL	A5	//光强传感器GY30的SCL引脚
#define PIN_GY30_SDA	A4	//光强传感器GY30的SDA引脚
#define PIN_LED1	4	//灯光1引脚
#define PIN_LED2	7	//灯光1引脚

//其他
#define SERIAL_RATE 9600	//串口波特率
#define DHTTYPE DHT11	//温湿度传感器类型

#endif