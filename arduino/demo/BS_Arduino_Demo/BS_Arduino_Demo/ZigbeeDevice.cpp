#include "ZigbeeDevice.h"

ZigbeeDevice::ZigbeeDevice()
{
	receiveTimeout = 300;
	state = DEVICE_STATE_CLOSED;
}

ZigbeeDevice::ZigbeeDevice(ZBCfg& cfg)
{
	this->cfg.clone(cfg);
	state = DEVICE_STATE_CLOSED;
}

ZigbeeDevice::ZigbeeDevice(ZBAppReg* appRegs, unsigned int count)
{
	this->appRegCount = count;
	this->appRegs = new ZBAppReg[count];
	for(unsigned int i=0;i<count;i++)
	{
		this->appRegs[i].clone(appRegs[i]);
	}
	state = DEVICE_STATE_CLOSED;
}

ZigbeeDevice::ZigbeeDevice(ZBCfg& cfg, ZBAppReg* appRegs, unsigned int appRegCount)
{
	this->cfg.clone(cfg);
	this->appRegCount = appRegCount;
	this->appRegs = new ZBAppReg[appRegCount];
	for(unsigned int i=0;i<appRegCount;i++)
	{
		this->appRegs[i].clone(appRegs[i]);
	}
	state = DEVICE_STATE_CLOSED;
}

ZigbeeDevice::~ZigbeeDevice()
{
	delete[] appRegs;
}

void ZigbeeDevice::setChannel(unsigned char channel[4])
{
	this->cfg.channel[0] = channel[0];
	this->cfg.channel[1] = channel[1];
	this->cfg.channel[2] = channel[2];
	this->cfg.channel[3] = channel[3];
}

void ZigbeeDevice::setPANID(unsigned char panID[2])
{
	this->cfg.panID[0] = panID[0];
	this->cfg.panID[1] = panID[1];
}

void ZigbeeDevice::setZDType(unsigned char zdType)
{
	this->cfg.zdType = zdType;
}

void ZigbeeDevice::setAppRegs(ZBAppReg* appRegs, unsigned int count)
{
	delete[] this->appRegs;
	this->appRegCount = count;
	this->appRegs = new ZBAppReg[count];
	for(unsigned int i=0;i<count;i++)
	{
		this->appRegs[i].clone(appRegs[i]);
	}
}

void ZigbeeDevice::init()
{
	//������ʱ��̫�̲��У�����1000
	Serial.write((byte*)ZBC::CMD_DEVICE_RESET.cmd, ZBC::CMD_DEVICE_RESET.len);
	delay(1800);
	//rec(1500);

	//���ò����ϴ�״̬����
	Serial.write((byte*)ZBC::CMD_STARTUP_WITHOUT_LAST_STATE.cmd, ZBC::CMD_STARTUP_WITHOUT_LAST_STATE.len);
	delay(300);
	//rec(300);

	//����
	Serial.write((byte*)ZBC::CMD_DEVICE_RESET.cmd, ZBC::CMD_DEVICE_RESET.len);
	delay(1800);
	//rec(1500);
	
	//����0x00000800�ŵ���Ĭ��Ҳ��0x00000800�ŵ�
	ZBCmd chanelCfgCmd;
	ZBC::chanlistCfg(cfg.channel, &chanelCfgCmd);
	Serial.write((byte*)chanelCfgCmd.cmd, chanelCfgCmd.len);
	delay(300);
	//rec(300);
	

	//���ù�������
	ZBCmd PANIDCfgCmd;
	ZBC::PANIDCfg(cfg.panID, &PANIDCfgCmd);
	Serial.write((byte*)PANIDCfgCmd.cmd, PANIDCfgCmd.len);
	delay(300);
	//rec(300);

	//����zigbee�豸���ͣ�Э����/·����/�նˣ�
	ZBCmd deviceTypeCfgCmd;
	ZBC::deviceTypeCfg(cfg.zdType, &deviceTypeCfgCmd);
	Serial.write((byte*)deviceTypeCfgCmd.cmd, deviceTypeCfgCmd.len);
	delay(300);
	//rec(300);

	for(unsigned int i=0;i<appRegCount;i++)
	{
		//Serial.println("------register--------");
		ZBCmd registerAppCmd;
		ZBC::appRegister(appRegs[i], &registerAppCmd);
		Serial.write((byte*)registerAppCmd.cmd, registerAppCmd.len);
		delay(300);
	}
	//rec(300);

	state = DEVICE_STATE_READY;
}

