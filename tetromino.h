#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H
#include "point.h"
#include <ncurses.h>

class tetromino {
    bool current;
public:
    bool get_current(){return current;}
    bool tetro[4][4];
    int rotate(int point_y, int point_x, int rotateV);
    int moving(int direction);
    void draw(int rotation, char letter);
};

class I_tetromino: public tetromino {
public:
    I_tetromino(){move(20, 20);printw("I - piece");}
    void info(){printw("hey");}
    bool tetro[4][4]={
            {0,0,0,0},
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0}};
};
class J_tetromino: public tetromino {
public:
    J_tetromino(){move(20, 20);printw("J - piece");}
    bool tetro[4][4]={
            {0,0,0,0},
            {0,0,0,1},
            {0,1,1,1},
            {0,0,0,0}};
};
class L_tetromino: public tetromino {
public:
    L_tetromino(){move(20, 20);printw("L - piece");}
    bool tetro[4][4]={
            {0,0,0,0},
            {0,1,0,0},
            {0,1,1,1},
            {0,0,0,0}};
};
class O_tetromino: public tetromino {
public:
    O_tetromino(){move(20, 20);printw("O - piece");}
    bool tetro[4][4]={
            {0,0,0,0},
            {0,1,1,0},
            {0,1,1,0},
            {0,0,0,0}};
};
class S_tetromino: public tetromino {
public:
    S_tetromino(){move(20, 20);printw("S - piece");}
    bool tetro[4][4]={
            {0,0,0,0},
            {0,0,1,1},
            {0,1,1,0},
            {0,0,0,0}};
};
class T_tetromino: public tetromino {
public:
    T_tetromino(){move(20, 20);printw("T - piece");}
    bool tetro[4][4]={
            {0,0,0,0},
            {0,0,1,0},
            {0,1,1,1},
            {0,0,0,0}};
};
class Z_tetromino: public tetromino {
public:
    Z_tetromino(){move(20, 20);printw("Z - piece");}
    bool tetro[4][4]={
            {0,0,0,0},
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0}};
};

#endif //TETRIS_TETROMINO_H
