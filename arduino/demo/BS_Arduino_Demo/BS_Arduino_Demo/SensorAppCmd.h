#ifndef _BS_SENSOR_APP_CMD_H_
#define _BS_SENSOR_APP_CMD_H_

#include "AppCmd.h"

//���λ�ȡ���������������ʽ��"2byte����ͷ"
#define CMD_UPLOAD_SENSOR_VALUE				0x0031
//�����������ϴ����������ʽ��"2byte����ͷ"
#define CMD_CIRCULARLY_UPLOAD_SENSOR_VALUE	0x0032
//ֹͣ�������ϴ����������ʽ��"2byte����ͷ"
#define CMD_STOP_UPLOAD_SENSOR_VALUE		0x0033
//�����ϴ���������ֵ��ʱ��������ʽ��"2byte����ͷ + 2byte��ʱ��"��ʱ�䵥λΪms,����Ϊunsigned int
#define CMD_SET_CIRCULARLY_UPLOAD_INTERVAL	0x0034


#endif