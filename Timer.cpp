//
// Created by kevin on 09/07/19.
//

#include "Timer.h"
#include <chrono>
#include <math.h>
#include <functional>

using namespace std;
using namespace std::chrono;

Timer::Timer() {
    start = steady_clock::now();
    duration = ::duration<int>::zero();
    running = false;
}

const time_point<steady_clock> &Timer::getStart() const {
    return start;
}

int Timer::getDuration() const {
    if(!running) {
        return (int)round(duration.count()/1000);
    }
    else{
        time_point<steady_clock> now = steady_clock::now();
        return (int)round((duration.count() - duration_cast<milliseconds>(now - start).count())/1000);
    }
}

bool Timer::setDuration(const unsigned int seconds) {
    if(!running) {
        if (seconds > 0) {
            duration = ::duration < int, milli > (seconds * 1000);
            return true;
        }
        return false;
    }
    throw bad_function_call();
}

bool Timer::isRunning() const {
    return running;
}

bool Timer::startTimer(){
    if(duration != ::duration<int>::zero()) {
        if (!running) {
            start = steady_clock::now();
            running = true;
            return true;
        }
        return false;
    }
    throw bad_function_call();
}

bool Timer::stopTimer() {
    if(running){
        time_point<steady_clock> now = steady_clock::now();
        running = false;
        if(duration_cast<milliseconds>(now - start) < duration) {
            duration = duration - duration_cast<milliseconds>(now - start);
            return true;
        }
        return false;
    }
    return false;
}

void Timer::resetTimer() {
    start = steady_clock::now();
}
