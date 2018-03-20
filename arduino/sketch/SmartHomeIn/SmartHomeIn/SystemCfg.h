#ifndef _BS_SYSTEM_CFG_H_
#define _BS_SYSTEM_CFG_H_

/**********引脚配置**********/
#define PIN_DHT11_DATA		2	//温湿度传感器DHT11引脚
#define PIN_NOKIA5110_CLK	3	//nokia5110的clk引脚
#define PIN_NOKIA5110_DIN	4	//nokia5110的din引脚
#define PIN_NOKIA5110_DC	5	//nokia5110的dc引脚
#define PIN_NOKIA5110_CE	6	//nokia5110的ce引脚
#define PIN_NOKIA5110_RST	7	//nokia5110的rst引脚
#define PIN_SWITCH1_OUT		8	//开关1OUT引脚
#define PIN_SWITCH2_OUT		9	//开关2OUT引脚
#define PIN_SWITCH3_OUT		10	//开关3OUT引脚
#define PIN_SWITCH4_OUT		11	//开关4OUT引脚
#define PIN_ALARM_OUT		12	//警报器引脚
#define PIN_IR_REMOTE_OUT	13	//红外传感器OUT引脚
#define PIN_FIRE_SENSOR_DO	A2	//火焰传感器DO引脚
#define PIN_MQ2_DO			A3	//MQ2传感器DO引脚
/**********引脚配置**********/


/**********设备ID分配**********/
#define DEVICE_ID_IN_ZIGBEE				0x0030
#define DEVICE_ID_IN_DHT11				0x0031
#define DEVICE_ID_IN_TEMPERATURE_SENSOR	0x0032
#define DEVICE_ID_IN_HUMIDITY_SENSOR	0x0033
#define DEVICE_ID_IN_HEAT_SENSOR		0x0034
#define DEVICE_ID_HARMFUL_GAS_SENSOR	0x0035
#define DEVICE_ID_SWITCH1				0x0036
#define DEVICE_ID_SWITCH2				0x0037
#define DEVICE_ID_SWITCH3				0x0038
#define DEVICE_ID_SWITCH4				0x0039
#define DEVICE_ID_LCD					0x003a
#define DEVICE_ID_ALARM					0x003b
#define DEVICE_ID_FIRE_SENSOR			0x003c
#define DEVICE_ID_IR_REMOTE				0x003d
/**********设备ID分配**********/


/**********应用ID分配**********/
#define APP_ID_ZIGBEE				0x0030
#define APP_ID_SENSOR				0x0031
#define APP_ID_DANGER_ALARM			0x0032
#define APP_ID_SWITCHS				0x0033
#define APP_ID_IRREMOTE				0x0034
#define APP_ID_LCD					0x0035

/**********应用ID分配**********/

#define SERAIL_BAUD_RATE	19200	//串口波特率

#endif