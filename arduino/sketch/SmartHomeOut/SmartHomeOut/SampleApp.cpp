#include "SampleApp.h"

void SampleApp::init(){}

void SampleApp::run(){}

void SampleApp::stop(){}

void SampleApp::reset(){}

void SampleApp::setAppID(unsigned char appID){
	this->appID = appID;
}

unsigned char SampleApp::getAppID()
{
	return appID;
}

void SampleApp::sendMsg(AppMsg& msg, unsigned char appID)
{
	API.sendAppMsg(msg, appID);
}

void SampleApp::appMsgReceivedCallback(AppMsg& msg)
{
}

void SampleApp::sendMsgToZigbee(AppMsg& msg)
{
	API.sendAppMsg(msg, APP_ID_OUT_ZIGBEE);
}
