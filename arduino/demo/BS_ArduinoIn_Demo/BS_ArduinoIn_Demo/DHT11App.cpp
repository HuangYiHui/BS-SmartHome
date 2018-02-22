#include "DHT11App.h"

DHT11App::DHT11App(DHT11Device& dht11) : dht11(dht11)
{
	this->dht11 = dht11;
}

void DHT11App::init()
{
	dht11.ready();
	dht11.start();
	PT_INIT(&pt);

	state = APP_STATE_READY;
}

void DHT11App::exeCmd()
{
	if(hasNextCommand()){
		Command command = nextCommand();
		if(command.cmd == CMD_OPEN_DEVICE){
			dht11.open();
		}else if(command.cmd == CMD_INIT_DEVICE){
			dht11.init();
		}else if(command.cmd == CMD_START_DEVICE){
			dht11.start();
		}else if(command.cmd == CMD_STOP_DEVICE){
			dht11.stop();
		}else if(command.cmd == CMD_CLASE_DEVICE){
			dht11.close();
		}
	}
}
	
int DHT11App::exeTask()
{
	PT_BEGIN(&pt);
	while(true)
	{
		PT_WAIT_UNTIL(&pt, dht11.getState() == DEVICE_STATE_WORKING);
		PT_TIMER_DELAY(&pt,1000);
		//读取湿度
		float h = dht11.readHumidity();
		//读取温度(默认为摄氏度)
		float t = dht11.readTemperature();

		// Check if any reads failed and exit early (to try again).
		if (isnan(h) || isnan(t)) {
			Serial.println("读取失败");
		}
		else
		{
			// 计算热指数(isFahreheit = false)
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

		PT_YIELD(&pt);
	}
	PT_END(&pt);
}
