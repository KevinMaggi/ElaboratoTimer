//
// Created by kevin on 14/07/19.
//

#include "Display.h"
#include <ncurses.h>
#include <functional>

Display::Display() {
    timer = Timer();
    clock = Clock();
    chrono = Chronometer();
    terminate = false;
}

void Display::init() {
    initscr();

    keypad(stdscr, true);
    nodelay(stdscr, true);

    timer.setDuration(10);

    termWidth = getmaxx(stdscr);
    termHeight = getmaxy(stdscr);
    height = 9;
    width = 25;

    timerWin = newwin(height, width, (termHeight-height)/2, (termWidth - width*3 + 2)/2);
    clockWin = newwin(height, width, (termHeight-height)/2, (termWidth - width*3 + 2)/2 + width - 1);
    chronoWin = newwin(height, width, (termHeight-height)/2, (termWidth - width*3 +2)/2 + 2*width - 2);
    refresh();

    do{
        update();
    }while(!terminate);

    endwin();
}

void Display::update() {
    checkKB();
    erase();
    werase(timerWin);
    werase(chronoWin);

    wborder(timerWin, 0, 0, 0, 0, 0, 0, 0, 0);
    wborder(clockWin, 0, 0, 0, 0, ACS_TTEE, ACS_TTEE, ACS_BTEE, ACS_BTEE);
    wborder(chronoWin, 0, 0, 0, 0, 0, 0, 0, 0);
    mvwprintw(timerWin, 2, 10, "TIMER");
    mvwprintw(clockWin, 2, 10, "CLOCK");
    mvwprintw(chronoWin, 2, 7, "CHRONOMETER");

    if(timer.getDuration() == 0){
        beep();
        tmrTime = "OUT OF TIME";
    }
    else {
        tmrTime = timer.getDurationString();
    }
    chrTime = chrono.getTimeString();
    chrMem = chrono.getMemoryString();



    mvwprintw(timerWin, 5, (width-tmrTime.length())/2, &tmrTime[0]);
    mvwprintw(chronoWin, 4, (width-chrTime.length())/2, &chrTime[0]);
    mvwprintw(chronoWin, 6, (width-chrMem.length())/2, &chrMem[0]);

    wrefresh(timerWin);
    wrefresh(chronoWin);
    wrefresh(clockWin);

    napms(50);
}

void Display::checkKB() {
    int ch = getch();

    switch(ch){
        case 27:            //ESC KEY
            terminate = true;
            break;
        case KEY_UP:
            if(!timer.isRunning()) {
                timer.setDuration(timer.getDuration() + 1);
            }
            break;
        case KEY_DOWN:
            if(!timer.isRunning()) {
                timer.setDuration(timer.getDuration() - 1);
            }
            break;
        case 's':
            try {
                timer.startTimer();
            }
            catch (bad_function_call e){}
            break;
        case 't':
            timer.stopTimer();
            break;
        case 'r':
            timer.resetTimer();
            break;
        case 'w':
            timer.setViewMode(timer.getViewMode()+1);
            break;
        case 'v':
            chrono.startChrono();
            break;
        case ' ':
            chrono.stopChrono();
            break;
        case 'b':
            chrono.resetChrono();
            break;
        case 'n':
            chrono.setViewMode(chrono.getViewMode()+1);
            break;
        default:
            break;
    }
}