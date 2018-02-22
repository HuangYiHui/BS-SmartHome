#ifndef _BS_DOORBELL_H_
#define _BS_DOORBELL_H_

#include "Arduino.h"
#include "cfg.h"
#include "pt.h"

#define PIN_BELL	_PIN_BELL_	//ÑïÉùÆ÷Òý½Å
#define PIN_TOUCH_SENSOR	_PIN_TOUCH_SENSOR_	//´¥Ãþ´«¸ÐÆ÷Òý½Å

void initDoorbellTask();
static int run();
void runDoorbellTask();

#endif