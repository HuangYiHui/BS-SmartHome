#ifndef _BS_SYSTEM_CFG_H_
#define _BS_SYSTEM_CFG_H_

/**********��������**********/
#define PIN_DHT11_DATA		2	//��ʪ�ȴ�����DHT11����
#define PIN_LCD_CS			3
#define PIN_LCD_RST			4
#define PIN_LCD_RS			5
#define PIN_LCD_SDA			6
#define PIN_LCD_SCK			7
#define PIN_SWITCH1_OUT		8	//1OUT����
#define PIN_SWITCH2_OUT		9	//����2OUT����
#define PIN_SWITCH3_OUT		10	//����3OUT����
#define PIN_LCD_LED			11
#define PIN_ALARM_OUT		12	//����������
#define PIN_IR_REMOTE_OUT	13	//���⴫����OUT����
#define PIN_FIRE_SENSOR_DO	A0	//���洫����DO����
#define PIN_MQ2_DO			A1	//MQ2������DO����
#define PIN_LCD_ROM_CS		A2
#define PIN_LCD_ROM_SCK		A3
#define PIN_LCD_ROM_OUT		A4
#define PIN_LCD_ROM_IN		A5
/**********��������**********/

#define EXECUTER_ID_SOCKET1	0x01
#define EXECUTER_ID_SOCKET2	0x02
#define EXECUTER_ID_SOCKET3	0x03
#define EXECUTER_ID_ALARM	0x04

/********������ID����*********/
#define SENSOR_ID_IN_TEMPERATURE	0x01
#define SENSOR_ID_IN_HUMIDITY		0x02
#define SENSOR_ID_IN_HEAT			0x03
#define	SENSOR_ID_HARMFUL_GAS		0x04
#define	SENSOR_ID_FIRE				0x05
/********������ID����*********/


/**********Ӧ��ID����**********/
#define APP_ID_IN_ZIGBEE			0x30
#define APP_ID_IN_SENSOR			0x31
#define APP_ID_DANGER_ALARM			0x32
#define APP_ID_SIMPLE_EXECUTER		0x33
#define APP_ID_IRREMOTE				0x34
#define APP_ID_LCD					0x35
#define APP_ID_THH_UPDATA			0x36

/**********Ӧ��ID����**********/

#define SERAIL_BAUD_RATE	19200	//���ڲ�����

#endif