#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H


class Board {
private:
    bool **board;
    const int height = 21;
    const int width = 10;
public:
    Board();
    ~Board();
    int get_height() const {return height;}
    int get_width() const {return width;}
    bool board_get(int x, int y) const {return board[x][y];}
    void board_set(int x, int y, bool z){board[x][y] = z;}
    bool add_to_board(/* tetromino */); //in game class
    void move_lines(int rowcleared);
    bool checkRows(int rowNumber);
    void draw_self();
};


#endif //TETRIS_BOARD_H
