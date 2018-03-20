#ifndef _BS_ZIGBEE_APP_CMD_H_
#define _BS_ZIGBEE_APP_CMD_H_

//�ϴ����������ʽ��"2byte������ͷ + 2byte���ϴ���(upload index) + ����(һ��Ϊ4byte��float����ֵ)"
#define CMD_UPLOAD_DATA 0x0001
//UPLOAD_INDEX��ƽ̨��sensorID��Ӧ
#define UPLOAD_INDEX_OUT_TEMPERATURE		0x0001
#define UPLOAD_INDEX_OUT_HUMIDITY			0x0002
#define UPLOAD_INDEX_OUT_HEAT				0x0003
#define UPLOAD_INDEX_IN_TEMPERATURE			0x0004
#define UPLOAD_INDEX_IN_HUMIDITY			0x0005
#define UPLOAD_INDEX_IN_HEAT				0x0006
#define UPLOAD_INDEX_SOLID_HUMIDITY			0x0007
#define UPLOAD_INDEX_DUST_DENSITY			0x0008
#define UPLOAD_INDEX_LIGHT_INTENSITY		0x0009
#define UPLOAD_INDEX_HARMFUL_GAS			0x000a
#define UPLOAD_INDEX_FIRE					0x000b

//��ȡִ�����ظ������ʽ��"2byte������ͷ + 2byte��Ŀ��appID + 2byte��ִ������־ + 1byte��ִ����״̬"
#define CMD_RSPONSE_TO_GET_EXECUTER_STATUS	0x0002
//ִ����״̬
#define EXECUTER_STATUS_OPENED	0x01	//����״̬
#define EXECUTER_STATUS_CLOSED	0x02	//�ر�״̬
//ִ������־
#define EXECUTER_INDEX_SWITCH1				0x0001
#define EXECUTER_INDEX_SWITCH2				0x0002
#define EXECUTER_INDEX_SWITCH3				0x0003
#define EXECUTER_INDEX_SWITCH4				0x0004

#endif