
#include "SystemCfg.h"
//因为IRremote库与Tone库冲突，这里选择性编译
#ifdef CUR_SYSTEM_IN

#ifndef _BS_IRREMOTE_DEVICE_H_
#define _BS_IRREMOTE_DEVICE_H_

#include "Arduino.h"
#include "SampleDevice.h"
#include "IRremote.h"

class IRRemoteDevice : public SampleDevice, public IRrecv
{
public:
	IRRemoteDevice(devicePin pin);
	void init();
};

#endif

#endif