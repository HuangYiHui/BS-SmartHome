#include "NoticeOutSensorValueApp.h"
NoticeOutSensorValueApp::NoticeOutSensorValueApp(DHT11Device& dht11, SensorDevice& pm25, SensorDevice& gy30 , SensorDevice& fc28)
		:
	dht11(dht11),
	pm25(pm25),
	gy30(gy30),
	fc28(fc28)
{
	this->appID = APP_ID_NOTICE_OUT_SENSOR_VALUE;
}

void NoticeOutSensorValueApp::init()
{
	dht11.start();
	gy30.start();
	pm25.start();
	fc28.start();
	PT_INIT(&pt);
}
void NoticeOutSensorValueApp::run(){
	runNoticeTask();
}
int NoticeOutSensorValueApp::runNoticeTask()
{
	PT_BEGIN(&pt);
	while(true){
		float thh[3];
		dht11.readSensorValue(thh);
		sendValue(
			thh[0], 
			thh[1], 
			thh[2], 
			pm25.getSensorValue(), 
			gy30.getSensorValue(), 
			fc28.getSensorValue());
		PT_TIMER_DELAY(&pt, 3000);
	}
	PT_END(&pt);
}

void NoticeOutSensorValueApp::sendValue(
		float temperature, 
		float humidity, 
		float heat,
		float pm25,
		float lightIntensity,
		float solidHumidity)
{
	AppMsg msg;
	msg.len = 25;
	msg.data = new unsigned char[25];
	msg.data[0] = CMD_OUT_SENSOR_VALUES_COMING;
	Tool::floatTo4Bytes(temperature, &(msg.data[1]));
	Tool::floatTo4Bytes(humidity, &(msg.data[5]));
	Tool::floatTo4Bytes(heat, &(msg.data[9]));
	Tool::floatTo4Bytes(pm25, &(msg.data[13]));
	Tool::floatTo4Bytes(lightIntensity, &(msg.data[17]));
	Tool::floatTo4Bytes(solidHumidity, &(msg.data[21]));
	sendMsgToZigbee(msg);
}

