#ifndef _BS_TEST2_APP_H_
#define _BS_TEST2_APP_H_

#include "Arduino.h"
#include "SampleApp.h"
#include "pt.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Debugger.h"

class Test2App : public SampleApp
{
public:
	Test2App(unsigned int appID);
	void init();
	void run();
private:
	LiquidCrystal_I2C* lcd;
	int exeTask();
	struct pt pt;
};

#endif