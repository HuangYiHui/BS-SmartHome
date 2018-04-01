#include "LCDApp.h"

LCDApp::LCDApp(LCDDevice& lcd) : lcd(lcd)
{
	this->appID = APP_ID_LCD;

	thhIn[0] = 0;
	thhIn[1] = 0;
	thhIn[2] = 0;
	thhOut[0] = 0;
	thhOut[1] = 0;
	thhOut[2] = 0;
	lightIntensity = 0;
	dustConcentration = 0;
	isOnline = false;
	isSocket1On = false;
	isSocket2On = false;
	isSocket3On = false;
}

void LCDApp::init()
{
	lcd.start();
	lcd.setFont(u8g_font_profont11);
}

void LCDApp::printFloat(unsigned char x, unsigned char y, float value)
{
	if(value < 0){
		lcd.setPrintPos(x, y);
		lcd.print('-');
	}
	if(abs(value) < 10)
		lcd.setPrintPos(x+11, y);
	else
		lcd.setPrintPos(x+5, y);

	lcd.print(abs(value), 1);
}

void LCDApp::refreshMainPage()
{
	lcd.firstPage();
	do {
		lcd.drawFrame(52,0,76,22);
		lcd.drawFrame(52,21,76,22);
		lcd.drawFrame(52,42,76,21);
		lcd.drawFrame(0,42,53,21);

		lcd.drawXBMP(54,3,16,16,temperatureIcon);
		lcd.drawXBMP(54,24,16,16,humidityIcon);
		lcd.drawXBMP(54,45,16,16,heatIcon);
		lcd.drawXBMP(2,44,8,8,dustConcentrationIcon);
		lcd.drawXBMP(2,53,8,8,lightIntensityIcon);

		lcd.drawStr(1, 8, "Smar");
		lcd.drawStr(21, 8, "tHome");

		lcd.drawStr(71, 10, "I:");
		lcd.drawStr(71, 19, "O:");

		lcd.drawCircle(117, 3, 1);
		lcd.drawStr(120, 10, "C");
		lcd.drawCircle(117, 12, 1);
		lcd.drawStr(120, 19, "C");
	
		lcd.drawStr(71, 31, "I:");
		lcd.drawStr(71, 40, "O:");
		lcd.drawStr(120, 31, "%");
		lcd.drawStr(120, 40, "%");

		lcd.drawStr(71, 52, "I:");
		lcd.drawStr(71, 61, "O:");

		lcd.drawStr(47, 52, "P");
		lcd.drawStr(47, 61, "L");

		//室内温度
		printFloat(83, 10, thhIn[0]);
		//室外温度
		printFloat(83, 19, thhOut[0]);
		//室内湿度度
		printFloat(83, 31, thhIn[1]);
		//室外湿度度
		printFloat(83, 40, thhOut[1]);
		//室内热度
		printFloat(83, 52, thhIn[2]);
		//室外热度
		printFloat(83, 61, thhOut[2]);
	
		//pm2.5
		lcd.setPrintPos(11, 52);
		lcd.print(dustConcentration, 1);
		//光强
		lcd.setPrintPos(11, 61);
		lcd.print(lightIntensity, 1);

		if(isOnline)
			lcd.drawXBMP(20,8,16,16,onlineIcon);
		else{
			lcd.drawXBMP(20,8,16,16,offlineIcon);
			lcd.drawStr(33, 22, "...");
		}

		if(isSocket1On)
			lcd.drawXBMP(2,25,16,16,socketOnIcon);
		else
			lcd.drawXBMP(2,25,16,16,socketOffIcon);

		if(isSocket2On)
			lcd.drawXBMP(18,25,16,16,socketOnIcon);
		else
			lcd.drawXBMP(18,25,16,16,socketOffIcon);

		if(isSocket3On)
			lcd.drawXBMP(34,25,16,16,socketOnIcon);
		else
			lcd.drawXBMP(34,25,16,16,socketOffIcon);
			
	} while ( lcd.nextPage() );
}

void LCDApp::appMsgReceivedCallback(AppMsg& msg)
{
	if(msg.len < 1)
		return;

	unsigned char cmd = msg.data[0];

	if(CMD_NOTICE_IN_SENSOR_VALUES == cmd){
		if(msg.len != 13)
			return;
		thhIn[0] = Tool::bytesToFloat(&msg.data[1]);
		thhIn[1] = Tool::bytesToFloat(&msg.data[5]);
		thhIn[2] = Tool::bytesToFloat(&msg.data[9]);
	}else if(CMD_NOTICE_OUT_SENSOR_VALUES == cmd){
		if(msg.len != 25)
			return;
		thhOut[0] = Tool::bytesToFloat(&msg.data[1]);
		thhOut[1] = Tool::bytesToFloat(&msg.data[5]);
		thhOut[2] = Tool::bytesToFloat(&msg.data[9]);
		dustConcentration = Tool::bytesToFloat(&msg.data[13]);
		lightIntensity = Tool::bytesToFloat(&msg.data[17]);
		//solidHumidity
	}else if(CMD_NOTICE_ZIGBEE_ONLINE == cmd){
		if(msg.len != 2)
			return;
		if(msg.data[1] == FLAG_ONLINE)
			isOnline = true;
		else if((msg.data[1] == FLAG_OFFLINE))
			isOnline = false;

	}else if(CMD_NOTICE_SOCKET_STATE_CHANGE == cmd){
		if(msg.len != 3)
			return;
		if(msg.data[1] == FLAG_SOCKET1){
			if(msg.data[2] == FLAG_SOCKET_ON)
				isSocket1On = true;
			else if(msg.data[2] == FLAG_SOCKET_OFF)
				isSocket1On = false;
		}

		if(msg.data[1] == FLAG_SOCKET2){
			if(msg.data[2] == FLAG_SOCKET_ON)
				isSocket2On = true;
			else if(msg.data[2] == FLAG_SOCKET_OFF)
				isSocket2On = false;
		}

		if(msg.data[1] == FLAG_SOCKET3){
			if(msg.data[2] == FLAG_SOCKET_ON)
				isSocket3On = true;
			else if(msg.data[2] == FLAG_SOCKET_OFF)
				isSocket3On = false;
		}
	}

	refreshMainPage();
}