#ifndef _BS_SENSOR_APP_CMD_H_
#define _BS_SENSOR_APP_CMD_H_

#include "DeviceCmd.h"

//�����������ϴ����������ʽ��"1byte����ͷ + 1byte������ID"
#define CMD_START_CIRCULARLY_UPLOAD_SENSOR_VALUE	0x01
//ֹͣ�������ϴ����������ʽ��"1byte����ͷ + 1byte������ID"
#define CMD_STOP_CIRCULARLY_UPLOAD_SENSOR_VALUE		0x02
//�����ϴ���������ֵ��ʱ��������ʽ��"1byte����ͷ +  + 1byte�豸ID + 2byte��ʱ��"��ʱ�䵥λΪms,����Ϊunsigned int
#define CMD_SET_CIRCULARLY_UPLOAD_INTERVAL			0x03
//�����ϴ����������ʽ��"1byte����ͷ + 1byte������ID"
#define CMD_UPLOAD_SENSOR_VALUE						0x04

#endif