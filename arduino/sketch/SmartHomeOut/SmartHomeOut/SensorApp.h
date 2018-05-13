#ifndef _BS_SENSOR_APP_H_
#define _BS_SENSOR_APP_H_

#include "SampleApp.h"
#include "SensorDevice.h"
#include "SensorAppCmd.h"
#include "ZigbeeAppCmd.h"
#include "pt.h"
#include "LinkedList.h"

struct SensorTask
{
	SensorDevice* sensor;	//������
	unsigned int uploadInterval;	//ʱ����
	bool isCirCularlyUploadSensorValue;	//�Ƿ�ѭ���ϴ�
	struct pt pt;

	SensorTask()
	{
		isCirCularlyUploadSensorValue = true;
		PT_INIT(&pt);
	}
	~SensorTask()
	{
		delete sensor;
		sensor = NULL;
	}
};

class SensorApp : public SampleApp
{
public:
	SensorApp();
	~SensorApp();
	//��Ӵ���������
	void addSensorTask(SensorDevice* sensor, unsigned int uploadInterval, bool isCirCularlyUploadSensorValue);
	void init();	//��ʼ��
	void run();		//����
	void appMsgReceivedCallback(AppMsg& msg);	//Ӧ����Ϣ�ص�
private:
	LinkedList<SensorTask*> sensorTaskList;
	//�ϴ�������ֵ
	void uploadSensorValue(SensorDevice* sensor);
	//�����ϴ�����
	int runCirCularlyUploadSensorValueTask(SensorTask* task);
	SensorTask* findUploadTaskByID(unsigned char sensorID);
};

#endif