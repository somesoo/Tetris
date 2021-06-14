#include<ncurses.h>
#include "board.h"
//#include "game.h"

board::board() {

    Board = new bool *[get_width()+2];
    for (int i = 0; i < get_width()+2; ++i) {
        Board[i] = new bool[get_height()+1];
        for (int j = 0; j < get_height()+1; ++j) {
            Board[i][j] = false;
//            if(j>17)
//                Board[i][j]= true;
        }
    }
    for (int i = 0; i < get_width(); ++i)
        Board[i][21]=true;
        for(int j = 0;j<get_height(); j++){
            Board[0][j]=true;
            Board[11][j]=true;}
}
void board::draw_self(){
    for (int i = 0; i < get_height(); i++) {
        move(i+1, 6); // otherwise the box won't draw
        printw("X");
        move(i+1, get_width()+7);
        printw("X");
        }
    move(21,6);
    for(int j = 0; j < get_width()+2; j++)
        printw("X");
    refresh();
}
board::~board(){
    for(int i=0;i<get_width();++i)
        delete[] Board[i];
    delete[] Board;
}