//��app���ڲ���ϵͳ�Ƿ���������
//���󣬴���ѭ�����1000��ӡ"test3 app run"

#ifndef _BS_TEST3_APP_H_
#define _BS_TEST3_APP_H_

#include "Arduino.h"
#include "SampleApp.h"
#include "pt.h"

class Test3App : public SampleApp
{
public:
	Test3App(unsigned int appID);
	void init();
	void run();
private:
	int runTask();
	struct pt pt;
};

#endif