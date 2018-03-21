#ifndef _BS_SYSTEM_CFG_H_
#define _BS_SYSTEM_CFG_H_

/**********��������**********/
#define PIN_DHT11_DATA		9	//��ʪ�ȴ�����DHT11����
#define PIN_PM25_LED		10	//pm2.5(GP2Y1014AU)led����
#define PIN_PM25_VO			A2	//pm2.5(GP2Y1014AU)VO����
#define PIN_FC28_IN			A3	//����ʪ�ȴ���������
#define PIN_GY30_SCL		A5	//��ǿ������GY30��SCL����
#define PIN_GY30_SDA		A4	//��ǿ������GY30��SDA����
/**********��������**********/


/**********�豸ID����**********/
#define DEVICE_ID_OUT_ZIGBEE				0x0090
#define DEVICE_ID_OUT_DHT11					0x0091
#define DEVICE_ID_OUT_TEMPERATURE_SENSOR	0x0092
#define DEVICE_ID_OUT_HUMIDITY_SENSOR		0x0093
#define DEVICE_ID_OUT_HEAT_SENSOR			0x0094
#define DEVICE_ID_SOLID_HUMIDITY_SENSOR		0x0095
#define DEVICE_ID_DUST_DENSITY_SENSOR		0x0096
#define DEVICE_ID_LIGHT_INTENSITY_SENSOR	0x0097
/**********�豸ID����**********/


/**********Ӧ��ID����**********/
#define APP_ID_ZIGBEE				0x0030
#define APP_ID_SENSOR				0x0031
#define APP_ID_DANGER_ALARM			0x0032
#define APP_ID_SWITCHS				0x0033
#define APP_ID_IRREMOTE				0x0034
#define APP_ID_LCD					0x0035

/**********Ӧ��ID����**********/

#define SERAIL_BAUD_RATE	19200	//���ڲ�����

#endif