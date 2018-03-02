#include "DHT11App.h"

DHT11App::DHT11App(unsigned int appID, DHT11Device& dht11) : SampleApp(appID), dht11(dht11)
{
	state = APP_STATE_UNREADY;
}

void DHT11App::init()
{
	dht11.ready();
	dht11.start();
	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void DHT11App::run()
{
	runTask();
}

void DHT11App::prcMsg()
{
}
	
int DHT11App::runTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_TIMER_DELAY(&pt,1000);
		if(dht11.getState() == DEVICE_STATE_WORKING)
		{
			//��ȡʪ��
			float h = dht11.readHumidity();
			//��ȡ�¶�(Ĭ��Ϊ���϶�)
			float t = dht11.readTemperature();

			// Check if any reads failed and exit early (to try again).
			if (isnan(h) || isnan(t)) {
				Serial.println("��ȡʧ��");
			}
			else
			{
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

		PT_YIELD(&pt);
	}
	PT_END(&pt);
}
