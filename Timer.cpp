//
// Created by kevin on 09/07/19.
//

#include "Timer.h"
#include <chrono>
#include <math.h>
#include <functional>
#include <string>

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

int Timer::getDuration() {
    if(!running) {
        return (int)round(duration.count()/1000);
    }
    else{
        time_point<steady_clock> now = steady_clock::now();
        float r = (duration - duration_cast<milliseconds>(now-start)).count()/1000.f;
        int remaining = r >= 0 ? (int)ceil(r) : (int)floor(r);
        return remaining;
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
        if (!running || getDuration() < 0) {
            start = steady_clock::now();
            running = true;
            return true;
        }
        return false;
    }
    throw bad_function_call();  //Before starting timer you need to set duration
}

bool Timer::stopTimer() {
    if(running){
        time_point<steady_clock> now = steady_clock::now();
        running = false;
        ::duration<int, milli> remaining = duration - duration_cast<milliseconds>(now - start);
        if(remaining.count() > 0) {
            duration = remaining;
            return true;
        }
        return false;
    }
    return false;
}

void Timer::resetTimer() {
    start = steady_clock::now();
}

string Timer::getDurationString() const {
    return std::__cxx11::string();
}
