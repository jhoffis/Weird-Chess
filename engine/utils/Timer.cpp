#include "Timer.h"
#include <chrono>
using namespace std::chrono;

long lastLoopTime;

long Timer::nowMillis() {
    return duration_cast< nanoseconds >(system_clock::now().time_since_epoch()).count();
}

double Timer::nowDelta() {
    long time = nowMillis();
    double delta = time - lastLoopTime;
    lastLoopTime = time;
    return delta / 40000000.0;
}

