#include "ZigbeeDevice.h"

ZigbeeDevice::ZigbeeDevice(unsigned int deviceID) : SampleDevice(deviceID)
{
}

void ZigbeeDevice::start()
{
	unsigned char buffer[14];

	//重启，时间太短不行，比如1000
	Tool::readBytesFromFlash((unsigned int)CMD_DEVICE_RESET_BYTES, buffer, 6);
	Serial.write(buffer, 6);
	delay(2000);
	//rec(1500);

	//设置不从上次状态启动
	Tool::readBytesFromFlash((unsigned int)CMD_STARTUP_WITHOUT_LAST_STATE_BYTES, buffer, 8);
	Serial.write(buffer, 8);
	delay(500);
	//rec(300);

	//重启
	Tool::readBytesFromFlash((unsigned int)CMD_DEVICE_RESET_BYTES, buffer, 6);
	Serial.write(buffer, 6);
	delay(2000);
	//rec(1500);
	
	//设置0x00000800信道，默认也是0x00000800信道
	Tool::readBytesFromFlash((unsigned int)CMD_CHANNEL_SET_BYTES, buffer, 11);
	Serial.write(buffer, 11);
	delay(500);
	//rec(300);

	//设置工作子网
	Tool::readBytesFromFlash((unsigned int)CMD_PANID_SET_BYTES, buffer, 9);
	Serial.write(buffer, 9);
	delay(500);
	//rec(300);

	//设置zigbee设备类型（协调器/路由器/终端）
	Tool::readBytesFromFlash((unsigned int)CMD_DEVICE_TYPE_SET_BYTES, buffer, 8);
	Serial.write(buffer, 8);
	delay(500);
	//rec(300);

	//打开设备mac地址或网络地址查寻回显开关
	Tool::readBytesFromFlash((unsigned int)CMD_ZDO_DIRECT_CB_BYTES, buffer, 8);
	Serial.write(buffer, 8);
	delay(500);
	//rec(300);
	
	//注册应用
	Tool::readBytesFromFlash((unsigned int)CMD_APP_REGISTER_BYTES, buffer, 14);
	Serial.write(buffer, 14);
	delay(500);

	Tool::readBytesFromFlash((unsigned int)CMD_STARTUP_FROM_APP_BYTES, buffer, 7);
	//Serial.println("------start--------");
	//建立网络或者连接网络
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