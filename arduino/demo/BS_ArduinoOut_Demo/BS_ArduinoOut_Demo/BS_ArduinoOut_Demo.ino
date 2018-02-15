
#include "dht11Task.h"
#include "doorbellTask.h"
#include "pm25Task.h"
#include "fc28Task.h"
#include "gy30Task.h"

void setup() {
	Serial.begin(9600);
	initDHT11Task();
	initDoorbellTask();
	initPM25Task();
	initFC28Task();
	initGY30Task();
}

void loop() {

	runDHT11Task();
	runDoorbellTask();
	runPM25Task();
	runFC28Task();
	runGY30Task();
}
