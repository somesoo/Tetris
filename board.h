//
// Created by johnny on 21.05.2021.
//

#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H


class board {
    const int height = 20;
    const int width = 10;
public:
    char brd[10][20]{};
    int get_height() const {return height;}
    int get_width() const {return width;}
    void displayBoard();
    board();
};


#endif //TETRIS_BOARD_H
