#ifndef _BS_DHT11_TASK_H_
#define _BS_DHT11_TASK_H_

#include "Arduino.h"
#include "cfg.h"
#include "pt.h"
#include "DHT.h"

#define PIN_DHT11 _PIN_DHT11_	//��ʪ�ȴ�����DHT11����
#define DHTTYPE DHT11	//��ʪ�ȴ���������

void initDHT11Task();
static int run();
void runDHT11Task();

#endif