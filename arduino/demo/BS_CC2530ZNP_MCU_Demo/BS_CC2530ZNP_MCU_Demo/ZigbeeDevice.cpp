#include "ZigbeeDevice.h"

ZigbeeDevice::ZigbeeDevice()
{
	receiveTimeout = 300;	
}

ZigbeeDevice::ZigbeeDevice(ZBCfg& cfg)
{
	this->cfg.clone(cfg);
}


void ZigbeeDevice::setChannel(unsigned char channel[4])
{
	cfg.channel[0] = channel[0];
	cfg.channel[1] = channel[1];
	cfg.channel[2] = channel[2];
	cfg.channel[3] = channel[3];
}

void ZigbeeDevice::setPANID(unsigned char panID[2])
{
	cfg.panID[0] = panID[0];
	cfg.panID[1] = panID[1];
}

void ZigbeeDevice::setZDType(unsigned char zdType)
{
	cfg.zdType = zdType;
}

void ZigbeeDevice::setAppReg(ZBAppReg& appReg)
{
	appReg.clone(appReg);
}


void printBytes(unsigned char* bs, unsigned char len, String title)
{
	Serial.print("---------");
	Serial.println(title);
	for(int i=0;i<len;i++)
	{
		Serial.print(bs[i], HEX);
		Serial.print(',');
	}
	Serial.println();
	Serial.print("---------");
	Serial.println(title);
	Serial.println();
}

void ZigbeeDevice::init()
{
	Serial.begin(19200);
	//Serial.println();

	//重启
	Serial.write((byte*)ZBC::CMD_DEVICE_RESET.cmd, ZBC::CMD_DEVICE_RESET.len);
	//printBytes(ZBC::CMD_DEVICE_RESET.cmd,ZBC::CMD_DEVICE_RESET.len, "reboot");
	delay(1500);
	//rec(1500);

	//设置不从上次状态启动
	Serial.write((byte*)ZBC::CMD_STARTUP_WITHOUT_LAST_STATE.cmd, ZBC::CMD_STARTUP_WITHOUT_LAST_STATE.len);
	//printBytes(ZBC::CMD_STARTUP_WITHOUT_LAST_STATE.cmd, ZBC::CMD_STARTUP_WITHOUT_LAST_STATE.len, "set don't start from last state");
	delay(300);
	//rec(300);

	//重启
	Serial.write((byte*)ZBC::CMD_DEVICE_RESET.cmd, ZBC::CMD_DEVICE_RESET.len);
	//printBytes(ZBC::CMD_DEVICE_RESET.cmd,ZBC::CMD_DEVICE_RESET.len, "reboot");
	delay(1500);
	//rec(1500);
	
	//设置0x00000800信道，默认也是0x00000800信道
	ZBCmd chanelCfgCmd;
	ZBC::chanlistCfg(cfg.channel, &chanelCfgCmd);
	Serial.write((byte*)chanelCfgCmd.cmd, chanelCfgCmd.len);
	//printBytes(chanelCfgCmd.cmd, chanelCfgCmd.len, "set channel");
	delay(300);
	//rec(300);
	

	//设置工作子网
	ZBCmd PANIDCfgCmd;
	ZBC::PANIDCfg(cfg.panID, &PANIDCfgCmd);
	Serial.write((byte*)PANIDCfgCmd.cmd, PANIDCfgCmd.len);
	//printBytes(PANIDCfgCmd.cmd, PANIDCfgCmd.len, "set panid");
	delay(300);
	//rec(300);

	//设置zigbee设备类型（协调器/路由器/终端）
	ZBCmd deviceTypeCfgCmd;
	ZBC::deviceTypeCfg(cfg.zdType, &deviceTypeCfgCmd);
	Serial.write((byte*)deviceTypeCfgCmd.cmd, deviceTypeCfgCmd.len);
	//printBytes(deviceTypeCfgCmd.cmd, deviceTypeCfgCmd.len, "set device type");
	delay(300);
	//rec(300);

	ZBCmd registerAppCmd;
	ZBC::appRegister(appReg, &registerAppCmd);
	Serial.write((byte*)registerAppCmd.cmd, registerAppCmd.len);
	//printBytes(registerAppCmd.cmd, registerAppCmd.len, "register App");
	delay(300);
	//rec(300);

	//建立网络或者连接网络
	Serial.write((byte*)ZBC::CMD_STARTUP_FROM_APP.cmd, ZBC::CMD_STARTUP_FROM_APP.len);
	//printBytes(ZBC::CMD_STARTUP_FROM_APP.cmd, ZBC::CMD_STARTUP_FROM_APP.len, "build pan");
	//rec(2500);
	delay(2500);
	//Serial.setTimeout(1);
}

unsigned char ZigbeeDevice::readByte()
{
	unsigned long time1 = micros();
	while((micros()-time1)<1000 && Serial.available()==0);
	return Serial.read();
}

ZBPacketReceive ZigbeeDevice::receivePacket()
{
	ZBPacketReceive packet;

	//判断信息包是否开始
	//返回默认msg，表示读取到了无效的dataPacket（len=0）
	bool isBegin = false;
	unsigned long cTime = millis();
	while(Serial.available() > 0 && (millis() - cTime)<receiveTimeout)
	{
		if(Serial.read() == SOF)
		{
			isBegin = true;
			break;
		}
	}
	if( ! isBegin)
		return ZBPacketReceive();

	packet.len = readByte();
	//等于-1表示在规定时间内没读到后续字节
	//当前数据传输有问题，终止当前传输
	if(packet.len == -1)
		return ZBPacketReceive();

	packet.cmd1 = readByte();
	if(packet.cmd1 == -1)
		return ZBPacketReceive();

	packet.cmd2 = readByte();
	if(packet.cmd2 == -1)
		return ZBPacketReceive();

	packet.data = new unsigned char[packet.len];
	unsigned char readLen = Serial.readBytes((char *)packet.data, packet.len);

	//读取的数据长度表示在制定时间内没有足够的数据传过来，认为此次通信有问题
	if(readLen != packet.len)
		return ZBPacketReceive();

	if( ! packet.validate(readByte()))
		return ZBPacketReceive();

	return packet;
}

void ZigbeeDevice::sendPacket(ZBPacketSend& packet)
{
	ZBCmd packetSendCmd;
	ZBC::packetSend(packet, &packetSendCmd);
	Serial.write((byte*)packetSendCmd.cmd, packetSendCmd.len);
}