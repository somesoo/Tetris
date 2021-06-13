//
// Created by johnny on 30.05.2021.
//

#ifndef TETRIS_POINT_H
#define TETRIS_POINT_H


class point {
    int x;
    int y;
public:
    int get_x(){return x;}
    int get_y(){return y;}
    point(){x=0; y=0;}
    point(int px,int py): x(px), y(py){}
    void setX(int newX){x=newX;}
    void setY(int newY){x=newY;}
};


#endif //TETRIS_POINT_H
