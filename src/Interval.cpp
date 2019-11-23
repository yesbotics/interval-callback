#include "Interval.h"

void Interval::start(unsigned long intervalLength, ExternalCallbackPointer onIntervalCallbackPointer) {
	this->onIntervalCallbackPointer = onIntervalCallbackPointer;
	this->intervalLength = intervalLength;
	this->lastMillis = millis();
}

void Interval::stop() {
	this->onIntervalCallbackPointer = 0;
}

void Interval::loop() {
	if (this->onIntervalCallbackPointer != 0) {
		unsigned long currentMillis = millis();
		if ((currentMillis - this->lastMillis) >= this->intervalLength) {
			this->lastMillis = currentMillis;
			this->onIntervalCallbackPointer();
		}
	}
}
