#include <unistd.h>
#include <ncurses.h>

#include <iostream>
#include <thread>
#include "Timer.h"
#include <string>

using namespace std;

void printDigit(char c, int x, int y, int size);

int main() {
    initscr();

    Timer t;
    t.setDuration(10);

    int r;
    time_point<steady_clock> start = steady_clock::now();
    t.startTimer();


    while((r = t.getDuration()) > 0){
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
    refresh();

    getch();
    endwin();
}