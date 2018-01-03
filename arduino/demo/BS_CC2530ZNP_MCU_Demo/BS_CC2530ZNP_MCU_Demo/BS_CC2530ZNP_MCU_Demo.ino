#include <Wire.h>
#include <LiquidCrystal_I2C.h> //����I2C��
#include "ZBC.h"
#include "Cfg.h"

//SCL��A5
//SDA��A4
//����LCD1602�豸��ַ������ĵ�ַ��0x3F��һ����0x20������0x27�����忴ģ���ֲ�
LiquidCrystal_I2C lcd(0x3F,16,2);

int index=0;

//�ȴ��ظ�
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

	//���ò����ϴ�״̬����
	Serial.write((byte*)ZBC::CMD_STARTUP_WITHOUT_LAST_STATE.cmd, ZBC::CMD_STARTUP_WITHOUT_LAST_STATE.len);
	//delay(300);
	rec(300);

	//����
	Serial.write((byte*)ZBC::CMD_DEVICE_RESET.cmd, ZBC::CMD_DEVICE_RESET.len);
	//delay(1500);
	rec(1500);
	
	//����0x00000800�ŵ���Ĭ��Ҳ��0x00000800�ŵ�
	ZBCmd chanelCfgCmd;
	unsigned char channel[4] = ZB_CHANNEL;
	ZBC::chanlistCfg(channel, &chanelCfgCmd);
	Serial.write((byte*)chanelCfgCmd.cmd, chanelCfgCmd.len);
	//delay(300);
	rec(300);
	

	//���ù�������
	ZBCmd PANIDCfgCmd;
	unsigned char panid[2] = ZB_PANID;
	ZBC::PANIDCfg(panid, &PANIDCfgCmd);
	Serial.write((byte*)PANIDCfgCmd.cmd, PANIDCfgCmd.len);
	//delay(300);
	rec(300);

	//����zigbee�豸���ͣ�Э����/·����/�նˣ�
	ZBCmd deviceTypeCfgCmd;
	ZBC::deviceTypeCfg((unsigned char)ZB_DEVICE_TYPE, &deviceTypeCfgCmd);
	Serial.write((byte*)deviceTypeCfgCmd.cmd, deviceTypeCfgCmd.len);
	//delay(300);
	rec(300);

	//ע��Ӧ��
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

	//�������������������
	Serial.write((byte*)ZBC::CMD_STARTUP_FROM_APP.cmd, ZBC::CMD_STARTUP_FROM_APP.len);
	rec(2500);
	//delay(2500);
}
void setup()
{
  lcd.init();                  // ��ʼ��LCD
  lcd.backlight();             //����LCD��������
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