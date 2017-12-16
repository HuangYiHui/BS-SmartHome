#define TOUCH_SIG 13

//获取状态
boolean get_touch(){
  boolean touch_stat=0;
  touch_stat=digitalRead(TOUCH_SIG);//读入状态
  return touch_stat;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(TOUCH_SIG,INPUT);       //设置13号端口为输入模式
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