#ifndef _BS_SIMPLE_EXECUTER_APP_CMD_H_
#define _BS_SIMPLE_EXECUTER_APP_CMD_H_

//����ִ���������ʽ��"1byte����ͷ + 1byteִ����ID
#define CMD_OPEN_SIMPLE_EXECUTER		0x31
//�ر�ִ���������ʽ��1byte����ͷ + 1byteִ����ID
#define CMD_CLOSE_SIMPLE_EXECUTER		0x32
//��ȡִ����״̬�����ʽ��"1byte����ͷ + 1byteִ����ID + 1byte��ԴappID"
#define CMD_GET_SIMPLE_EXECUTER_STATE	0x33
//�ظ�ִ����״̬�����ʽ��"1byte����ͷ+1byteִ�����豸ID+1byte״̬"
#define CMD_RESPONSE_EXECUTER_STATE		0x34
#define FLAG_EXECUTER_ON	0x01
#define FLAG_EXECUTER_OFF	0x02

#endif