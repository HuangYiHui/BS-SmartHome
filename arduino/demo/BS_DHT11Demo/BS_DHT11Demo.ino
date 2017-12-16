/*
 Name:		DHTDemo.ino
 Created:	2017/12/16 12:41:31
 Author:	ahui
*/

//如果使用逻辑电压是3.3V的板子，比如Arduino Due，那么需要连接pin 1的来3.3V代替5v

#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");

  dht.begin();
}

void loop() {
  //等待传感器测量
  delay(2000);

  // 读取temperature或者humidity需要大概250ms!
  // 读取的数据是2前的数据 (这种器件很慢)

  //读取湿度
  float h = dht.readHumidity();
  //读取温度(默认为摄氏度)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("读取失败");
    return;
  }

  // 计算热指数(isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

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