#ifndef _BS_ISYSTEM_H_
#define _BS_ISYSTEM_H_

//调使用
#include <MemoryFree.h>

#include "Arduino.h"
#include "IApp.h"

class ISystem
{
public:
	virtual void init() = 0;	//初始化
	virtual void start() = 0;	//开始运行
	virtual void stop() = 0;	//停止运行
	virtual void reset() = 0;	//重置系统
	virtual void installApp(IApp* app) = 0;	//安装应用
	virtual void sendAppMsg(AppMsg& msg, unsigned char appID) = 0;	//发送应用消息
};
#endif