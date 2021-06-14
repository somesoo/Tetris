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
        Board[i][20]=true;
        for(int j = 0;j<get_height(); j++){
            Board[0][j]=true;
            Board[11][j]=true;}
}
void board::draw_self(){

    //boundary
    for (int i = 0; i < get_height(); i++) {
        move(i+1, 6); // otherwise the box won't draw
        printw("X");
        move(i+1, get_width()+7);
        printw("X");
        }
    move(21,6);
    for(int j = 0; j < get_width()+2; j++)
        printw("X");
    //currentpieces
    for(int i=1; i<get_width();i++)
        for(int j=1;j<get_height();j++)
            if(Board[i][j]) {
                move(j+1, i+6);
                printw("X");
            }
}
board::~board(){
    for(int i=0;i<get_width();++i)
        delete[] Board[i];
    delete[] Board;
}

void board::clear_lines() {
    int a=0;
    for(int i = 0; i<get_height(); i++)
        for(int j = 0; j<get_width(); j++)
            if(Board[i][j]==1)
                a++;
            if(a==8)
                printw("Clear line");

}
