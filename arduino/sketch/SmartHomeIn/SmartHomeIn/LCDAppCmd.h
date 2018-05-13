#ifndef _BS_LCD_APP_CMD_H_
#define _BS_LCD_APP_CMD_H_

//֪ͨ���⴫������ֵ�����ʽ��"1byte����ͷ + 20byte��3��float����,�ֱ�Ϊ�¶ȣ�ʪ�Ⱥ��ȶ�"
#define CMD_NOTICE_IN_SENSOR_VALUES		0x01

//֪ͨ���⴫������ֵ�����ʽ��"1byte����ͷ + 20byte��5��float����"
#define CMD_NOTICE_OUT_SENSOR_VALUES	0x02

//֪ͨ�ѵ����ӵ���������,��ʽΪ��"1byte����ͷ��1byte�Ƿ����ӱ�־"
#define CMD_NOTICE_ZIGBEE_ONLINE		0x03
#define FLAG_ONLINE			0x01
#define FLAG_OFFLINE		0x02

//֪ͨ����״̬�ı������ʽ��"1byte����ͷ + 1byte����ID + 1byte״̬��־"
#define CMD_NOTICE_SOCKET_STATE_CHANGE	0x04
#define FLAG_SOCKET1		0x01
#define FLAG_SOCKET2		0x02
#define FLAG_SOCKET3		0x03
#define FLAG_SOCKET_ON		0x01
#define FLAG_SOCKET_OFF		0x02

//֪ͨ����״̬�ı������ʽ��"1byte����ͷ + 1byte����ID + 1byte״̬��־"
#define CMD_NOTICE_IS_DANGER			0x05
#define FLAG_DANGER		0x01
#define FLAG_NO_DANGER	0x02

#endif