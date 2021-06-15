#include "board.h"
#include "point.h"
#include "tetromino.h"
#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

// start/stop game, make new piece

class Game {
private:
    bool isOver = false;
public:
    Game();
    Game(const Game &object){
        isOver=object.isOver;}
    Game & operator=(const Game&object){
        isOver=object.isOver;
        return *this;}
    static int score;
    static int piece_count;
    static int tick;
    void start_game();
    bool check_collisions(int currentTetromino, int currentRotation, int posY, int posX, tetromino &piece, Board &matrix);
    tetromino new_falling_tetromino();
    void check_for_lock(tetromino &piece, Board &matrix, int currentTetromino, int currentRotation, int posY, int posX);
    bool is_over() const {return isOver;}
    void game_over();
    void moving(tetromino &piece, Board &matrix);
    void clear_lines(Board &matrix, tetromino &piece);
};

#endif //TETRIS_GAME_H
