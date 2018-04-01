#include "SensorApp.h"

SensorApp::SensorApp()
{
	this->appID = APP_ID_IN_SENSOR;
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
		sensorTaskList.get(i)->sensor->start();
	}
}

void SensorApp::appMsgReceivedCallback(AppMsg& msg)
{
	/*
		if(msg.len < 1)
			return;
	
		unsigned char cmd = msg.data[0];
		unsigned char sensorID;
		if(CMD_START_CIRCULARLY_UPLOAD_SENSOR_VALUE == cmd ||
			CMD_STOP_CIRCULARLY_UPLOAD_SENSOR_VALUE == cmd ||
			CMD_SET_CIRCULARLY_UPLOAD_INTERVAL == cmd
		){
			if(msg.len < 2)
				return;
			sensorID = msg.data[1];
		}
		
		SensorTask* task = NULL;
		for(int i=0;i<sensorTaskList.size();i++){
			if(sensorTaskList.get(i)->sensor->getSensorID() == sensorID){
				task = sensorTaskList.get(i);
				break;
			}
		}

		if(task == NULL)
			return;

		if(CMD_START_CIRCULARLY_UPLOAD_SENSOR_VALUE == cmd){
			task->isCirCularlyUploadSensorValue = true;
		}else if(CMD_STOP_CIRCULARLY_UPLOAD_SENSOR_VALUE == cmd){
			task->isCirCularlyUploadSensorValue = false;
		}else if(CMD_SET_CIRCULARLY_UPLOAD_INTERVAL == cmd){
			//带2个byte参数，表示unsigned int的interval数值
			if(msg.len < 4)
				return;
			unsigned int value = Tool::bytesToInt(&(msg.data[2]));
			if(value > 0){
				task->uploadInterval = value;
			}
		}
		*/
}

void SensorApp::uploadSensorValue(SensorDevice* sensor)
{
	float value = sensor->getSensorValue();
	AppMsg msg;
	msg.len = 7;
	msg.data = new unsigned char[7];
	msg.data[0] = CMD_UPLOAD_DATA;
	msg.data[1] = UPLOAD_DATA_INDEX_SENSOR_VALUE;
	msg.data[2] = sensor->getSensorID();
	Tool::floatTo4Bytes(value, &(msg.data[3]));
	sendMsgToZigbee(msg);
}

void SensorApp::run()
{
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