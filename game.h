#include "board.h"
#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

// start/stop game, make new piece

class game {
    int score=0;
    bool isOver = false;
public:
    game();
    int get_score(){return score;}
    void check_collisions();
    void new_falling_tetromino(int current_tetromino);
    void pause();
    void play();
    void start_game() {isOver= true;}
    bool is_over() const {return isOver;}
    void game_over() {isOver=false;}
    void move(int num);
    int get_move();

};


#endif //TETRIS_GAME_H
