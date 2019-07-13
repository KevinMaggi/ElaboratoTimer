#include <unistd.h>
#include <ncurses.h>

#include <iostream>
#include <thread>
#include "Timer.h"
#include "Chronometer.h"
#include <string>

using namespace std;

int main() {
    initscr();

    /*Timer t;
    t.setDuration(10);

    time_point<steady_clock> start = steady_clock::now();
    t.startTimer();

    while(t.getDuration() > 0){
        string remaining = t.getDurationString(3);

        clear();

        move(2,10);
        printw("TIMER");
        move(4, 15);
        printw(&remaining[0]);
        move(10, 0);
        refresh();

        napms(25);
    }

    time_point<steady_clock> end = steady_clock::now();
    string tempo = to_string(duration_cast<milliseconds>(end-start).count());

    move(2,10);
    printw("TIMER");
    move(4, 15);
    printw("FINE");
    printw(&tempo[0]);
    refresh();*/

    Chronometer c;
    time_point<steady_clock> start = steady_clock::now();
    c.startChrono();

    string time;

    for(int i = 1; i<INT16_MAX; i++){
        time = c.getTimeString(3);

        clear();

        move(2, 10);
        printw("CHRONO");
        move(4, 15);
        printw(&time[0]);
        move(10,0);
        refresh();

        napms(5);
    }

    time_point<steady_clock> end = steady_clock::now();
    string tempo = to_string(duration_cast<milliseconds>(end-start).count());

    move(2,10);
    printw("CHRONO");
    move(4, 15);
    printw(&tempo[0]);
    refresh();

    getch();
    endwin();
}