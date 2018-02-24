#include "SampleSystem.h"

SampleSystem::SampleSystem()
{
	state = SYSTEM_STATE_UNREADY;
}

void SampleSystem::init()
{
	state = SYSTEM_STATE_READY;
}

void SampleSystem::start()
{
	state = SYSTEM_STATE_WORKING;
}

void SampleSystem::stop()
{
	state = SYSTEM_STATE_READY;
}

void SampleSystem::reset()
{
	state = SYSTEM_STATE_UNREADY;
}

systemState SampleSystem::getState()
{
	return state;
}