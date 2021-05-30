#include "tetromino.h"


int tetromino::rotate(int point_y, int point_x, int rotateV) {
    int pi = 0;
    switch (rotateV % 4)
    {
        // array begin from 0
        case 0:
            pi = point_x * 4 + point_y;
            break;

        // array begin from 12 - 90 degrees rotation
        case 1:
            pi = 12 + point_y - (point_x * 4);
            break;

        // array begin from 15 - 180 degrees rotation
        case 2:
            pi = 15 - (point_y * 4) - point_x;
            break;

        // array begin from 3 - 270 degrees rotation
        case 3:
            pi = 3 - point_y + (point_x * 4);
            break;
    }
    return pi;
}
