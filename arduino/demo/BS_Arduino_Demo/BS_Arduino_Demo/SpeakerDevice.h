#include "cfg.h"
//因为IRremote库与Tone库冲突，这里选择性编译
#ifndef CUR_SYSTEM_IN

#ifndef _BS_SPEAKER_DEVICE_H_
#define _BS_SPEAKER_DEVICE_H_

#include "Arduino.h"
#include "SampleDevice.h"
#include "TonePlayer.h"

class SpeakerDevice : public SampleDevice
{
public:
	SpeakerDevice(devicePin pin);
	void init();
	void speak(unsigned int frequency, unsigned long duration);
	void noSpeak();

private:
	devicePin pin;
};

#endif
#endif