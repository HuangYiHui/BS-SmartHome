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


#define SENSOR_ID_OUT_TEMPERATURE	0x11
#define SENSOR_ID_OUT_HUMIDITY		0x12
#define SENSOR_ID_OUT_HEAT			0x13
#define SENSOR_ID_SOLID_HUMIDITY	0x14
#define SENSOR_ID_DUST_DENSITY		0x15
#define SENSOR_ID_LIGHT_INTENSITY	0x16

/**********Ӧ��ID����**********/
#define APP_ID_OUT_ZIGBEE				0x90
#define APP_ID_OUT_SENSOR				0x91
#define APP_ID_NOTICE_OUT_SENSOR_VALUE	0x92
/**********Ӧ��ID����**********/

#define SERAIL_BAUD_RATE	19200	//���ڲ�����

#endif