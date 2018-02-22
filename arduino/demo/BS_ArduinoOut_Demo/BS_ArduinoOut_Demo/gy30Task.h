#ifndef _BS_GY30_H_
#define _BS_GY30_H_

#include "Arduino.h"
#include "cfg.h"
#include "pt.h"
#include "Wire.h"
#include "BH1750xtra.h"

#define PIN_GY30_SCL	_PIN_GY30_SCL_	//��ǿ������GY30��SCL����
#define PIN_GY30_SDA	_PIN_GY30_SCL_	//��ǿ������GY30��SDA����
#define PIN_LED1	_PIN_LED1_	//�ƹ�1����
#define PIN_LED2	_PIN_LED1_	//�ƹ�1����

void initGY30Task();
static int run();
void runGY30Task();

#endif