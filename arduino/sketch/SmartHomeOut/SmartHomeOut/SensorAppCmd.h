#ifndef _BS_SENSOR_APP_CMD_H_
#define _BS_SENSOR_APP_CMD_H_

//�ϴ��豸ֵ�����ʽ��"1byte����ͷ"
#define CMD_UPLOAD_ALL_DEVICE_VALUE	0xf0

//�����������ϴ����������ʽ��"2byte����ͷ + 2byte�豸ID"
#define CMD_START_CIRCULARLY_UPLOAD_SENSOR_VALUE	0x31
//ֹͣ�������ϴ����������ʽ��"2byte����ͷ + 2byte�豸ID"
#define CMD_STOP_CIRCULARLY_UPLOAD_SENSOR_VALUE		0x32
//�����ϴ���������ֵ��ʱ��������ʽ��"2byte����ͷ +  + 2byte�豸ID + 2byte��ʱ��"��ʱ�䵥λΪms,����Ϊunsigned int
#define CMD_SET_CIRCULARLY_UPLOAD_INTERVAL	0x33


#endif