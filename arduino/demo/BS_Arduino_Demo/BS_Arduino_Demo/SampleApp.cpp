#include "SampleApp.h"

SampleApp::SampleApp()
{
	state = APP_STATE_UNREADY;
}

void SampleApp::init()
{
	state = APP_STATE_READY;
}

void SampleApp::run()
{
	state = APP_STATE_WORKING;
}

void SampleApp::stop()
{
	state = APP_STATE_READY;
}

void SampleApp::reset()
{
	state = APP_STATE_UNREADY;
}

appState SampleApp::getState()
{
	return state;
}