#include "SensorApp.h"

SensorApp::SensorApp()
{
	this->appID = APP_ID_OUT_SENSOR;
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
		PT_INIT(&(sensorTaskList.get(i)->pt));
	}
}

void SensorApp::appMsgReceivedCallback(AppMsg& msg)
{
	if(msg.len < 1)
		return;
	
	unsigned char cmd = msg.data[0];
	if(CMD_UPLOAD_ALL_DEVICE_VALUE == cmd && msg.len == 1){
		for(int i=0;i<sensorTaskList.size();i++){
			uploadSensorValue(sensorTaskList.get(i)->sensor);
		}
	}else if(CMD_START_CIRCULARLY_UPLOAD_SENSOR_VALUE == cmd && msg.len == 2){
		SensorTask* task = findUploadTaskByID(msg.data[1]);
		if(task != NULL){
			task->isCirCularlyUploadSensorValue = true;
		}
	}else if(CMD_STOP_CIRCULARLY_UPLOAD_SENSOR_VALUE == cmd && msg.len == 2){
		SensorTask* task = findUploadTaskByID(msg.data[1]);
		if(task != NULL){
			task->isCirCularlyUploadSensorValue = false;
		}
	}else if(CMD_SET_CIRCULARLY_UPLOAD_INTERVAL == cmd && msg.len == 4){
		SensorTask* task = findUploadTaskByID(msg.data[1]);
		if(task != NULL){
			unsigned int interval = Tool::bytesToInt(&(msg.data[2]));
			if(interval > 0)
				task->uploadInterval = interval;
		}
	}else if(CMD_UPLOAD_SENSOR_VALUE == cmd && msg.len == 2){
		SensorTask* task = findUploadTaskByID(msg.data[1]);
		if(task != NULL){
			uploadSensorValue(task->sensor);
		}
	}
}

SensorTask* SensorApp::findUploadTaskByID(unsigned char sensorID)
{
	if(sensorTaskList.size()>0){
		for(int i=0;i<sensorTaskList.size();i++){
			if(sensorTaskList.get(i)->sensor->getSensorID() == sensorID){
				return sensorTaskList.get(i);
			}
		}
	}
	
	return NULL;
	
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
