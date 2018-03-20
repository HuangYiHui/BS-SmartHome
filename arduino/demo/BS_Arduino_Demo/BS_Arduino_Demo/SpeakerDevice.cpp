#include "SpeakerDevice.h"

//��ΪIRremote����Tone���ͻ������ѡ���Ա���
#ifndef CUR_SYSTEM_IN

SpeakerDevice::SpeakerDevice(unsigned int deviceID, devicePin pin) : SampleDevice(deviceID)
{
	this->pin = pin;
}

void SpeakerDevice::init()
{
	pinMode(pin, OUTPUT);

	state = DEVICE_STATE_READY;
}

void SpeakerDevice::speak(unsigned int frequency, unsigned long duration = 0)
{
	tone(pin, frequency, duration);
}

void SpeakerDevice::noSpeak()
{
	noTone(pin);
}

#endif