#ifndef _BS_SIMPLE_EXECUTER_APP_CMD_H_
#define _BS_SIMPLE_EXECUTER_APP_CMD_H_

//开启执行器命令，格式："1byte命令头 + 1byte执行器ID
#define CMD_OPEN_SIMPLE_EXECUTER		0x01
//关闭执行器命令，格式：1byte命令头 + 1byte执行器ID
#define CMD_CLOSE_SIMPLE_EXECUTER		0x02
//获取执行器状态命令，格式："1byte命令头 + 1byte执行器ID + 1byte的源appID"
#define CMD_GET_SIMPLE_EXECUTER_STATE	0x03
//回复执行器状态命令，格式："1byte命令头+1byte执行器设备ID+1byte状态"
#define CMD_RESPONSE_EXECUTER_STATE		0x04
#define FLAG_EXECUTER_ON	0x01
#define FLAG_EXECUTER_OFF	0x02

#endif