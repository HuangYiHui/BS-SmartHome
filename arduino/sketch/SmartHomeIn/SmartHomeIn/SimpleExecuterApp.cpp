#include "SimpleExecuterApp.h"

SimpleExecuterApp::SimpleExecuterApp()
{
	this->appID = APP_ID_SIMPLE_EXECUTER;
}

SimpleExecuterApp::~SimpleExecuterApp()
{
	while(executerList.size() > 0){
		SimpleExecuterDevice* executer = executerList.remove(0);
		delete executer;
		executer = NULL;
	}
}

void SimpleExecuterApp::addExecuter(SimpleExecuterDevice* executer)
{
	if(executer != NULL){
		executerList.add(executer);
	}
}

void SimpleExecuterApp::init()
{
	for(int i=0; i<executerList.size();i++){
		executerList.get(i)->start();
	}
}

void SimpleExecuterApp::appMsgReceivedCallback(AppMsg& msg)
{
	if(msg.len < 1)
		return;
	
	unsigned char cmd = msg.data[0];
	unsigned char executerID = msg.data[1];
	SimpleExecuterDevice* executer = NULL;
	if(CMD_GET_SIMPLE_EXECUTER_STATE == cmd ||
		CMD_OPEN_SIMPLE_EXECUTER == cmd ||
		CMD_CLOSE_SIMPLE_EXECUTER == cmd)
	{
		if(msg.len < 2)
			return;

		for(int i=0; i<executerList.size();i++){
			if(executerList.get(i)->getExecuterID() == executerID){
				executer = executerList.get(i);
				break;
			}
		}

		if(executer == NULL)
			return;
	}

	if(CMD_GET_SIMPLE_EXECUTER_STATE == cmd){
		if(msg.len != 3)
			return;

		AppMsg responseMsg;
		responseMsg.len = 3;
		responseMsg.data = new unsigned char[3];
		//»Ø¸´Ö´ÐÐÆ÷×´Ì¬ÃüÁî£¬¸ñÊ½£º"1byteÃüÁîÍ·+1byteÖ´ÐÐÆ÷Éè±¸ID+1byte×´Ì¬"
		responseMsg.data[0] = CMD_RESPONSE_EXECUTER_STATE;
		responseMsg.data[1] = executer->getExecuterID();
		if(executer->isOpened())
			responseMsg.data[2] = FLAG_EXECUTER_ON;
		else
			responseMsg.data[2] = FLAG_EXECUTER_OFF;

		unsigned char appID = msg.data[2];
		sendMsg(responseMsg, appID);

	}else if(CMD_OPEN_SIMPLE_EXECUTER == cmd){
		executer->openExecuter();
		noticeLCDSocketStateChange(executer);
	}else if(CMD_CLOSE_SIMPLE_EXECUTER == cmd){
		executer->closeExecuter();
		noticeLCDSocketStateChange(executer);
	}
}

void SimpleExecuterApp::noticeLCDSocketStateChange(SimpleExecuterDevice* executer)
{
	AppMsg msg;
	msg.len = 3;
	msg.data = new unsigned char[3];
	msg.data[0] = CMD_NOTICE_SOCKET_STATE_CHANGE;
	bool isOpend = executer->isOpened();
	if(executer->getExecuterID() == 0x01){
		msg.data[1] = FLAG_SOCKET1;
		if(isOpend)
			msg.data[2] = FLAG_SOCKET_ON;
		else
			msg.data[2] = FLAG_SOCKET_OFF;
		sendMsg(msg, APP_ID_LCD);
	}else if(executer->getExecuterID() == 0x02){
		msg.data[1] = FLAG_SOCKET2;
		if(isOpend)
			msg.data[2] = FLAG_SOCKET_ON;
		else
			msg.data[2] = FLAG_SOCKET_OFF;
		sendMsg(msg, APP_ID_LCD);
	}else if(executer->getExecuterID() == 0x03){
		msg.data[1] = FLAG_SOCKET3;
		if(isOpend)
			msg.data[2] = FLAG_SOCKET_ON;
		else
			msg.data[2] = FLAG_SOCKET_OFF;
		sendMsg(msg, APP_ID_LCD);
	}
}