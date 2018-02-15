#include "doorbellTask.h"

static struct pt pt;
int melody[] = {
  262, 196, 196, 220, 196
};

// 4代表四分音符，8代表8分音符，以此类推:
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
			// 要根据音符种类计算播放每个音符播放的时间，只需要使用一秒除以音符的种类
			//例如，四分音符播放时间为1000 / 4,八分音符播放时间为=1000/8,以此类推。
			int noteDuration = 1000 / noteDurations[thisNote];
			tone(PIN_BELL, melody[thisNote], noteDuration);

			// 为了让人耳能够分辨清楚每个音符，设置播放每个音符间的最小间隔时间。音符的播放时间*1.3作为间隔时间是比较好的选择:
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