//
// Created by kevin on 09/07/19.
//

#include "Timer.h"
#include <chrono>

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

void Timer::setStart(const time_point<steady_clock> &start) {
    Timer::start = start;
}

int Timer::getDuration() const {
    return duration.count();
}

void Timer::setDuration(const int duration) {
    Timer::duration = ::duration<int>(duration);
}

bool Timer::isRunning() const {
    return running;
}

void Timer::setRunning(bool running) {
    Timer::running = running;
}

void Timer::startTimer() {
    if(!running){
        start = steady_clock::now();
        running = true;
    }
}

void Timer::stopTimer() {
    if(running){
        time_point<steady_clock> now = steady_clock::now();
        running = false;
        duration = duration_cast<seconds>(now - start);
    }
}
