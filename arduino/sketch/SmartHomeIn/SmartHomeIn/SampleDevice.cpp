#include "SampleDevice.h"

SampleDevice::SampleDevice(unsigned int deviceID)
{
	this->deviceID = deviceID;
	state = DEVICE_STATE_CLOSED;
}

void SampleDevice::open()
{
	state = DEVICE_STATE_UNREADY;
}

void SampleDevice::init()
{
	state = DEVICE_STATE_READY;
}


void SampleDevice::start()
{
	state = DEVICE_STATE_WORKING;
}

void SampleDevice::stop()
{
	state = DEVICE_STATE_READY;
}

void SampleDevice::reset()
{
	state = DEVICE_STATE_UNREADY;
}

void SampleDevice::close()
{
	state = DEVICE_STATE_CLOSED;
}

deviceState SampleDevice::getState()
{
	return state;
}

unsigned int SampleDevice::getDeviceID(){
	return deviceID;
}

void SampleDevice::begin()
{
	open();
	init();
	start();
}

void SampleDevice::end()
{
	stop();
	close();
}