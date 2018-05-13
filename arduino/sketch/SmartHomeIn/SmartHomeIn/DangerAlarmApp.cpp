#include "DangerAlarmApp.h"

DangerAlarmApp::DangerAlarmApp(SimpleSensorDevice& fireSensor, SimpleSensorDevice& harmfulGasSensor, SimpleExecuterDevice& alarm) 
	: 
	fireSensor(fireSensor),
	harmfulGasSensor(harmfulGasSensor),
	alarm(alarm)
{
	lastStateDanger = false;
	this->appID = APP_ID_DANGER_ALARM;
}

void DangerAlarmApp::init()
{
	fireSensor.start();
	alarm.start();
}

void DangerAlarmApp::run()
{
	//сп╩П
	if(fireSensor.getSensorValue() == 0 ||
		harmfulGasSensor.getSensorValue() > 250
	){
		alarm.openExecuter();
		if( ! lastStateDanger){
			noticeLCDIsDanger(true);
			if(fireSensor.getSensorValue() == 0){
				uploadSensorValue(fireSensor);
			}

			if(harmfulGasSensor.getSensorValue() > 250){
				uploadSensorValue(harmfulGasSensor);
			}
		}
		lastStateDanger = true;
		/*
		Serial.println("harmfulGasValue : ");
		Serial.println(harmfulGasSensor.getSensorValue());
		Serial.println("openExecuter");
		*/

	}else{
		alarm.closeExecuter();
		if(lastStateDanger){
			noticeLCDIsDanger(false);
			uploadSensorValue(fireSensor);
			uploadSensorValue(harmfulGasSensor);
		}

		lastStateDanger = false;
	}
}

void DangerAlarmApp::noticeLCDIsDanger(bool isDanger)
{
	AppMsg msg;
	msg.len = 2;
	msg.data = new unsigned char[2];
	msg.data[0] = CMD_NOTICE_IS_DANGER;
	if(isDanger)
		msg.data[1] = FLAG_DANGER;
	else
		msg.data[1] = FLAG_NO_DANGER;
	sendMsg(msg, APP_ID_LCD);
}

void DangerAlarmApp::uploadSensorValue(SimpleSensorDevice& sensor)
{
	float value = sensor.getSensorValue();
	AppMsg msg;
	msg.len = 7;
	msg.data = new unsigned char[7];
	msg.data[0] = CMD_UPLOAD_DATA;
	msg.data[1] = UPLOAD_DATA_INDEX_SENSOR_VALUE;
	msg.data[2] = sensor.getSensorID();
	Tool::floatTo4Bytes(value, &(msg.data[3]));
	sendMsgToZigbee(msg);
}