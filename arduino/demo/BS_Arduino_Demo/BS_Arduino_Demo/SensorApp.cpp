#include "SensorApp.h"

SensorApp::SensorApp(unsigned int appID, SensorDevice& sensor) : SampleApp(appID), sensor(sensor)
{
	uploadInterval = 60000;
	isUploadSensorValue = false;
	isCirCularlyUploadSensorValue = true;
	isRunAppByDefault = false;

	state = APP_STATE_UNREADY;
}

void SensorApp::setUploadInterval(unsigned int interval)
{
	if(interval > 0)
		this->uploadInterval = interval;
}

void SensorApp::init()
{
	sensor.begin();
	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void SensorApp::prcAppMsg()
{
	if(msgList.size() < 1)
		return;
	AppMsg* msg = msgList.remove(0);
	if(msg->len < 2){
		delete msg;
		return;
	}
	
	int cmd = msg->data[0] + 256 * msg->data[1];

	if(CMD_RUN_APP_BY_DEFAULT == cmd){
		isRunAppByDefault = true;
	}else if(CMD_UPLOAD_SENSOR_VALUE == cmd){
		isUploadSensorValue = true;
	}else if(CMD_CIRCULARLY_UPLOAD_SENSOR_VALUE == cmd){
		isCirCularlyUploadSensorValue = true;
	}else if(CMD_STOP_UPLOAD_SENSOR_VALUE == cmd){
		isCirCularlyUploadSensorValue = false;
	}else if(CMD_SET_CIRCULARLY_UPLOAD_INTERVAL == cmd){
		//带2个byte参数，表示unsigned int的interval数值
		if(msg->len < 4)
			return;
		unsigned int value = Tool::bytesToInt(&(msg->data[2]));
		if(value > 0){
			uploadInterval = value;
		}
	}

	delete msg;
}

void SensorApp::uploadSensorValue()
{
	float value = sensor.getSensorValue();
	AppMsg msg;
	msg.len = 6;
	msg.data = new unsigned char[6];
	Tool::intTo2Bytes(sensor.getSensorValueIndex(), &(msg.data[0]));
	Tool::floatTo4Bytes(value, &(msg.data[2]));
	uploadDataByZigbee(msg);
//	Serial.print("sensor : ");
//	Serial.println(value);
}

void SensorApp::run()
{
	prcAppMsg();

	if(isRunAppByDefault){
		uploadInterval = 60000;
		isUploadSensorValue = false;
		isCirCularlyUploadSensorValue = true;
		isRunAppByDefault = false;
	}

	if(isUploadSensorValue){
		uploadSensorValue();
		isUploadSensorValue = false;
	}

	if(isCirCularlyUploadSensorValue){
		runCirCularlyUploadSensorValueTask();
	}else{
		PT_INIT(&pt);
	}

}

int SensorApp::runCirCularlyUploadSensorValueTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		uploadSensorValue();
		PT_TIMER_DELAY(&pt, uploadInterval);
	}
	PT_END(&pt);
}