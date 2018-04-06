#ifndef _BS_ZIGBEE_APP_CMD_H_
#define _BS_ZIGBEE_APP_CMD_H_

#include "DeviceCmd.h"

//发送消息给app命令，格式："1byte命令头 + 1byteappID + nbyte数据"
#define CMD_SEND_MSG_TO_APP				0x01
//上传数据命令，格式："1byte的命令头 + 1byte的上传项(upload index)+nByte数据"
#define CMD_UPLOAD_DATA					0x02
//传感器数值上传，格式："1byteSensorID + 4byte数值"
#define UPLOAD_DATA_INDEX_SENSOR_VALUE		0x01
#define UPLOAD_DATA_INDEX_EXECUTER_VALUE	0x02
#define EXECUTER_VALUE_OPENED	0x01
#define EXECUTER_VALUE_CLOSED	0x02

#define CMD_OUT_SENSOR_VALUES_COMING	0x03

#define CMD_QUERY_ZIGBEE_IS_ONLINE		0x04

#define CMD_RESPONSE_ZIGBEE_ONLINE		0x05

#define CMD_ZIGBEE_APP_UPLAOD_ALL_DEVICE_VALUE		0x06

#endif