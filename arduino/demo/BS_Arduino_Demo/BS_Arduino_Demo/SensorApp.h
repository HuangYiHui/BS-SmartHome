#ifndef _BS_SENSOR_APP_H_
#define _BS_SENSOR_APP_H_

#include "SampleApp.h"
#include "SensorDevice.h"
#include "SensorAppCmd.h"
#include "pt.h"

class SensorApp : public SampleApp
{
public:
	SensorApp(unsigned int appID, SensorDevice& sensor);
	void init();
	void run();
	void setUploadInterval(unsigned int interval);

private:
	SensorDevice& sensor;
	struct pt pt;
	unsigned int uploadInterval;

	bool isRunAppByDefault;
	bool isUploadSensorValue;
	bool isCirCularlyUploadSensorValue;

	void prcAppMsg();
	void uploadSensorValue();
	int runCirCularlyUploadSensorValueTask();
};

#endif