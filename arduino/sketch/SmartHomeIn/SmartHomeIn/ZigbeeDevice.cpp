#include "ZigbeeDevice.h"

ZigbeeDevice::ZigbeeDevice()
{
	receiveTimeout = 200;
}

void ZigbeeDevice::sendFlashCmdBytes(unsigned int address, unsigned int len)
{
	unsigned char* buffer = new unsigned char[len];
	Tool::readBytesFromFlash(address, buffer, len);
	Serial.write(buffer, len);
	delete[] buffer;
}

bool ZigbeeDevice::startUpWithoutLastState()
{
	sendFlashCmdBytes((unsigned int)CMD_STARTUP_WITHOUT_LAST_STATE_BYTES, 8);
	ZBPacketReceive packet;
	receive(packet, 20);
	if(packet.len == 0x01 && packet.cmd1 == 0x66 && packet.cmd2 == 0x05 && packet.data[0] == 0x00)
		return true;
	else
		return false;
}

bool ZigbeeDevice::restart()
{
	sendFlashCmdBytes((unsigned int)CMD_DEVICE_RESET_BYTES, 6);
	ZBPacketReceive packet;
	receive(packet, 1700);
	if(packet.len == 0x06 && packet.cmd1 == 0x41 && packet.cmd2 == 0x80)
		return true;
	else
		return false;
}

bool ZigbeeDevice::setDeviceType()
{
	sendFlashCmdBytes((unsigned int)CMD_DEVICE_TYPE_SET_BYTES, 8);
	ZBPacketReceive packet;
	receive(packet, 20);
	if(packet.len == 0x01 && packet.cmd1 == 0x61 && packet.cmd2 == 0x09 && packet.data[0] == 0x00)
		return true;
	else
		return false;
}

bool ZigbeeDevice::setDirectCB()
{
	sendFlashCmdBytes((unsigned int)CMD_ZDO_DIRECT_CB_BYTES, 8);
	ZBPacketReceive packet;
	receive(packet, 20);
	if(packet.len == 0x01 && packet.cmd1 == 0x66 && packet.cmd2 == 0x05 && packet.data[0] == 0x00)
		return true;
	else
		return false;
}

bool ZigbeeDevice::registerApp()
{
	sendFlashCmdBytes((unsigned int)CMD_APP_REGISTER_BYTES, 18);
	ZBPacketReceive packet;
	receive(packet, 20);
	if(packet.len == 0x01 && packet.cmd1 == 0x64 && packet.cmd2 == 0x00 && packet.data[0] == 0xb8)
		return true;
	else
		return false;
}
bool ZigbeeDevice::startFromApp()
{
	sendFlashCmdBytes((unsigned int)CMD_STARTUP_FROM_APP_BYTES, 7);
	delay(100);
	return true;
}

void ZigbeeDevice::start()
{
	//��մ��ڻ���
	while(Serial.available()>0)
		Serial.read();

	unsigned char buffer[14];
	ZBPacketReceive packet;

	//���ò����ϴ�״̬����
	startUpWithoutLastState();
	//����
	restart();
	
	//�����ŵ���ʹ��Ĭ�ϵ�0x00000800
	//���ù�������,ʹ��Ĭ�ϵ�0xffff

	//����zigbee�豸���ͣ�Э����/·����/�նˣ�
	setDeviceType();

	//���豸mac��ַ�������ַ��Ѱ���Կ���
	setDirectCB();
	//rec(300);
	
	//ע��Ӧ��
	registerApp();

	//�������������������
	startFromApp();
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

void ZigbeeDevice::setReceiveTimeout(unsigned int receiveTimeout)
{
	this->receiveTimeout = receiveTimeout;
}

void ZigbeeDevice::receive(ZBPacketReceive& packet)
{
	receive(packet, receiveTimeout);
}

void ZigbeeDevice::receive(ZBPacketReceive& packet, unsigned int timeout)
{
	//�ж���Ϣ���Ƿ�ʼ
	//����Ĭ��msg����ʾ��ȡ������Ч��dataPacket��len=0��
	bool isBegin = false;
	unsigned long cTime = millis();
	do{
		if(Serial.read() == SOF)
		{
			isBegin = true;
			break;
		}
	}while((millis() - cTime) < timeout);

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
	unsigned char len = 15+packet.len;
	unsigned char* bs = new unsigned char[len];
	getPacketSendBytes(packet, bs);
	Serial.write(bs, len);
	delete[] bs;
}

void ZigbeeDevice::getPacketSendBytes(ZBPacketSend& packet, unsigned char* bs)
{
	unsigned char len = 15+packet.len;
	bs[0] = 0xfe;
	bs[1] = 10 + packet.len;
	bs[2] = 0x24;
	bs[3] = 0x01;
	bs[4] = packet.dstAddr[0];
	bs[5] = packet.dstAddr[1];
	bs[6] = packet.dstEndpoint;
	bs[7] = packet.srcEndpoint;
	bs[8] = packet.clusterID[0];
	bs[9] = packet.clusterID[1];
	bs[10] = packet.transID;
	bs[11] = packet.options;
	bs[12] = packet.radius;
	bs[13] = packet.len;
	memcpy(&bs[14], packet.data, sizeof(unsigned char)*packet.len);
	bs[len-1] = calCrc(&bs[1], len-2);
}

unsigned char ZigbeeDevice::calCrc(const unsigned char *pMsg, unsigned char len)
{
	unsigned char result = 0;
	while (len--)
	{
		result ^= *pMsg++;
	}
	return result;
}