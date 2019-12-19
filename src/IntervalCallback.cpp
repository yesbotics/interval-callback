#include "IntervalCallback.h"

void IntervalCallback::start(unsigned long intervalLength, ExternalCallbackPointer onIntervalCallbackPointer) {
	this->onIntervalCallbackPointer = onIntervalCallbackPointer;
	this->intervalLength = intervalLength;
	this->lastMillis = millis();
}

void IntervalCallback::stop() {
	this->onIntervalCallbackPointer = 0;
}

void IntervalCallback::loop() {
	if (this->onIntervalCallbackPointer != 0) {
		unsigned long currentMillis = millis();
		if ((currentMillis - this->lastMillis) >= this->intervalLength) {
			this->lastMillis = currentMillis;
			this->onIntervalCallbackPointer();
		}
	}
}
