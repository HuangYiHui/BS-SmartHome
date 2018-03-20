#include "Arduino.h"

class Base
{
public:
	Base()
	{
		Serial.println("Base build");
	}
	virtual void init()
	{
		Serial.println("Base");
		state = 123;
	}
	int getState(){
		return state;
	}
protected:
	int state;
};

class Son : public Base
{
public:
	Son()
	{
		Serial.println("Son build");
	}
	void init()
	{
		Serial.println("Son");
		state = 321;
		Base::init();
	}
};