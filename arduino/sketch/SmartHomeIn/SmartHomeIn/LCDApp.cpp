#include "LCDApp.h"

LCDApp::LCDApp(unsigned int appID, LCDDevice& lcd) : SampleApp(appID), lcd(lcd)
{
}

void LCDApp::init()
{
	lcd.begin();
	lcd.println("1234567890");
	state = APP_STATE_READY;
}

void LCDApp::run()
{
}