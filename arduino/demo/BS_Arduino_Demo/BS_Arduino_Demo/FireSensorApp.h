#ifndef _BS_FIRE_SENSOR_APP_H_
#define _BS_FIRE_SENSOR_APP_H_

#include "cfg.h"
#include "WithCommandApp.h"
#include "pt.h"
#include "FireSensorDevice.h"

class FireSensorApp : public WithCommandApp
{
public:
	FireSensorApp(FireSensorDevice& fireSensor);
	void init();
private:
	void exeCmd();
	int exeTask();
	FireSensorDevice& fireSensor;
	struct pt pt;
};
#endif