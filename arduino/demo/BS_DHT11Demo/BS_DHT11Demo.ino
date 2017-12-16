/*
 Name:		DHTDemo.ino
 Created:	2017/12/16 12:41:31
 Author:	ahui
*/

//���ʹ���߼���ѹ��3.3V�İ��ӣ�����Arduino Due����ô��Ҫ����pin 1����3.3V����5v

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
  //�ȴ�����������
  delay(2000);

  // ��ȡtemperature����humidity��Ҫ���250ms!
  // ��ȡ��������2ǰ������ (������������)

  //��ȡʪ��
  float h = dht.readHumidity();
  //��ȡ�¶�(Ĭ��Ϊ���϶�)
  float t = dht.readTemperature();

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("��ȡʧ��");
    return;
  }

  // ������ָ��(isFahreheit = false)
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