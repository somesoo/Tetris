#include "board.h"
#include "point.h"
#include "tetromino.h"
#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

// start/stop game, make new piece

class game {
    bool isOver = true;
public:
    game();
    static int score;
    static int piece_count;
    bool check_collisions(int currentTetromino, int currentRotation, int posY, int posX, tetromino &piece, board &matrix);
    point possition(){point poss;return poss;}
    tetromino new_falling_tetromino();
    void check_for_lock(tetromino &piece, board &matrix, int currentTetromino, int currentRotation, int posY, int posX);
//    void pause();
//    void play();
    void start_game();
    bool is_over() const {return isOver;}
    void game_over() {isOver=true;}
    void moving(tetromino &piece, board &matrix);

};
static int score = 0;
static int piece_count=0;

#endif //TETRIS_GAME_H
