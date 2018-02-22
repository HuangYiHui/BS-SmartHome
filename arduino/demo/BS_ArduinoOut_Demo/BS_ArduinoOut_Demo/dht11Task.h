#ifndef _BS_DHT11_TASK_H_
#define _BS_DHT11_TASK_H_

#include "Arduino.h"
#include "cfg.h"
#include "pt.h"
#include "DHT.h"

#define PIN_DHT11 _PIN_DHT11_	//温湿度传感器DHT11引脚
#define DHTTYPE DHT11	//温湿度传感器类型

void initDHT11Task();
static int run();
void runDHT11Task();

#endif