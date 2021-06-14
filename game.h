#include "board.h"
#include "point.h"
#include "tetromino.h"
#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

// start/stop game, make new piece

class game {
    int score=0;
    bool isOver = true;
public:
    game();
    static int get_score();
    bool check_collisions(int currentTetromino, int currentRotation, int posY, int posX, tetromino &piece, board &matrix);
    point possition(){point poss;return poss;}
    tetromino new_falling_tetromino();
//    void pause();
//    void play();
    void start_game();
    bool is_over() const {return isOver;}
    void game_over() {isOver=true;}
    void moving(tetromino &piece, board &matrix);

};
static int score = 0;

#endif //TETRIS_GAME_H
