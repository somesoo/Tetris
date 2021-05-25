#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H


class board {
    bool **Board;
    const int height = 20;
    const int width = 10;
public:
    board();
    ~board();
    int get_height() const {return height;}
    int get_width() const {return width;}
    bool board_get(int x, int y){return Board[x][y];}
    void board_set(int x, int y, bool z){Board[x][y] = z;}
};


#endif //TETRIS_BOARD_H
