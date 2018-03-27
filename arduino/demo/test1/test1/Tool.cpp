#include "Tool.h"

//所有转换结果为小端模式

void Tool::intTo2Bytes(int n, unsigned char* result)
{
	IBConv conv;
	conv.n = n;
	result[0] = conv.bs[0];
	result[1] = conv.bs[1];
}

void Tool::floatTo4Bytes(float f, unsigned char* result)
{
	FBConv conv;
	conv.f = f;
	result[0] = conv.bs[0];
	result[1] = conv.bs[1];
	result[2] = conv.bs[2];
	result[3] = conv.bs[3];
}

int Tool::bytesToInt(unsigned char* bytes)
{
	IBConv conv;
	conv.bs[0] = bytes[0];
	conv.bs[1] = bytes[1];
	return conv.n;
}

float Tool::bytesToFloat(unsigned char* bytes)
{
	FBConv conv;
	conv.bs[0] = bytes[0];
	conv.bs[1] = bytes[1];
	conv.bs[2] = bytes[2];
	conv.bs[3] = bytes[3];
	return conv.f;
}

void Tool::byteArrayCopy(unsigned char* bs1, int begin1, unsigned char* bs2, int begin2, int len)
{
	for(int i=0; i<len; i++)
		bs2[i+begin2] = bs1[begin1+i];
}


void Tool::readBytesFromFlash(int address, unsigned char* buffer, unsigned int count)
{
	for(unsigned int i=0;i <count; i++){
		buffer[i] = pgm_read_byte_near(address+i);
	}
}