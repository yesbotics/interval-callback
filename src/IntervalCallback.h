#ifndef INTERVAL_H
#define INTERVAL_H

#include <Arduino.h>

class IntervalCallback {

public:
	typedef void (*ExternalCallbackPointer)();
    IntervalCallback(unsigned long intervalMillis, ExternalCallbackPointer onIntervalCallbackPointer);
	void start();
	void stop();
	void loop();
	boolean isRunning();
protected:

private:
	ExternalCallbackPointer onIntervalCallbackPointer;
	unsigned long intervalLength;
	unsigned long lastMillis;
    boolean running = false;
};

#endif
