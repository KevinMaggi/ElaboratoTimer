//
// Created by kevin on 09/07/19.
//

#ifndef ELABORATOTIMER_TIMER_H
#define ELABORATOTIMER_TIMER_H

#include <chrono>

using namespace std;
using namespace std::chrono;

class Timer {
public:
    Timer();

    const time_point<steady_clock> &getStart() const;

    void setStart(const time_point<steady_clock> &start);

    int getDuration() const;

    void setDuration(const int duration);

    bool isRunning() const;

    void setRunning(bool running);

    void startTimer();
    void stopTimer();

private:
    time_point<steady_clock> start;
    ::duration<int> duration;
    bool running;
};


#endif //ELABORATOTIMER_TIMER_H
