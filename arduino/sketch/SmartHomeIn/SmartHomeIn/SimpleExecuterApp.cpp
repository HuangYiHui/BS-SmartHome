#include "SimpleExecuterApp.h"

SimpleExecuterApp::SimpleExecuterApp(unsigned int appID) : SampleApp(appID)
{
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
		executerList.get(i)->begin();
	}
	state = APP_STATE_READY;
}

void SimpleExecuterApp::run()
{
	while(msgList.size()>0){

		AppMsg* msg = msgList.remove(0);
		if(msg->len < 2){
			delete msg;
			return;
		}
	
		int cmd = msg->data[0] + 256 * msg->data[1];
		unsigned int executerID;
		SimpleExecuterDevice* executer = NULL;
		if(CMD_GET_SIMPLE_EXECUTER_STATUS == cmd ||
			CMD_OPEN_SIMPLE_EXECUTER == cmd ||
			CMD_CLOSE_SIMPLE_EXECUTER == cmd)
		{
			if(msg->len < 4){
				delete msg;
				return;
			}

			executerID = msg->data[2] + 256 * msg->data[3];

			for(int i=0; i<executerList.size();i++){
				if(executerList.get(i)->getDeviceID() == executerID){
					executer = executerList.get(i);
					break;
				}
			}

			if(executer == NULL)
				return;
		}

		if(CMD_GET_SIMPLE_EXECUTER_STATUS == cmd){
			if(msg->len != 6){
				delete msg;
				return;
			}
			unsigned int appID = msg->data[4] + 256 * msg->data[5];

			AppMsg responseMsg;
			responseMsg.len = 7;
			responseMsg.data = new unsigned char[7];

			//CMD_RSPONSE_TO_GET_EXECUTER_STATUS, 2byte的命令头 + 2byte的目标appID + 2byte的执行器标志 + 1byte的执行器状态"
			Tool::intTo2Bytes(CMD_RSPONSE_TO_GET_EXECUTER_STATUS , &(responseMsg.data[0]));
			Tool::intTo2Bytes(appID , &(responseMsg.data[2]));
			Tool::intTo2Bytes(executer->getDeviceID() , &(responseMsg.data[4]));
			if(executer->isOpened())
				responseMsg.data[6] = EXECUTER_STATUS_OPENED;
			else
				responseMsg.data[6] = EXECUTER_STATUS_CLOSED;
			sendMsgToZigbee(responseMsg);
		}else if(CMD_OPEN_SIMPLE_EXECUTER == cmd){
			executer->openExecuter();
		}else if(CMD_CLOSE_SIMPLE_EXECUTER == cmd){
			executer->closeExecuter();
		}
	}
}