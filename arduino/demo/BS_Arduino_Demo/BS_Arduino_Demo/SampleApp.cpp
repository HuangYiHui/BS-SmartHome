#include "SampleApp.h"

SampleApp::SampleApp(unsigned int appID) : appID(appID)
{
	state = APP_STATE_UNREADY;
}

SampleApp::~SampleApp()
{
	while(msgList.size()>0)
	{
		AppMsg* msg = msgList.remove(0);
		delete msg;
	}
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

unsigned int SampleApp::getAppID()
{
	return appID;
}

void SampleApp::sendMsg(AppMsg& msg, unsigned int appID)
{
	API.sendAppMsg(msg, appID);
}

void SampleApp::receiveMsg(AppMsg& msg)
{
	msgList.add(new AppMsg(msg));
}

void SampleApp::uploadDataByZigbee(AppMsg& msg)
{
	if(msg.len<1)
		return;

	AppMsg zigbeeMsg;
	zigbeeMsg.len = msg.len+2;
	zigbeeMsg.data = new unsigned char[msg.len+2];
	zigbeeMsg.data[0] = CMD_UPLOAD_DATA % 256;
	zigbeeMsg.data[1] = CMD_UPLOAD_DATA / 256;
	for(int i=0;i<msg.len;i++){
		zigbeeMsg.data[i+2] = msg.data[i];
	}
	API.sendAppMsg(zigbeeMsg, APP_ID_ZIGBEE);
}
