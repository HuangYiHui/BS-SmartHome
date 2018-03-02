#ifndef _BS_FIRE_SENSOR_APP_H_
#define _BS_FIRE_SENSOR_APP_H_

#include "cfg.h"
#include "SampleApp.h"
#include "pt.h"
#include "FireSensorDevice.h"

class FireSensorApp : public SampleApp
{
public:
	FireSensorApp(unsigned int appID, FireSensorDevice& fireSensor);
	void init();
	void run();
private:
	int runTask();
	FireSensorDevice& fireSensor;
	struct pt pt;
};
#endif