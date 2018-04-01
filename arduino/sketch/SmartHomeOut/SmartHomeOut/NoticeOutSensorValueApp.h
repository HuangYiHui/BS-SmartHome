#ifndef _BS_THH_UPDATA_APP_H_
#define _BS_THH_UPDATA_APP_H_

#include "SampleApp.h"
#include "pt.h"
#include "DHT11Device.h"
#include "SimpleSensorDevice.h"

class NoticeOutSensorValueApp : public SampleApp
{
private:
	DHT11Device& dht11;
	SensorDevice& gy30;
	SensorDevice& pm25;
	SensorDevice& fc28;
	struct pt pt;
	int runNoticeTask();
	void sendValue(
		float temperature, 
		float humidity, 
		float heat,
		float pm25,
		float lightIntensity,
		float solidHumidity);
public:
	NoticeOutSensorValueApp(DHT11Device& dht11, SensorDevice& pm25, SensorDevice& gy30, SensorDevice& fc28);
	void init();
	void run();
};

#endif