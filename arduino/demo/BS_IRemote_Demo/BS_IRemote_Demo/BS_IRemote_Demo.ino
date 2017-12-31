
//红外接收管的引脚定义：正对着红外接收管，从左到右依次为：OUT,GND,VCC
//红外接收管可直接接电源
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