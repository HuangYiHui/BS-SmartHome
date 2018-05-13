#ifndef _BS_ISYSTEM_H_
#define _BS_ISYSTEM_H_

//��ʹ��
#include <MemoryFree.h>

#include "Arduino.h"
#include "IApp.h"

class ISystem
{
public:
	virtual void init() = 0;	//��ʼ��
	virtual void start() = 0;	//��ʼ����
	virtual void stop() = 0;	//ֹͣ����
	virtual void reset() = 0;	//����ϵͳ
	virtual void installApp(IApp* app) = 0;	//��װӦ��
	virtual void sendAppMsg(AppMsg& msg, unsigned char appID) = 0;	//����Ӧ����Ϣ
};
#endif