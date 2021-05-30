#include<ncurses.h>
#include "board.h"


board::board() {

    Board = new bool*[get_width()];
    for(int i=0;i<get_width();++i){
        Board[i] = new bool[get_height()];
            for(int j=0;j<get_height();++j)
            Board[i][j] = false;}
}
board::~board(){
    for(int i=0;i<get_width();++i)
        delete[] Board[i];
    delete[] Board;
}