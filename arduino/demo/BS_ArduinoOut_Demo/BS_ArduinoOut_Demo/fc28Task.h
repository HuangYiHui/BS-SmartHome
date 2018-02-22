#ifndef _BS_FC28_H_
#define _BS_FC28_H_

#include "Arduino.h"
#include "cfg.h"
#include "pt.h"

#define PIN_FC28	_PIN_FC28_	//土壤湿度传感器引脚

void initFC28Task();
static int run();
void runFC28Task();

#endif