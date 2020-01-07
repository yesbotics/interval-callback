#include "IntervalCallback.h"

IntervalCallback::IntervalCallback(unsigned long intervalMillis, ExternalCallbackPointer onIntervalCallbackPointer) {
	this->onIntervalCallbackPointer = onIntervalCallbackPointer;
	this->intervalLength = intervalMillis;
}

void IntervalCallback::start() {
	this->lastMillis = millis();
    this->running = true;
}

void IntervalCallback::stop() {
    this->running = true;
}

// Call this in Arduino loop() function
void IntervalCallback::loop() {
	if (this->running) {
		unsigned long currentMillis = millis();
		if ((currentMillis - this->lastMillis) >= this->intervalLength) {
			this->lastMillis = currentMillis;
			this->stop();
			this->onIntervalCallbackPointer();
		}
	}
}
