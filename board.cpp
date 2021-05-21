//
// Created by johnny on 21.05.2021.
//
#include<ncurses.h>
#include "board.h"

void board::displayBoard() {
    initscr();
    for(int i=0;i<get_height();++i) {
        printw("X");
        for (int j = 0; j < get_width(); ++j)
            printw("%c", brd[j][i]);
        printw("X\n");
    }
    for(int i=0;i<get_width()+2;++i)
        printw("X");
    refresh();
    getchar();
    endwin(); //kończenie
}

board::board() {
    for(int i=0;i<get_width();++i)
        for(int j=0;j<get_height();++j)
            brd[i][j] = '0';
}