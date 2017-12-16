#include <Wire.h>
#include <LiquidCrystal_I2C.h> //����I2C��

//SCL��A5
//SDA��A4
//����LCD1602�豸��ַ������ĵ�ַ��0x3F��һ����0x20������0x27�����忴ģ���ֲ�
LiquidCrystal_I2C lcd(0x3F,16,2);

void setup()
{
  lcd.init();                  // ��ʼ��LCD
  lcd.backlight();             //����LCD��������
}

void loop()
{
  lcd.setCursor(0,0);                //������ʾָ��
  lcd.print("LCD1602 iic Test");     //����ַ���LCD1602��
  lcd.setCursor(0,1);
  lcd.print("         by L.L.");
  delay(1000);
}