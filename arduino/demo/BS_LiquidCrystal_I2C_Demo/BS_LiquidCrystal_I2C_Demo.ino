#include <Wire.h>
#include <LiquidCrystal_I2C.h> //引用I2C库

//SCL接A5
//SDA接A4
//设置LCD1602设备地址，这里的地址是0x3F，一般是0x20，或者0x27，具体看模块手册
LiquidCrystal_I2C lcd(0x3F,16,2);

void setup()
{
  lcd.init();                  // 初始化LCD
  lcd.backlight();             //设置LCD背景等亮
}

void loop()
{
  lcd.setCursor(0,0);                //设置显示指针
  lcd.print("LCD1602 iic Test");     //输出字符到LCD1602上
  lcd.setCursor(0,1);
  lcd.print("         by L.L.");
  delay(1000);
}