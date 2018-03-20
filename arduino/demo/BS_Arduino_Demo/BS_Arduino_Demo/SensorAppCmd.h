#ifndef _BS_SENSOR_APP_CMD_H_
#define _BS_SENSOR_APP_CMD_H_

#include "AppCmd.h"

//单次获取传感器数据命令，格式："2byte命令头"
#define CMD_UPLOAD_SENSOR_VALUE				0x0031
//开启周期性上传数据命令，格式："2byte命令头"
#define CMD_CIRCULARLY_UPLOAD_SENSOR_VALUE	0x0032
//停止周期性上传数据命令，格式："2byte命令头"
#define CMD_STOP_UPLOAD_SENSOR_VALUE		0x0033
//设置上传传感器数值的时间间隔，格式："2byte命令头 + 2byte的时间"，时间单位为ms,类型为unsigned int
#define CMD_SET_CIRCULARLY_UPLOAD_INTERVAL	0x0034


#endif