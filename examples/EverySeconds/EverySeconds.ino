#include <IntervalCallback.h>

const unsigned long INTERVAL = 500;
void onInterval();
int num = 0;
IntervalCallback interval(INTERVAL, onInterval);

void setup() {
	Serial.begin(57600);
	interval.start();
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
