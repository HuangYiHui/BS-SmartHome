#ifndef _BS_ZIGBEE_APP_CMD_H_
#define _BS_ZIGBEE_APP_CMD_H_

//�ϴ����������ʽ��"2byte������ͷ + 2byte���ϴ���(upload index)+nByte����"
#define CMD_UPLOAD_DATA 0x0001
//��������ֵ�ϴ�����ʽ��"2byte�豸ID + 4byte��ֵ"
#define UPLOAD_DATA_INDEX_SENSOR_VALUE		0x0001

//��ȡִ�����ظ������ʽ��"2byte������ͷ + 2byte��Ŀ��appID + 2byte��ִ������־ + 1byte��ִ����״̬"
#define CMD_RSPONSE_TO_GET_EXECUTER_STATUS	0x0002
//ִ����״̬
#define EXECUTER_STATUS_OPENED	0x01	//����״̬
#define EXECUTER_STATUS_CLOSED	0x02	//�ر�״̬

#endif