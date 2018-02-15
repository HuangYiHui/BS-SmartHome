#include "pm25Task.h"

static struct pt pt;

void initPM25Task()
{
	pinMode(PIN_PM25_LED, OUTPUT);

	PT_INIT(&pt);
}

static int run()
{
	PT_BEGIN(&pt);
	unsigned int samplingTime = 280;  
	unsigned int deltaTime = 40;  
	unsigned int sleepTime = 9680;  
  
	float voMeasured = 0;  
	float calcVoltage = 0;  
	float dustDensity = 0;

	while (1)
	{
		PT_TIMER_DELAY(&pt,1500);

		digitalWrite(PIN_PM25_LED, LOW);  
		delayMicroseconds(samplingTime);  
  
		voMeasured = analogRead(PIN_PM25_VO);  
  
		delayMicroseconds(deltaTime);  
		digitalWrite(PIN_PM25_LED, HIGH);  
		delayMicroseconds(sleepTime);  
  
		calcVoltage = voMeasured*(5.0/1024);  
		dustDensity = 0.17*calcVoltage-0.1;  
  
		if ( dustDensity < 0)  
		{  
		dustDensity = 0.00;  
		}  
  
		Serial.println("Raw Signal Value (0-1023):");  
		Serial.println(voMeasured);  
  
		Serial.println("Voltage:");  
		Serial.println(calcVoltage);  
  
		Serial.println("Dust Density:");  
		Serial.println(dustDensity);  
	}
	PT_END(&pt);
}

void runPM25Task()
{
	run();
}