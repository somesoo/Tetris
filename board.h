#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H


class board {
    bool **Board;
    const int height = 21;
    const int width = 10;
public:
    board();
    ~board();
    int get_height() const {return height;}
    int get_width() const {return width;}
    bool board_get(int x, int y) const {return Board[x][y];}
    void board_set(int x, int y, bool z){Board[x][y] = z;}
    bool add_to_board(/* tetromino */); //in game class
    void clear_lines();
    bool checkRows(int rowNumber);
    void draw_self();
};


#endif //TETRIS_BOARD_H
