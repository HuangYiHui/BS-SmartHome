#ifndef _BS_DOORBELL_H_
#define _BS_DOORBELL_H_

#include "Arduino.h"
#include "cfg.h"
#include "pt.h"

#define PIN_BELL	_PIN_BELL_	//����������
#define PIN_TOUCH_SENSOR	_PIN_TOUCH_SENSOR_	//��������������

void initDoorbellTask();
static int run();
void runDoorbellTask();

#endif