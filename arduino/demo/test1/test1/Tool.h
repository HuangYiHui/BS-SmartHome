#ifndef _BS_TOOL_H_
#define _BS_TOOL_H_

#include "Arduino.h"
typedef union IBConv 
{   
    int n;   
    unsigned char bs[2];
}IBConv;

typedef union FBConv 
{   
    float f;   
    unsigned char bs[4];
}FBConv;

class Tool
{
public:
	static void intTo2Bytes(int n, unsigned char* result);
	static void floatTo4Bytes(float f, unsigned char* result);
	static int bytesToInt(unsigned char* bytes);
	static float bytesToFloat(unsigned char* bytes);
	static void byteArrayCopy(unsigned char* bs1, int begin1, unsigned char* bs2, int begin2, int len);
	static void readBytesFromFlash(int address, unsigned char* buffer, unsigned int count);
};

#endif