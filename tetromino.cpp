#include "tetromino.h"
#include <ncurses.h>

void tetromino::draw(int rot, char letter, int currentPiece, int currentpos_x, int currentpos_y) {
    for (int py = 0; py < 4; py++)
        for (int px = 0; px < 4; px++) {
            move(currentpos_x+px,currentpos_y+py+6);
            if (tetro[currentPiece][rotate(py, px, rot)]!='.')
                printw("%c", letter);
        }
    }

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
            pi = 12 + point_x - (point_y * 4);
            break;
        // array begin from 15 - 180 degrees rotation
        case 2:
            pi = 15 - (point_x * 4) - point_y;
            break;
        // array begin from 3 - 270 degrees rotation
        case 3:
            pi = 3 - point_x + (point_y * 4);
            break;
    }
    return pi;
}

