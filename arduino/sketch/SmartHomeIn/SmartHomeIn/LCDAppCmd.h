#ifndef _BS_LCD_APP_CMD_H_
#define _BS_LCD_APP_CMD_H_

//通知室外传感器数值命令，格式："1byte命令头 + 20byte的3个float数据,分别为温度，湿度和热度"
#define CMD_NOTICE_IN_SENSOR_VALUES		0x01

//通知室外传感器数值命令，格式："1byte命令头 + 20byte的5个float数据"
#define CMD_NOTICE_OUT_SENSOR_VALUES	0x02

//通知已的连接到网关命令,格式为："1byte命令头，1byte是否连接标志"
#define CMD_NOTICE_ZIGBEE_ONLINE		0x03
#define FLAG_ONLINE			0x01
#define FLAG_OFFLINE		0x02

//通知插座状态改变命令，格式："1byte命令头 + 1byte插座ID + 1byte状态标志"
#define CMD_NOTICE_SOCKET_STATE_CHANGE	0x04
#define FLAG_SOCKET1		0x01
#define FLAG_SOCKET2		0x02
#define FLAG_SOCKET3		0x03
#define FLAG_SOCKET_ON		0x01
#define FLAG_SOCKET_OFF		0x02

//通知插座状态改变命令，格式："1byte命令头 + 1byte插座ID + 1byte状态标志"
#define CMD_NOTICE_IS_DANGER			0x05
#define FLAG_DANGER		0x01
#define FLAG_NO_DANGER	0x02

#endif