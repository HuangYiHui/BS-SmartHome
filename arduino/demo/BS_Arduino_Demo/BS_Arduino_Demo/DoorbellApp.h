#ifndef _BS_DOORBELL_APP_H_
#define _BS_DOORBELL_APP_H_

#include "WithCommandApp.h"
#include "TouchSensorDevice.h"
#include "SpeakerDevice.h"
#include "pt.h"

class DoorbellApp : public WithCommandApp
{
public:
	DoorbellApp(TouchSensorDevice& touchSensor, SpeakerDevice& speakerDevice);
	void init();
private:
	void exeCmd();
	int exeTask();
	TouchSensorDevice& touchSensor;
	SpeakerDevice& speaker;
	struct pt pt;
};

#endif