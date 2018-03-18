#include "Test2App.h"

Test2App::Test2App(unsigned int appID) : SampleApp(appID), lcd(lcd)
{
	lcd = new LiquidCrystal_I2C(0x3F,16,2);
}
void Test2App::init()
{
	PT_INIT(&pt);
	lcd->init();                  // 初始化LCD
	lcd->backlight();             //设置LCD背景等亮

	lcd->setCursor(0,0);
	lcd->print("test2AppID:");
	lcd->print(appID, HEX);
}

void Test2App::run()
{
	exeTask();
}

int Test2App::exeTask()
{
	PT_BEGIN(&pt);
	while(true){
		PT_TIMER_DELAY(&pt, 1000);
		
		while(msgList.size()>0){
			AppMsg* msg = msgList.remove(0);
			Serial.println("data");
			Serial.println(msg->data[0]);
			Serial.println(msg->data[1]);
			if(msg->data[0] == 0x12 && msg->data[1] == 0x34){
				digitalWrite(13, HIGH);
			}else if(msg->data[0] == 0x12 && msg->data[1] == 0x12){
				digitalWrite(13, LOW);
			}
			delete msg;
			/*
			lcd->clear();
			lcd->print("data:");
			Serial.println("test2App receive data");
			Serial.println(msg->len);
			Debugger::printAppMsg(*msg);
			//Serial.println("data:");
		
			bool isRight = true;
			if(msg->len == 5){
				for(int i=0;i<5;i++)
				{
					if(msg->data[i]!=0x56)
					{
						isRight = false;
					}
				}
			}else{
				isRight = false;
			}

			if(isRight){
				for(int i=0;i<20;i++){
					digitalWrite(13, HIGH);
					delay(50);
					digitalWrite(13, LOW);
					delay(50);
				}
				delete msg;
			}*/
		}
	}
	PT_END(&pt);
}