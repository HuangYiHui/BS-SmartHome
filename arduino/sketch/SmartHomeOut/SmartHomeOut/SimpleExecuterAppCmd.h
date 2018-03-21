#ifndef _BS_SIMPLE_EXECUTER_APP_CMD_H_
#define _BS_SIMPLE_EXECUTER_APP_CMD_H_

//开启执行器命令，格式："2byte命令头 + 2byte执行器ID
#define CMD_OPEN_SIMPLE_EXECUTER		0x0031
//关闭执行器命令，格式："2byte命令头 + 2byte执行器ID
#define CMD_CLOSE_SIMPLE_EXECUTER		0x0032
//获取执行器状态命令，格式："2byte命令头 + 2byte执行器ID + 2byte的源appID"
#define CMD_GET_SIMPLE_EXECUTER_STATUS	0x0033

#endif