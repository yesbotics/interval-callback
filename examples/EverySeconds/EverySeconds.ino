#include "Arduino.h"
#include <Interval.h>

Interval int0;

int num = 0;

void setup() {
	Serial.begin(57600);
	int0.start(1000, onInterval);
}

void loop() {
	int0.loop();
}

void onInterval() {
	Serial.print("got interval ");
	Serial.println(String(num));
	num++;
	if (num > 10) {
		Serial.println("stop it");
		int0.stop();
	}
}
