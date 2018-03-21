#include "ZigbeeDevice.h"

ZigbeeDevice::ZigbeeDevice(unsigned int deviceID) : SampleDevice(deviceID)
{
}

void ZigbeeDevice::init()
{
	unsigned char CMD_DEVICE_RESET_BYTES[6] = {0xfe, 0x01, 0x41, 0x00, 0x00, 0x40};
	unsigned char CMD_STARTUP_WITHOUT_LAST_STATE_BYTES[8] = {0xfe, 0x03, 0x26, 0x05, 0x03, 0x01, 0x03, 0x21};
	unsigned char CMD_ZDO_DIRECT_CB_BYTES[8] = {SOF, 0x03, 0x26, 0x05, 0x8f, 0x01, 0x01, 0xaf};
	//信道使用0x00000800
	unsigned char CMD_CHANNEL_SET_BYTES[11] = {0xfe, 0x06, 0x26, 0x05, 0x84, 0x04, 0x00, 0x08, 0x00, 0x00, 0xad};
	//工作子网为0xffff
	unsigned char CMD_PANID_SET_BYTES[9] = {0xfe, 0x04, 0x26, 0x05, 0x83, 0x02, 0xff, 0xff, 0xa6};
	//设备类型0x01,路由器
	unsigned char CMD_DEVICE_TYPE_SET_BYTES[8] = {0xfe, 0x03, 0x26, 0x05, 0x87, 0x01, 0x01, 0xa7};
	//应用注册
	unsigned char CMD_APP_REGISTER_BYTES[14] = {0xfe, 0x09, 0x24, 0x00, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78};


	//重启，时间太短不行，比如1000
	Serial.write(CMD_DEVICE_RESET_BYTES, 6);
	delay(2000);
	//rec(1500);

	//设置不从上次状态启动
	Serial.write(CMD_STARTUP_WITHOUT_LAST_STATE_BYTES, 8);
	delay(500);
	//rec(300);

	//重启
	Serial.write(CMD_DEVICE_RESET_BYTES, 6);
	delay(2000);
	//rec(1500);
	
	//设置0x00000800信道，默认也是0x00000800信道
	Serial.write(CMD_CHANNEL_SET_BYTES, 11);
	delay(500);
	//rec(300);

	//设置工作子网
	Serial.write(CMD_PANID_SET_BYTES, 9);
	delay(500);
	//rec(300);

	//设置zigbee设备类型（协调器/路由器/终端）
	Serial.write(CMD_DEVICE_TYPE_SET_BYTES, 8);
	delay(500);
	//rec(300);

	//打开设备mac地址或网络地址查寻回显开关
	Serial.write(CMD_ZDO_DIRECT_CB_BYTES, 8);
	delay(500);
	//rec(300);
	
	//注册应用
	Serial.write(CMD_APP_REGISTER_BYTES, 14);
	delay(500);

	state = DEVICE_STATE_READY;
}

void ZigbeeDevice::start()
{
	unsigned char CMD_STARTUP_FROM_APP_BYTES[7] = {0xfe, 0x02, 0x25, 0x40, 0x00, 0x00, 0x67};

	//Serial.println("------start--------");
	//建立网络或者连接网络
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
	//判断信息包是否开始
	//返回默认msg，表示读取到了无效的dataPacket（len=0）
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

	//等于-1表示在规定时间内没读到后续字节
	//当前数据传输有问题，终止当前传输
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

	//读取的数据长度表示在制定时间内没有足够的数据传过来，认为此次通信有问题
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