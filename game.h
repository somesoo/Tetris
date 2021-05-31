//
// Created by johnny on 30.05.2021.
//

#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

// start/stop game, make new piece

class game {
    int score=0;
    bool isOver = false;
public:
    int get_score(){return score;}
    void check_collisions();
    void new_falling_tetromino();
    void pause();
    void play();
    void start_game() {isOver= true;}
    bool is_over() const {return isOver;}

};


#endif //TETRIS_GAME_H
