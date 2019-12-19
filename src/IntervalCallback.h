#ifndef INTERVAL_H
#define INTERVAL_H

#include <Arduino.h>

class IntervalCallback {

public:
	typedef void (*ExternalCallbackPointer)();
	void start(unsigned long intervalLength, ExternalCallbackPointer onIntervalCallbackPointer);
	void stop();
	void loop();
protected:

private:
	ExternalCallbackPointer onIntervalCallbackPointer;
	unsigned long intervalLength;
	unsigned long lastMillis;
};

#endif
