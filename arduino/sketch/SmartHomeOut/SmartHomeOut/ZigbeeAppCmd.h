#ifndef _BS_ZIGBEE_APP_CMD_H_
#define _BS_ZIGBEE_APP_CMD_H_

//上传数据命令，格式："2byte的命令头 + 2byte的上传项(upload index)+nByte数据"
#define CMD_UPLOAD_DATA 0x0001
//传感器数值上传，格式："2byte设备ID + 4byte数值"
#define UPLOAD_DATA_INDEX_SENSOR_VALUE		0x0001

//获取执行器回复命令，格式："2byte的命令头 + 2byte的目标appID + 2byte的执行器标志 + 1byte的执行器状态"
#define CMD_RSPONSE_TO_GET_EXECUTER_STATUS	0x0002
//执行器状态
#define EXECUTER_STATUS_OPENED	0x01	//开启状态
#define EXECUTER_STATUS_CLOSED	0x02	//关闭状态

#endif