void ZigbeeDevice::start()
{
	//Serial.println("------start--------");
	//�������������������
	Serial.write((byte*)ZBC::CMD_STARTUP_FROM_APP.cmd, ZBC::CMD_STARTUP_FROM_APP.len);
	//rec(2500);
	delay(2000);

	state = DEVICE_STATE_WORKING;
}

int ZigbeeDevice::readByte()
{
	unsigned long time1 = micros();
	while((micros()-time1)<1000 && Serial.available() < 1);
	return Serial.read();
}

bool ZigbeeDevice::isDataComing()
{
	while(Serial.available() > 0)
	{
		if(Serial.peek() != SOF)
			Serial.read();
		else
		{
			return true;
		}
	}

	return false;
}

void ZigbeeDevice::receive(ZBPacketReceive& packet)
{
	//�ж���Ϣ���Ƿ�ʼ
	//����Ĭ��msg����ʾ��ȡ������Ч��dataPacket��len=0��
	bool isBegin = false;
	unsigned long cTime = millis();
	while((millis() - cTime) < receiveTimeout)
	{
		if(Serial.read() == SOF)
		{
			isBegin = true;
			break;
		}
	}

	if( ! isBegin)
	{
		packet.reset();
		return;
	}

	int temp = readByte();

	//����-1��ʾ�ڹ涨ʱ����û���������ֽ�
	//��ǰ���ݴ��������⣬��ֹ��ǰ����
	if(temp == -1){
		packet.reset();
		return;
	}
	else{
		packet.len = temp;
	}

	temp = readByte();
	if(temp == -1){
		packet.reset();
		return;
	}else{
		packet.cmd1 = temp;
	}

	temp = readByte();
	if(temp == -1){
		packet.reset();
		return;
	}else{
		packet.cmd2 = temp;
	}

	packet.data = new unsigned char[packet.len];
	unsigned char readLen = Serial.readBytes((char *)packet.data, packet.len);

	//��ȡ�����ݳ��ȱ�ʾ���ƶ�ʱ����û���㹻�����ݴ���������Ϊ�˴�ͨ��������
	if(readLen != packet.len)
	{
		packet.reset();
		return;
	}

	if( ! packet.validate(readByte()))
	{
		packet.reset();
		return;
	}
}

void ZigbeeDevice::send(ZBPacketSend& packet)
{
	ZBCmd packetSendCmd;
	ZBC::packetSend(packet, &packetSendCmd);
	Serial.write((byte*)packetSendCmd.cmd, packetSendCmd.len);
}

/*
void ZigbeeDevice::test(LCDDevice& lcd)
{
	setZDType(ZB_DEVICE_TYPE_COORDINATOR);
	ZBAppReg appRegs[1];
	appRegs[0] = ZBAppReg();
	setAppRegs(appRegs, 1);
	init();
	start();
	ready();
	unsigned char count=0;
	while(true){
		if(Serial.available()>0){
			count++;
			if(count==78){
				count=0;
				lcd.clear();
				lcd.setCursor(0,0);
			}
			char c = Serial.read();
			lcd.print(c);
		}
	}
}


void ZigbeeDevice::test1()
{
	while(true){
		ZBPacketSend packet;
		packet.dstAddr[0] = 0xff;
		packet.dstAddr[1] = 0xff;
		packet.dstEndpoint = 0x01;
		packet.srcEndpoint = 0x01;
		packet.clusterID[0] = 0x01;
		packet.clusterID[1] = 0x01;
		packet.transID = 0;
		packet.options = 0x00;
		packet.radius = 0x00;
		packet.len = 0x03;
		packet.data = new unsigned char[3];
		packet.data[0] = 56;
		packet.data[1] = 56;
		packet.data[2] = 56;
		sendPacket(packet);
		delay(2500);
	}
}

*/