#ifndef _BS_SYSTEM_CFG_H_
#define _BS_SYSTEM_CFG_H_

/**********��������**********/
#define PIN_DHT11_DATA		2	//��ʪ�ȴ�����DHT11����
#define PIN_NOKIA5110_CLK	3	//nokia5110��clk����
#define PIN_NOKIA5110_DIN	4	//nokia5110��din����
#define PIN_NOKIA5110_DC	5	//nokia5110��dc����
#define PIN_NOKIA5110_CE	6	//nokia5110��ce����
#define PIN_NOKIA5110_RST	7	//nokia5110��rst����
#define PIN_SWITCH1_OUT		8	//����1OUT����
#define PIN_SWITCH2_OUT		9	//����2OUT����
#define PIN_SWITCH3_OUT		10	//����3OUT����
#define PIN_SWITCH4_OUT		11	//����4OUT����
#define PIN_ALARM_OUT		12	//����������
#define PIN_IR_REMOTE_OUT	13	//���⴫����OUT����
#define PIN_FIRE_SENSOR_DO	A2	//���洫����DO����
#define PIN_MQ2_DO			A3	//MQ2������DO����
/**********��������**********/


/**********�豸ID����**********/
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