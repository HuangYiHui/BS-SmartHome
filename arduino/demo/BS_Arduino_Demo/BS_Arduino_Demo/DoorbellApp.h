#include "SystemCfg.h"
//因为IRremote库与Tone库冲突，这里选择性编译
#ifndef CUR_SYSTEM_IN

#ifndef _BS_DOORBELL_APP_H_
#define _BS_DOORBELL_APP_H_

#include "SampleApp.h"
#include "TouchSensorDevice.h"
#include "SpeakerDevice.h"
#include "pt.h"

class DoorbellApp : public SampleApp
{
public:
	DoorbellApp(unsigned int appID, TouchSensorDevice& touchSensor, SpeakerDevice& speakerDevice);
	void init();
	void run();
private:
	TouchSensorDevice& touchSensor;
	SpeakerDevice& speaker;
	struct pt pt;

	int runTask();
};


#endif
#endif