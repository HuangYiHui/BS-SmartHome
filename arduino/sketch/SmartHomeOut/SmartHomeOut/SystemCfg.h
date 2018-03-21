#ifndef _BS_SYSTEM_CFG_H_
#define _BS_SYSTEM_CFG_H_

/**********引脚配置**********/
#define PIN_DHT11_DATA		9	//温湿度传感器DHT11引脚
#define PIN_PM25_LED		10	//pm2.5(GP2Y1014AU)led引脚
#define PIN_PM25_VO			A2	//pm2.5(GP2Y1014AU)VO引脚
#define PIN_FC28_IN			A3	//土壤湿度传感器引脚
#define PIN_GY30_SCL		A5	//光强传感器GY30的SCL引脚
#define PIN_GY30_SDA		A4	//光强传感器GY30的SDA引脚
/**********引脚配置**********/


/**********设备ID分配**********/
#define DEVICE_ID_OUT_ZIGBEE				0x0090
#define DEVICE_ID_OUT_DHT11					0x0091
#define DEVICE_ID_OUT_TEMPERATURE_SENSOR	0x0092
#define DEVICE_ID_OUT_HUMIDITY_SENSOR		0x0093
#define DEVICE_ID_OUT_HEAT_SENSOR			0x0094
#define DEVICE_ID_SOLID_HUMIDITY_SENSOR		0x0095
#define DEVICE_ID_DUST_DENSITY_SENSOR		0x0096
#define DEVICE_ID_LIGHT_INTENSITY_SENSOR	0x0097
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