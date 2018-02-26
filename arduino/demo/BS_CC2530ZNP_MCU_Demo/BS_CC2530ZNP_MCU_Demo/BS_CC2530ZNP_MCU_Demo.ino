
/*
调试方法
在ZigbeeApp.init中设置设备类型，使一个作协调器，一个作路由器
路由器循环发送,在loop中执行send方法
协调器等待接收，在loop方法中执行receive方法
*/
//转换模块lv接3.3v,hv接5v
//arduino与zigbee共地，接转换模块的gnd
//arduino tx接转换模块的TXO
//zigbee  rx接转换模块的TXI
//arduino的rx与zigbee的tx直连

#include "ZigbeeDevice.h"
#include "ZigbeeApp.h"

ZigbeeDevice zigbee;
ZigbeeApp zigbeeApp(zigbee);

#include <Wire.h>
#include <LiquidCrystal_I2C.h> //引用I2C库
//SCL接A5
//SDA接A4
//设置LCD1602设备地址，这里的地址是0x3F，一般是0x20，或者0x27，具体看模块手册
LiquidCrystal_I2C lcd(0x3F,16,2);
int index=0;

void setup()
{
	Serial.begin(19200);
	lcd.init();                  // 初始化LCD
	lcd.backlight();             //设置LCD背景等亮
	pinMode(13, OUTPUT);
	zigbeeApp.init();
}

void receive()
{
	if ( Serial.available() > 0){
		index++;
		if(index==17){
		  lcd.setCursor(0, 1);
		} else if(index==33){
		  lcd.setCursor(0, 0);
		  index=0;
		  lcd.clear();
		}

		char c = Serial.read();
		//lcd.print(c, HEX);
		//lcd.print(',');
		lcd.print(c);
		//Serial.print(c);
	 }
}

void send()
{
	zigbeeApp.run();
	//arduino板子上的灯闪，表示在工作
	digitalWrite(13, LOW);
	delay(700);
	digitalWrite(13, HIGH);
	delay(700);
}
void loop()
{
	//receive();
	send();
}