
//������չܵ����Ŷ��壺�����ź�����չܣ�����������Ϊ��OUT,GND,VCC
//������չܿ�ֱ�ӽӵ�Դ
#include <IRremote.h>  
   
int PIN_RECV = 9;  
IRrecv irrecv(PIN_RECV);  
decode_results results;  
   
void setup()  
{  
  Serial.begin(115200);  
  irrecv.enableIRIn();  
}  
   
void loop() {  
  if (irrecv.decode(&results)) {  
    Serial.println(results.value);  
    irrecv.resume();  
  }  
} 