#include "Arduino.h"
#include <IntervalCallback.h>

IntervalCallback interval;

int num = 0;

void setup() {
	Serial.begin(57600);
	interval.start(1000, onInterval);
}

void loop() {
	interval.loop();
}

void onInterval() {
	Serial.print("got interval ");
	Serial.println(String(num));
	num++;
	if (num > 10) {
		Serial.println("stop it");
		interval.stop();
	}
}
