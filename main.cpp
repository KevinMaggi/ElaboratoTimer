#include <unistd.h>
#include <ncurses.h>

#include <iostream>
#include <thread>
#include "Timer.h"
#include <string>

using namespace std;

int main() {
    initscr();

    Timer t;
    t.setDuration(15);

    string remaining = to_string(t.getDuration());
    printw(&remaining[0]);

    t.startTimer();

    while(t.getDuration()){
        string remaining = to_string(t.getDuration());

        clear();
        printw(&remaining[0]);
        refresh();
    }

    printw("FINE");
    refresh();

    getch();
    endwin();
}