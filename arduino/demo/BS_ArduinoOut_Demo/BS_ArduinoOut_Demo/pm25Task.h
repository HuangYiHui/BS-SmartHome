#ifndef _BS_PM25_H_
#define _BS_PM25_H_

#include "Arduino.h"
#include "cfg.h"
#include "pt.h"

#define PIN_PM25_LED	_PIN_PM25_LED_	//pm2.5(GP2Y1014AU)ledÒý½Å
#define PIN_PM25_VO	_PIN_PM25_VO_	//pm2.5(GP2Y1014AU)VOÒý½Å

void initPM25Task();
static int run();
void runPM25Task();

#endif