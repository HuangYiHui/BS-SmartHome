#include "doorbellTask.h"

static struct pt pt;
int melody[] = {
  262, 196, 196, 220, 196
};

// 4�����ķ�������8����8���������Դ�����:
int noteDurations[] = {
  8,8,4,4,8
};

void initDoorbellTask()
{
	pinMode(PIN_TOUCH_SENSOR,INPUT);
	pinMode(PIN_BELL,OUTPUT);

	PT_INIT(&pt);
}

static int run()
{
	PT_BEGIN(&pt);
	while (1)
	{
		PT_WAIT_UNTIL(&pt, digitalRead(PIN_TOUCH_SENSOR)==1);
		for (int thisNote = 0; thisNote < 5; thisNote++) 
		{
			// Ҫ��������������㲥��ÿ���������ŵ�ʱ�䣬ֻ��Ҫʹ��һ���������������
			//���磬�ķ���������ʱ��Ϊ1000 / 4,�˷���������ʱ��Ϊ=1000/8,�Դ����ơ�
			int noteDuration = 1000 / noteDurations[thisNote];
			tone(PIN_BELL, melody[thisNote], noteDuration);

			// Ϊ�����˶��ܹ��ֱ����ÿ�����������ò���ÿ�����������С���ʱ�䡣�����Ĳ���ʱ��*1.3��Ϊ���ʱ���ǱȽϺõ�ѡ��:
			int pauseBetweenNotes = noteDuration * 1.30;
			delay(pauseBetweenNotes);
			// stop the tone playing:
			noTone(PIN_BELL);
			}
	}
	PT_END(&pt);
}

void runDoorbellTask()
{
	run();
}