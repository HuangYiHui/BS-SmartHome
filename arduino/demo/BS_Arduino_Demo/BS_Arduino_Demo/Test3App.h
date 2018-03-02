//本app用于测试系统是否正常运行
//现象，串口循环间隔1000打印"test3 app run"

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