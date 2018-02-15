#define PT_USE_TIMER
#define PT_USE_SEM

#include "pt.h"
static struct pt thread1,thread2;
static struct pt_sem sem_LED;
unsigned char i;

void setup() {
  //Set Hardware
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  //Initialize Semaphore
  PT_SEM_INIT(&sem_LED,1);
  //Initialize the Threads
  PT_INIT(&thread1);
  PT_INIT(&thread2);
}

//Blinky LED, 0.5Hz
static int thread1_entry(struct pt *pt)
{
	PT_BEGIN(pt);
  while (1)
  {
    PT_SEM_WAIT(pt,&sem_LED);
    digitalWrite(13,!digitalRead(13));
    PT_TIMER_DELAY(pt,1000);
    PT_SEM_SIGNAL(pt,&sem_LED);
    PT_YIELD(pt); //Check the other events.
  }
  PT_END(pt);
}

//If a series of chars are sent through COM, blink LED13 quickly for 5 times
static int thread2_entry(struct pt *pt)
{
  PT_BEGIN(pt);
  while (1)
  {
    PT_WAIT_UNTIL(pt, Serial.available());
    PT_SEM_WAIT(pt,&sem_LED);
     for (i=0;i<5;i++)
    {
      digitalWrite(13,HIGH);
      PT_TIMER_DELAY(pt,200);
      digitalWrite(13,LOW);
      PT_TIMER_DELAY(pt,200);
    }
    while (Serial.available())
      Serial.read();
    PT_SEM_SIGNAL(pt,&sem_LED);
  }
  PT_END(pt);
}

void loop() {
  //Check each thread by priority
  thread1_entry(&thread1);
  thread2_entry(&thread2);
}