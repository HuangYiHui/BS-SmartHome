#include "dht11Task.h"

static struct pt pt;
DHT dht11(PIN_DHT11, DHTTYPE);

void initDHT11Task()
{
	PT_INIT(&pt);
	dht11.begin();
}

static int run()
{
	PT_BEGIN(&pt);
	while (1)
	{
		PT_TIMER_DELAY(&pt,1500);
	
		// ��ȡtemperature����humidity��Ҫ���250ms!
		// ��ȡ��������2ǰ������ (������������)

		//��ȡʪ��
		float h = dht11.readHumidity();
		//��ȡ�¶�(Ĭ��Ϊ���϶�)
		float t = dht11.readTemperature();

		// Check if any reads failed and exit early (to try again).
		if (isnan(h) || isnan(t)) {
			Serial.println("��ȡʧ��");
		}
		else{

			// ������ָ��(isFahreheit = false)
			float hic = dht11.computeHeatIndex(t, h, false);

			Serial.print("Humidity: ");
			Serial.print(h);
			Serial.print(" %");
			Serial.println();

			Serial.print("Temperature: ");
			Serial.print(t);
			Serial.print(" *C");
			Serial.println();
 
			Serial.print("Heat index: ");
			Serial.print(hic);
			Serial.println();
			Serial.println();
		}
	}
	PT_END(&pt);
}

void runDHT11Task()
{
	run();
}