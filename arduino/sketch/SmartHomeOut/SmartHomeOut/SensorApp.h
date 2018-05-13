#ifndef _BS_SENSOR_APP_H_
#define _BS_SENSOR_APP_H_

#include "SampleApp.h"
#include "SensorDevice.h"
#include "SensorAppCmd.h"
#include "ZigbeeAppCmd.h"
#include "pt.h"
#include "LinkedList.h"

struct SensorTask
{
	SensorDevice* sensor;	//传感器
	unsigned int uploadInterval;	//时间间隔
	bool isCirCularlyUploadSensorValue;	//是否循环上传
	struct pt pt;

	SensorTask()
	{
		isCirCularlyUploadSensorValue = true;
		PT_INIT(&pt);
	}
	~SensorTask()
	{
		delete sensor;
		sensor = NULL;
	}
};

class SensorApp : public SampleApp
{
public:
	SensorApp();
	~SensorApp();
	//添加传感器任务
	void addSensorTask(SensorDevice* sensor, unsigned int uploadInterval, bool isCirCularlyUploadSensorValue);
	void init();	//初始化
	void run();		//运行
	void appMsgReceivedCallback(AppMsg& msg);	//应用消息回调
private:
	LinkedList<SensorTask*> sensorTaskList;
	//上传传感器值
	void uploadSensorValue(SensorDevice* sensor);
	//运行上传任务
	int runCirCularlyUploadSensorValueTask(SensorTask* task);
	SensorTask* findUploadTaskByID(unsigned char sensorID);
};

#endif