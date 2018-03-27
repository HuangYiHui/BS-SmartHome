#include "LCDApp.h"

LCDApp::LCDApp(unsigned int appID, LCDDevice& lcd, DHT11Device& dht11) : SampleApp(appID), lcd(lcd), dht11(dht11)
{
}

void LCDApp::init()
{
	lcd.start();
	lcd.setColorIndex(1);
	lcd.setFont(u8g_font_unifont);
	lcd.printStr(20,20,"12345ABCD");
	PT_INIT(&pt);
	state = APP_STATE_READY;
}

int LCDApp::runUpdateInTHHTask()
{
	PT_BEGIN(&pt);
	while(true){
		float values[3];
		dht11.readSensorValue(values);
		/*
		lcd.clear();

		lcd.setCursor(4, 1);
		lcd.print(">>>SmartHome<<<");

		lcd.setCursor(13, 3);
		lcd.print("T  : ");
		lcd.print(values[0]);
		lcd.print(" `C");

		lcd.setCursor(13, 4);
		lcd.print("H  : ");
		lcd.print(values[1]);
		lcd.print("  %");
		
		lcd.setCursor(13, 5);
		lcd.print("HI : ");
		lcd.print(values[2]);
		*/
		PT_TIMER_DELAY(&pt, 3000);
	}
	PT_END(&pt);
}
void LCDApp::run()
{
	runUpdateInTHHTask();
	/*
	while(msgList.size()>0){
		AppMsg* msg = msgList.remove(0);
		if(msg->len < 2){
			delete msg;
			msg = NULL;
			return;
		}
		
		int cmd = msg->data[0] + 256 * msg->data[1];
		if(CMD_RECEIVE_DATA == cmd)
		{
			//2byte命令头 + 2byte数据index + 数据
			if(msg->len < 5){
				delete msg;
				msg = NULL;
				return;
			}

			int dataIndex = msg->data[2] + 256 * msg->data[3];
			if(dataIndex == DATA_INDEX_IN_TEMPERATURE ||
				dataIndex == DATA_INDEX_IN_HUMIDITY ||
				dataIndex == DATA_INDEX_IN_HEAT
			){
				float value = Tool::bytesToFloat(&(msg->data[4]));
				if(dataIndex == DATA_INDEX_IN_TEMPERATURE){
					lcd.setCursor(0, 0);
					lcd.print("T  : ");
					lcd.print(value);
					lcd.print(" `C");
				}else if(dataIndex == DATA_INDEX_IN_HUMIDITY){
					lcd.setCursor(0, 1);
					lcd.print("H  : ");
					lcd.print(value);
					lcd.print(" %");
				}else if(dataIndex == DATA_INDEX_IN_HEAT){
					lcd.setCursor(0, 2);
					lcd.print("HI : ");
					lcd.print(value);
				}
			}
		}

		delete msg;
		msg = NULL;
	}
	*/
}