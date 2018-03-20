#include "SensorApp.h"

SensorApp::SensorApp(unsigned int appID) : SampleApp(appID)
{
}

SensorApp::~SensorApp()
{
	while(sensorTaskList.size()>0){
		SensorTask* sensorTask = sensorTaskList.remove(0);
		delete sensorTask;
		sensorTask = NULL;
	}
}

void SensorApp::addSensorTask(SensorDevice* sensor, unsigned int uploadInterval, bool isCirCularlyUploadSensorValue)
{
	if(sensor != NULL){
		SensorTask* sensorTask = new SensorTask();
		sensorTask->sensor = sensor;
		sensorTask->uploadInterval = uploadInterval;
		sensorTask->isCirCularlyUploadSensorValue = isCirCularlyUploadSensorValue;
		sensorTaskList.add(sensorTask);
	}
}

void SensorApp::init()
{
	for(int i=0;i<sensorTaskList.size();i++){
		sensorTaskList.get(i)->sensor->begin();
	}

	state = APP_STATE_READY;
}

void SensorApp::prcAppMsg()
{
	while(msgList.size()>0){

		//Serial.println("sensor app get msg");

		AppMsg* msg = msgList.remove(0);
		if(msg->len < 2){
			delete msg;
			return;
		}
	
		int cmd = msg->data[0] + 256 * msg->data[1];
		unsigned int deviceID;
		if(CMD_START_CIRCULARLY_UPLOAD_SENSOR_VALUE == cmd ||
			CMD_STOP_CIRCULARLY_UPLOAD_SENSOR_VALUE == cmd ||
			CMD_SET_CIRCULARLY_UPLOAD_INTERVAL == cmd
		){
			if(msg->len < 4){
				delete msg;
				return;
			}
			deviceID = msg->data[2] + 256 * msg->data[3];
		//	Serial.print("deviceID : ");
		//	Serial.print(deviceID, HEX);
		}
		
		SensorTask* task = NULL;
		for(int i=0;i<sensorTaskList.size();i++){
			if(sensorTaskList.get(i)->sensor->getDeviceID() == deviceID){
				task = sensorTaskList.get(i);
			//	Serial.println("found device");
				break;
			}
		}

		if(task == NULL){
			delete msg;
			return;
		}

		if(CMD_START_CIRCULARLY_UPLOAD_SENSOR_VALUE == cmd){
			task->isCirCularlyUploadSensorValue = true;
		}else if(CMD_STOP_CIRCULARLY_UPLOAD_SENSOR_VALUE == cmd){
			task->isCirCularlyUploadSensorValue = false;
		}else if(CMD_SET_CIRCULARLY_UPLOAD_INTERVAL == cmd){
			//带2个byte参数，表示unsigned int的interval数值
			if(msg->len < 6)
				return;
			unsigned int value = Tool::bytesToInt(&(msg->data[4]));
			if(value > 0){
				task->uploadInterval = value;
			}
		}

		delete msg;
	}
}

void SensorApp::uploadSensorValue(SensorDevice* sensor)
{
	float value = sensor->getSensorValue();
	AppMsg msg;
	msg.len = 8;
	msg.data = new unsigned char[8];
	Tool::intTo2Bytes(UPLOAD_DATA_INDEX_SENSOR_VALUE, msg.data);
	Tool::intTo2Bytes(sensor->getDeviceID(), &(msg.data[2]));
	Tool::floatTo4Bytes(value, &(msg.data[4]));
	uploadDataByZigbee(msg);
}

void SensorApp::run()
{
	prcAppMsg();

	for(int i=0;i<sensorTaskList.size();i++){
		SensorTask* task = sensorTaskList.get(i);

		if(task->isCirCularlyUploadSensorValue){
			runCirCularlyUploadSensorValueTask(task);
		}else{
			PT_INIT(&(task->pt));
		}
	}

}

int SensorApp::runCirCularlyUploadSensorValueTask(SensorTask* task)
{
	pt* pt = &(task->pt);
	PT_BEGIN(pt);
	while(true)
	{
		uploadSensorValue(task->sensor);
		PT_TIMER_DELAY(pt, task->uploadInterval);
	}
	PT_END(pt);
}