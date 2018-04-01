#include "THHUpdateApp.h"

THHUpdateApp::THHUpdateApp(DHT11Device& dht11) : dht11(dht11)
{
	this->appID = APP_ID_THH_UPDATA;
}

void THHUpdateApp::init()
{
	dht11.start();
	PT_INIT(&pt);
}

int THHUpdateApp::runUpdateTask()
{
	PT_BEGIN(&pt);
	while(true){
		float thh[3];
		dht11.readSensorValue(thh);
		sendToLCD(thh[0], thh[1], thh[2]);
		PT_TIMER_DELAY(&pt, 3000);
	}
	PT_END(&pt);
}

void THHUpdateApp::sendToLCD(float temperature, float humidity, float heat)
{
	AppMsg msg;
	msg.len = 13;
	msg.data = new unsigned char[13];
	msg.data[0] = CMD_NOTICE_IN_SENSOR_VALUES;
	Tool::floatTo4Bytes(temperature, &(msg.data[1]));
	Tool::floatTo4Bytes(humidity, &(msg.data[5]));
	Tool::floatTo4Bytes(heat, &(msg.data[9]));
	sendMsg(msg, APP_ID_LCD);
}

void THHUpdateApp::run(){
	runUpdateTask();
}