#ifndef _BS_LCD_APP_CMD_H_
#define _BS_LCD_APP_CMD_H_

//接收数据命令，格式："2byte命令头 + 2byte数据index + nbyte数据"
#define CMD_RECEIVE_DATA	0x0001

//数据index
//传感器数据，数据实体为4byte传感器数值
#define DATA_INDEX_IN_TEMPERATURE	0x0001
#define DATA_INDEX_IN_HUMIDITY		0x0002
#define DATA_INDEX_IN_HEAT			0x0003

#endif