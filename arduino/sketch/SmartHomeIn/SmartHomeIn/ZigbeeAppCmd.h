#ifndef _BS_ZIGBEE_APP_CMD_H_
#define _BS_ZIGBEE_APP_CMD_H_

#include "DeviceCmd.h"

//������Ϣ��app�����ʽ��"1byte����ͷ + 1byteappID + nbyte����"
#define CMD_SEND_MSG_TO_APP				0x01
//�ϴ����������ʽ��"1byte������ͷ + 1byte���ϴ���(upload index)+nByte����"
#define CMD_UPLOAD_DATA					0x02
//��������ֵ�ϴ�����ʽ��"1byteSensorID + 4byte��ֵ"
#define UPLOAD_DATA_INDEX_SENSOR_VALUE		0x01
#define UPLOAD_DATA_INDEX_EXECUTER_VALUE	0x02
#define EXECUTER_VALUE_OPENED	0x01
#define EXECUTER_VALUE_CLOSED	0x02

#define CMD_OUT_SENSOR_VALUES_COMING	0x03

#define CMD_QUERY_ZIGBEE_IS_ONLINE		0x04

#define CMD_RESPONSE_ZIGBEE_ONLINE		0x05

#define CMD_ZIGBEE_APP_UPLAOD_ALL_DEVICE_VALUE		0x06

#endif