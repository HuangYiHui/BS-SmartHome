/*
	�豸�ӿڶ���
*/

#ifndef _BS_IDEVICE_H_
#define _BS_IDEVICE_H_

typedef unsigned char deviceState;
typedef unsigned char devicePin;

//�豸״̬����
#define DEVICE_STATE_CLOSED		0x31	//�ر�״̬
#define DEVICE_STATE_UNREADY	0x32	//δ׼��״̬
#define DEVICE_STATE_READY		0x33	//��׼��״̬
#define DEVICE_STATE_WORKING	0x34	//����״̬

class IDevice
{
	virtual void open() = 0;	//�������ر�״̬ -> δ׼��״̬
	virtual void init() = 0;	//��ʼ����δ׼��״̬ -> ��׼��״̬
	virtual void start() = 0;	//��������׼��״̬ -> ����״̬
	virtual void stop() = 0;	//ֹͣ������״̬ -> ��׼��״̬
	virtual void reset() = 0;	//���ã�-> δ׼��״̬
	virtual void close() = 0;	//�رգ���׼��״̬ -> �ر�״̬
	virtual deviceState getState() = 0;	//��ȡ״̬
};

#endif