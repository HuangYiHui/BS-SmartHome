#include "ZigbeeDevice.h"

ZigbeeDevice::ZigbeeDevice(unsigned int deviceID) : SampleDevice(deviceID)
{
}

void ZigbeeDevice::start()
{
	unsigned char buffer[14];

	//������ʱ��̫�̲��У�����1000
	Tool::readBytesFromFlash((unsigned int)CMD_DEVICE_RESET_BYTES, buffer, 6);
	Serial.write(buffer, 6);
	delay(2000);
	//rec(1500);

	//���ò����ϴ�״̬����
	Tool::readBytesFromFlash((unsigned int)CMD_STARTUP_WITHOUT_LAST_STATE_BYTES, buffer, 8);
	Serial.write(buffer, 8);
	delay(500);
	//rec(300);

	//����
	Tool::readBytesFromFlash((unsigned int)CMD_DEVICE_RESET_BYTES, buffer, 6);
	Serial.write(buffer, 6);
	delay(2000);
	//rec(1500);
	
	//����0x00000800�ŵ���Ĭ��Ҳ��0x00000800�ŵ�
	Tool::readBytesFromFlash((unsigned int)CMD_CHANNEL_SET_BYTES, buffer, 11);
	Serial.write(buffer, 11);
	delay(500);
	//rec(300);

	//���ù�������
	Tool::readBytesFromFlash((unsigned int)CMD_PANID_SET_BYTES, buffer, 9);
	Serial.write(buffer, 9);
	delay(500);
	//rec(300);

	//����zigbee�豸���ͣ�Э����/·����/�նˣ�
	Tool::readBytesFromFlash((unsigned int)CMD_DEVICE_TYPE_SET_BYTES, buffer, 8);
	Serial.write(buffer, 8);
	delay(500);
	//rec(300);

	//���豸mac��ַ�������ַ��Ѱ���Կ���
	Tool::readBytesFromFlash((unsigned int)CMD_ZDO_DIRECT_CB_BYTES, buffer, 8);
	Serial.write(buffer, 8);
	delay(500);
	//rec(300);
	
	//ע��Ӧ��
	Tool::readBytesFromFlash((unsigned int)CMD_APP_REGISTER_BYTES, buffer, 14);
	Serial.write(buffer, 14);
	delay(500);

	Tool::readBytesFromFlash((unsigned int)CMD_STARTUP_FROM_APP_BYTES, buffer, 7);
	//Serial.println("------start--------");
	//�������������������
	Serial.write(buffer, 7);
	//rec(2500);
	delay(2000);
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
	while((millis() - cTime) < 300)
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