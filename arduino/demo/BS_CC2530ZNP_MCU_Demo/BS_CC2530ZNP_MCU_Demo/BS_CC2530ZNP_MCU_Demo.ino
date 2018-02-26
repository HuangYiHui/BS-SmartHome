
/*
���Է���
��ZigbeeApp.init�������豸���ͣ�ʹһ����Э������һ����·����
·����ѭ������,��loop��ִ��send����
Э�����ȴ����գ���loop������ִ��receive����
*/
//ת��ģ��lv��3.3v,hv��5v
//arduino��zigbee���أ���ת��ģ���gnd
//arduino tx��ת��ģ���TXO
//zigbee  rx��ת��ģ���TXI
//arduino��rx��zigbee��txֱ��

#include "ZigbeeDevice.h"
#include "ZigbeeApp.h"

ZigbeeDevice zigbee;
ZigbeeApp zigbeeApp(zigbee);

#include <Wire.h>
#include <LiquidCrystal_I2C.h> //����I2C��
//SCL��A5
//SDA��A4
//����LCD1602�豸��ַ������ĵ�ַ��0x3F��һ����0x20������0x27�����忴ģ���ֲ�
LiquidCrystal_I2C lcd(0x3F,16,2);
int index=0;

void setup()
{
	Serial.begin(19200);
	lcd.init();                  // ��ʼ��LCD
	lcd.backlight();             //����LCD��������
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
	//arduino�����ϵĵ�������ʾ�ڹ���
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