#include<ncurses.h>
#include "board.h"
//#include "game.h"

Board::Board() {

    board = new bool *[get_width()+2];
    for (int i = 0; i < get_width()+2; ++i) {
        board[i] = new bool[get_height()+1];
        for (int j = 0; j < get_height()+1; ++j) {
            board[i][j] = false;
//            if(j>17)
//                Board[i][j]= true;
        }
    }
    for (int i = 0; i < get_width()+1; ++i)
        board[i][20]=true;
        for(int j = 0;j<get_height(); j++){
            board[0][j]=true;
            board[11][j]=true;}
}
void Board::draw_self(){

    //boundary
    for (int i = 0; i < get_height(); i++) {
        move(i+1, 6); // otherwise the box won't draw
        printw("|");
        move(i+1, get_width()+7);
        printw("|");
        }
    move(21,6);
    for(int j = 0; j < get_width()+2; j++)
        printw("-");
    //currentpieces
    for(int i=1; i<get_width()+1;i++)
        for(int j=1;j<get_height()-1;j++)
            if(board[i][j]) {
                move(j+1, i+6);
                printw("X");
            }
}

bool Board::checkRows(int rowNum) {
    for (int i = 0; i < get_width()+1; i++)
        if(!board_get(i, rowNum))
            return false;
    return true;
}

void Board::move_lines(int rowcleared) {
    for(int j=rowcleared; j>0; j--)
        for (int i = 0; i < get_width()+1; i++)
            board_set(i, j,board_get(i,j-1));
}
Board::~Board(){
    for(int i=0;i<get_width();++i)
        delete[] board[i];
    delete[] board;
}
