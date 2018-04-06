#ifndef _BS_SENSOR_APP_CMD_H_
#define _BS_SENSOR_APP_CMD_H_

//上传设备值命令，格式："1byte命令头"
#define CMD_UPLOAD_ALL_DEVICE_VALUE	0xf0

//开启周期性上传数据命令，格式："2byte命令头 + 2byte设备ID"
#define CMD_START_CIRCULARLY_UPLOAD_SENSOR_VALUE	0x31
//停止周期性上传数据命令，格式："2byte命令头 + 2byte设备ID"
#define CMD_STOP_CIRCULARLY_UPLOAD_SENSOR_VALUE		0x32
//设置上传传感器数值的时间间隔，格式："2byte命令头 +  + 2byte设备ID + 2byte的时间"，时间单位为ms,类型为unsigned int
#define CMD_SET_CIRCULARLY_UPLOAD_INTERVAL	0x33


#endif