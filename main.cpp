#include <unistd.h>
#include <ncurses.h>

#include <chrono>
#include <iostream>

using namespace std::chrono;

int main() {
    initscr();

    printw("Hello, world!");
    refresh();

    getch();
    endwin();
}