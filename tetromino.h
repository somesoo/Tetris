#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H
#include "point.h"
#include <ncurses.h>
#include <string>

//pure virtual class
class Shape{
public:
    virtual void draw(int rotation, char letter, int currentPiece, point currentpos) =0;
};

class tetromino: public Shape {
private:
    int current;
    int rotation;
    point possition;
public:
    //constructor that gives basic start info to the object
    tetromino(int py, int px, int currentPiece, int Rotation): possition(py, px), current(currentPiece), rotation(Rotation) {}
    //copy constructor
    tetromino(const tetromino &object){
        current=object.current;
        rotation=object.rotation;
        possition=object.possition;}
    // equals operator
    tetromino & operator=(const tetromino&object){
        current=object.current;
        rotation=object.rotation;
        possition=object.possition;
        return *this;}
    //getting current piece number [0-6]
    int get_current(){return current;}
    //pieces template
    std::string tetro[7]={
            {"..I...I...I...I."},
            {"..J..JJ...J....."},
            {".....LL..LL....."},
            {"..O..OO..O......"},
            {".S...SS...S....."},
            {".T...T...TT....."},
            {"..Z...Z..ZZ....."}
    };
    //getters
    point get_poss(){return possition;}
    void set_possition_y(int y){possition.setY(y);}
    void set_possition_x(int x){possition.setX(x);}
    int get_rotation(){return rotation;}
    void set_rotation(int rot){rotation=rot;}

    //function that rotates tetrominos
    int rotate(int point_y, int point_x, int rotateV);
    //drawing itself on board before it becomes part of the board
    void draw(int rotation, char letter, int currentPiece, point currentpos);
};

/*
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
*/
#endif //TETRIS_TETROMINO_H
