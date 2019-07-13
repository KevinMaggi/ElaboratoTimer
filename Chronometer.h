//
// Created by kevin on 12/07/19.
//

#ifndef ELABORATOTIMER_CHRONOMETER_H
#define ELABORATOTIMER_CHRONOMETER_H

#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

class Chronometer {
public:
    Chronometer();

    const time_point<steady_clock> &getStart() const;

    string getTimeString(int mode) const;
    int getTime() const;

    string getMemoryString(int mode) const;

    bool isRunning() const;

    bool startChrono();
    bool stopChrono();
    void resetChrono();

private:
    time_point<steady_clock> start;
    ::duration<int, milli> stored;
    bool running;
    ::duration<int, milli> memory;

    static const int secPerDay, secPerHour, secPerMin;

    string stringify(int deciseconds, int mode) const;
};


#endif //ELABORATOTIMER_CHRONOMETER_H
