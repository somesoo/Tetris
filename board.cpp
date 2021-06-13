#include<ncurses.h>
#include "board.h"
#include "game.h"

board::board() {

    Board = new bool *[get_width()];
    for (int i = 0; i < get_width(); ++i) {
        Board[i] = new bool[get_height()];
        for (int j = 0; j < get_height(); ++j)
            Board[i][j] = false;
    }
}
void board::draw_self(){
    for (int i = 0; i < get_height(); i++) {
        move(i, 0); // otherwise the box won't draw
        printw("X");
        //for (int j = 0; j < get_width(); j++)
        //printw(" ");
        move(i, get_width()+1);
        printw("X");
        }
    move(20,0);
    for(int j = 0; j < get_width()+2; j++)
        printw("X");
    refresh();
}
board::~board(){
    for(int i=0;i<get_width();++i)
        delete[] Board[i];
    delete[] Board;
}