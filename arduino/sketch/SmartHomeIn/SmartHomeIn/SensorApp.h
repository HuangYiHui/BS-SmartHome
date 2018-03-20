#ifndef _BS_SENSOR_APP_H_
#define _BS_SENSOR_APP_H_

#include "SampleApp.h"
#include "SensorDevice.h"
#include "SensorAppCmd.h"
#include "pt.h"

struct SensorTask
{
	SensorDevice* sensor;
	unsigned int uploadInterval;
	bool isUploadSensorValue;
	bool isCirCularlyUploadSensorValue;
	struct pt pt;

	SensorTask()
	{
		isUploadSensorValue = false;
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
	SensorApp(unsigned int appID);
	~SensorApp();
	void addSensorTask(SensorDevice* sensor, unsigned int uploadInterval, bool isCirCularlyUploadSensorValue);
	void init();
	void run();
	void setUploadInterval(unsigned int interval);

private:
	LinkedList<SensorTask*> sensorTaskList;
	void prcAppMsg();
	void uploadSensorValue(SensorDevice* sensor);
	int runCirCularlyUploadSensorValueTask(SensorTask* task);
};

#endif