#include<ncurses.h>
#include "board.h"


board::board() {

    Board = new bool*[get_width()];
    for(int i=0;i<get_width();++i){
        Board[i] = new bool[get_height()];
            for(int j=0;j<get_height();++j)
            Board[i][j] = 0;}
//    initscr();
//    for(int i=0;i<get_height();++i) {
//        printw("X");
//        for (int j = 0; j < get_width(); ++j)
//            printw("%c", Board[j][i]);
//        printw("X\n");}
//    for(int i=0;i<get_width()+2;++i)
//        printw("X");
//    refresh();
//    getchar();
//    endwin(); //kończenie
}
board::~board(){
    for(int i=0;i<get_width();++i)
        delete[] Board[i];
    delete[] Board;
}