#ifndef _BS_LCD_APP_CMD_H_
#define _BS_LCD_APP_CMD_H_

//�������������ʽ��"2byte����ͷ + 2byte����index + nbyte����"
#define CMD_RECEIVE_DATA	0x0001

//����index
//���������ݣ�����ʵ��Ϊ4byte��������ֵ
#define DATA_INDEX_IN_TEMPERATURE	0x0001
#define DATA_INDEX_IN_HUMIDITY		0x0002
#define DATA_INDEX_IN_HEAT			0x0003

#endif