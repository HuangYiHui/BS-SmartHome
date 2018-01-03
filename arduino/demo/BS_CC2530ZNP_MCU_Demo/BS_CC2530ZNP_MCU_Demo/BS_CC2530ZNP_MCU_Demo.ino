#include <Wire.h>
#include <LiquidCrystal_I2C.h> //引用I2C库
#include "ZBC.h"
#include "Cfg.h"

//SCL接A5
//SDA接A4
//设置LCD1602设备地址，这里的地址是0x3F，一般是0x20，或者0x27，具体看模块手册
LiquidCrystal_I2C lcd(0x3F,16,2);

int index=0;

//等待回复
void rec(unsigned long time){
	
	unsigned long cur = millis();
	while((millis()-cur)<time){
		while ( Serial.available() > 0){
    
		index++;
		if(index==17){
		  lcd.setCursor(0, 1);
		} else if(index==33){
		  lcd.setCursor(0, 0);
		  index=0;
		  lcd.clear();
		}

		char c = Serial.read();
		lcd.print(c);
		//Serial.print(c);
	  }
	}
}

void initZigbee()
{
	delay(1000);

	//设置不从上次状态启动
	Serial.write((byte*)ZBC::CMD_STARTUP_WITHOUT_LAST_STATE.cmd, ZBC::CMD_STARTUP_WITHOUT_LAST_STATE.len);
	//delay(300);
	rec(300);

	//重启
	Serial.write((byte*)ZBC::CMD_DEVICE_RESET.cmd, ZBC::CMD_DEVICE_RESET.len);
	//delay(1500);
	rec(1500);
	
	//设置0x00000800信道，默认也是0x00000800信道
	ZBCmd chanelCfgCmd;
	unsigned char channel[4] = ZB_CHANNEL;
	ZBC::chanlistCfg(channel, &chanelCfgCmd);
	Serial.write((byte*)chanelCfgCmd.cmd, chanelCfgCmd.len);
	//delay(300);
	rec(300);
	

	//设置工作子网
	ZBCmd PANIDCfgCmd;
	unsigned char panid[2] = ZB_PANID;
	ZBC::PANIDCfg(panid, &PANIDCfgCmd);
	Serial.write((byte*)PANIDCfgCmd.cmd, PANIDCfgCmd.len);
	//delay(300);
	rec(300);

	//设置zigbee设备类型（协调器/路由器/终端）
	ZBCmd deviceTypeCfgCmd;
	ZBC::deviceTypeCfg((unsigned char)ZB_DEVICE_TYPE, &deviceTypeCfgCmd);
	Serial.write((byte*)deviceTypeCfgCmd.cmd, deviceTypeCfgCmd.len);
	//delay(300);
	rec(300);

	//注册应用
	ZBAppReg reg;
	reg.AppDeviceID[0] = ZB_DEVICEID0;
	reg.AppDeviceID[1] = ZB_DEVICEID1;
	reg.AppNumInClusters = 0x00;
	reg.AppNumOutClusters = 0x00;
	reg.AppProfID[0] = ZB_APP_PROFID0;
	reg.AppProfID[1] = ZB_APP_PROFID1;
	reg.EndDevVer = ZB_END_DEVICE_VERSION;
	reg.EndPoint = ZB_ENDPOINT;
	reg.LatencyReq = ZB_LATENCY_REQUEST;

	ZBCmd registerAppCmd;
	ZBC::appRegister(reg, &registerAppCmd);
	Serial.write((byte*)registerAppCmd.cmd, registerAppCmd.len);
	//delay(300);
	rec(300);

	//建立网络或者连接网络
	Serial.write((byte*)ZBC::CMD_STARTUP_FROM_APP.cmd, ZBC::CMD_STARTUP_FROM_APP.len);
	rec(2500);
	//delay(2500);
}
void setup()
{
  lcd.init();                  // 初始化LCD
  lcd.backlight();             //设置LCD背景等亮
  Serial.begin(19200);
  delay(1000);
  initZigbee();
}

void loop()
{
	
  while ( Serial.available() > 0){
    
    index++;
    if(index==17){
      lcd.setCursor(0, 1);
    } else if(index==33){
      lcd.setCursor(0, 0);
      index=0;
      lcd.clear();
    }

    char c = Serial.read();
    lcd.print(c);
    //Serial.print(c);
  }
}