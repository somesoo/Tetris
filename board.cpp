#include<ncurses.h>
#include "board.h"


board::board() {

    Board = new bool*[get_width()];
    for(int i=0;i<get_width();++i){
        Board[i] = new bool[get_height()];
            for(int j=0;j<get_height();++j)
            Board[i][j] = false;}

    for (int i = 0; i < get_height(); i++) {
        move(1 + i, 1); // otherwise the box won't draw
        printw("X");
        for (int j = 0; j < get_width(); j++)
            printw(" ");
        printw("X");
        }
    move(21,1);
    for(int j = 0; j < get_width()+2; j++)
        printw("X");
    move(22, 1);
    printw("Score: %d", 16);
    refresh();
}
board::~board(){
    for(int i=0;i<get_width();++i)
        delete[] Board[i];
    delete[] Board;
}