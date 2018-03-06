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
	/*
	PT_BEGIN(&pt);
	while(true){
		PT_TIMER_DELAY(&pt, 1000);
		Serial.println("test2App run...");
	}
	PT_END(&pt);
*/
	PT_BEGIN(&pt);
	while(true){
		PT_TIMER_DELAY(&pt, 1000);
		while(msgList.size()>0){
			AppMsgReceive* msg = msgList.remove(0);
			lcd->clear();
			lcd->print("data:");
			//Serial.println("data:");

			bool isRight = true;
			if(msg->len == 5){
				for(int i=0;i<5;i++){
					if(msg->data[i]!=0x56){
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
			}

			for(unsigned int i=0;i<msg->len;i++)
			{
				lcd->print(msg->data[i], HEX);
				lcd->print(",");

				//Serial.print(msg->data[i], HEX);
				//Serial.print(",");
			}
			delete msg;
		}
	}

	PT_END(&pt);

	/*
	PT_BEGIN(&pt);
	while(true){
		PT_WAIT_UNTIL(&pt, msgList.size()>0);
		if(msgList.size()>0){
			
			AppMsg* msg = msgList.remove(0);
			lcd.print("data:");
			for(unsigned int i=0;i<msg->len;i++)
			{
				lcd.print(msg->data[i], HEX);
				lcd.print(",");
			}
			delete msg;
		}
	}
	PT_END(&pt);
	*/
}