#ifndef _BS_SYSTEM_CFG_H_
#define _BS_SYSTEM_CFG_H_

/**********引脚配置**********/
#define PIN_DHT11_DATA		2	//温湿度传感器DHT11引脚
#define PIN_LCD_CS			3
#define PIN_LCD_RST			4
#define PIN_LCD_RS			5
#define PIN_LCD_SDA			6
#define PIN_LCD_SCK			7
#define PIN_SWITCH1_OUT		8	//1OUT引脚
#define PIN_SWITCH2_OUT		9	//开关2OUT引脚
#define PIN_SWITCH3_OUT		10	//开关3OUT引脚
#define PIN_LCD_LED			11
#define PIN_ALARM_OUT		12	//警报器引脚
#define PIN_IR_REMOTE_OUT	13	//红外传感器OUT引脚
#define PIN_FIRE_SENSOR_DO	A0	//火焰传感器DO引脚
#define PIN_MQ2_DO			A1	//MQ2传感器DO引脚
#define PIN_LCD_ROM_CS		A2
#define PIN_LCD_ROM_SCK		A3
#define PIN_LCD_ROM_OUT		A4
#define PIN_LCD_ROM_IN		A5
/**********引脚配置**********/

#define EXECUTER_ID_SOCKET1	0x01
#define EXECUTER_ID_SOCKET2	0x02
#define EXECUTER_ID_SOCKET3	0x03
#define EXECUTER_ID_ALARM	0x04

/********传感器ID分配*********/
#define SENSOR_ID_IN_TEMPERATURE	0x01
#define SENSOR_ID_IN_HUMIDITY		0x02
#define SENSOR_ID_IN_HEAT			0x03
#define	SENSOR_ID_HARMFUL_GAS		0x04
#define	SENSOR_ID_FIRE				0x05
/********传感器ID分配*********/


/**********应用ID分配**********/
#define APP_ID_IN_ZIGBEE			0x30
#define APP_ID_IN_SENSOR			0x31
#define APP_ID_DANGER_ALARM			0x32
#define APP_ID_SIMPLE_EXECUTER		0x33
#define APP_ID_IRREMOTE				0x34
#define APP_ID_LCD					0x35
#define APP_ID_THH_UPDATA			0x36

/**********应用ID分配**********/

#define SERAIL_BAUD_RATE	19200	//串口波特率

#endif