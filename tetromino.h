#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H
#include "point.h"

class tetromino {
    bool current;
public:
    bool get_current(){return current;}
    bool tetro[4][4];
    int rotate(int point_y, int point_x, int rotateV);
    int move(int direction);
};

class I_tetromino: public tetromino {
public:
    bool tetro[4][4]={
            {0,0,0,0},
            {0,0,0,0},
            {1,1,1,1},
            {0,0,0,0}};
};
class J_tetromino: public tetromino {
public:
    bool tetro[4][4]={
            {0,0,0,0},
            {0,0,0,1},
            {0,1,1,1},
            {0,0,0,0}};
};
class L_tetromino: public tetromino {
public:
    bool tetro[4][4]={
            {0,0,0,0},
            {0,1,0,0},
            {0,1,1,1},
            {0,0,0,0}};
};
class O_tetromino: public tetromino {
public:
    bool tetro[4][4]={
            {0,0,0,0},
            {0,1,1,0},
            {0,1,1,0},
            {0,0,0,0}};
};
class S_tetromino: public tetromino {
public:
    bool tetro[4][4]={
            {0,0,0,0},
            {0,0,1,1},
            {0,1,1,0},
            {0,0,0,0}};
};
class T_tetromino: public tetromino {
public:
    bool tetro[4][4]={
            {0,0,0,0},
            {0,0,1,0},
            {0,1,1,1},
            {0,0,0,0}};
};
class Z_tetromino: public tetromino {
public:
    bool tetro[4][4]={
            {0,0,0,0},
            {1,1,0,0},
            {0,1,1,0},
            {0,0,0,0}};
};

#endif //TETRIS_TETROMINO_H
