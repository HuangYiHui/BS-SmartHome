#include "ZigbeeDevice.h"

ZigbeeDevice::ZigbeeDevice(unsigned int deviceID) : SampleDevice(deviceID)
{
}

void ZigbeeDevice::init()
{
	unsigned char CMD_DEVICE_RESET_BYTES[6] = {0xfe, 0x01, 0x41, 0x00, 0x00, 0x40};
	unsigned char CMD_STARTUP_WITHOUT_LAST_STATE_BYTES[8] = {0xfe, 0x03, 0x26, 0x05, 0x03, 0x01, 0x03, 0x21};
	unsigned char CMD_ZDO_DIRECT_CB_BYTES[8] = {SOF, 0x03, 0x26, 0x05, 0x8f, 0x01, 0x01, 0xaf};
	//�ŵ�ʹ��0x00000800
	unsigned char CMD_CHANNEL_SET_BYTES[11] = {0xfe, 0x06, 0x26, 0x05, 0x84, 0x04, 0x00, 0x08, 0x00, 0x00, 0xad};
	//��������Ϊ0xffff
	unsigned char CMD_PANID_SET_BYTES[9] = {0xfe, 0x04, 0x26, 0x05, 0x83, 0x02, 0xff, 0xff, 0xa6};
	//�豸����0x01,·����
	unsigned char CMD_DEVICE_TYPE_SET_BYTES[8] = {0xfe, 0x03, 0x26, 0x05, 0x87, 0x01, 0x01, 0xa7};
	//Ӧ��ע��
	unsigned char CMD_APP_REGISTER_BYTES[14] = {0xfe, 0x09, 0x24, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78};


	//������ʱ��̫�̲��У�����1000
	Serial.write(CMD_DEVICE_RESET_BYTES, 6);
	delay(2000);
	//rec(1500);

	//���ò����ϴ�״̬����
	Serial.write(CMD_STARTUP_WITHOUT_LAST_STATE_BYTES, 8);
	delay(500);
	//rec(300);

	//����
	Serial.write(CMD_DEVICE_RESET_BYTES, 6);
	delay(2000);
	//rec(1500);
	
	//����0x00000800�ŵ���Ĭ��Ҳ��0x00000800�ŵ�
	Serial.write(CMD_CHANNEL_SET_BYTES, 11);
	delay(500);
	//rec(300);

	//���ù�������
	Serial.write(CMD_PANID_SET_BYTES, 9);
	delay(500);
	//rec(300);

	//����zigbee�豸���ͣ�Э����/·����/�նˣ�
	Serial.write(CMD_DEVICE_TYPE_SET_BYTES, 8);
	delay(500);
	//rec(300);

	//���豸mac��ַ�������ַ��Ѱ���Կ���
	Serial.write(CMD_ZDO_DIRECT_CB_BYTES, 8);
	delay(500);
	//rec(300);
	
	//ע��Ӧ��
	Serial.write(CMD_APP_REGISTER_BYTES, 14);
	delay(500);

	state = DEVICE_STATE_READY;
}

void ZigbeeDevice::start()
{
	unsigned char CMD_STARTUP_FROM_APP_BYTES[7] = {0xfe, 0x02, 0x25, 0x40, 0x00, 0x00, 0x67};

	//Serial.println("------start--------");
	//�������������������
	Serial.write(CMD_STARTUP_FROM_APP_BYTES, 7);
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