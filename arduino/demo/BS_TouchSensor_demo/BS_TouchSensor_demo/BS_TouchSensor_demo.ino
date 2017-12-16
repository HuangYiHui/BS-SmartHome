#define TOUCH_SIG 13

//��ȡ״̬
boolean get_touch(){
  boolean touch_stat=0;
  touch_stat=digitalRead(TOUCH_SIG);//����״̬
  return touch_stat;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(TOUCH_SIG,INPUT);       //����13�Ŷ˿�Ϊ����ģʽ
  Serial.begin(115200);
}

void loop() {
  boolean touch_stat;
  // put your main code here, to run repeatedly:  
  Serial.print("\nrunning\nTouch Stat - "); 
  touch_stat=get_touch();
  Serial.print(touch_stat);
  delay(1000);
}