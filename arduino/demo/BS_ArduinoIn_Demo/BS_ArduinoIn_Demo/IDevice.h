/*
	设备接口定义
*/

#ifndef _BS_IDEVICE_H_
#define _BS_IDEVICE_H_

typedef unsigned char deviceState;
typedef unsigned char devicePin;

//设备状态定义
#define DEVICE_STATE_CLOSED		0x31	//关闭状态
#define DEVICE_STATE_UNREADY	0x32	//未准备状态
#define DEVICE_STATE_READY		0x33	//已准备状态
#define DEVICE_STATE_WORKING	0x34	//工作状态

class IDevice
{
	virtual void open() = 0;	//开启，关闭状态 -> 未准备状态
	virtual void init() = 0;	//初始化，未准备状态 -> 已准备状态
	virtual void start() = 0;	//启动，已准备状态 -> 工作状态
	virtual void stop() = 0;	//停止，工作状态 -> 已准备状态
	virtual void reset() = 0;	//重置，-> 未准备状态
	virtual void close() = 0;	//关闭，已准备状态 -> 关闭状态
	virtual deviceState getState() = 0;	//获取状态
};

#endif