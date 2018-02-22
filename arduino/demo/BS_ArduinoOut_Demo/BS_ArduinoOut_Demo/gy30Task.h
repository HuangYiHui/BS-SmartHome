#ifndef _BS_GY30_H_
#define _BS_GY30_H_

#include "Arduino.h"
#include "cfg.h"
#include "pt.h"
#include "Wire.h"
#include "BH1750xtra.h"

#define PIN_GY30_SCL	_PIN_GY30_SCL_	//光强传感器GY30的SCL引脚
#define PIN_GY30_SDA	_PIN_GY30_SCL_	//光强传感器GY30的SDA引脚
#define PIN_LED1	_PIN_LED1_	//灯光1引脚
#define PIN_LED2	_PIN_LED1_	//灯光1引脚

void initGY30Task();
static int run();
void runGY30Task();

#endif