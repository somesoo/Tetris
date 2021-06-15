#ifndef TETRIS_POINT_H
#define TETRIS_POINT_H


class point {
    int x;
    int y;
public:
    point(){x=0; y=0;}
    point(int py,int px): x(px), y(py){}
    point(const point &object){
        x = object.x;
        y = object.y;}
    point & operator=(const point&object){
        x=object.x;
        y=object.y;
        return *this;}
    //getters
    int get_x(){return x;}
    int get_y(){return y;}
    //set coordinates
    void setX(int newX){x=newX;}
    void setY(int newY){y=newY;}
};


#endif //TETRIS_POINT_H
