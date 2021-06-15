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
    Board(const Board &object){
        board=object.board;}
    Board & operator=(const Board&object){
        board=object.board;
        return *this;}
    //getters
    int get_height() const {return height;}
    int get_width() const {return width;}
    bool board_get(int x, int y) const {return board[x][y];}
    //setting location on board to choosen walue
    void board_set(int x, int y, bool z){board[x][y] = z;}
    //after clearing lines, move every line above down
    void move_lines(int rowcleared);
    //check if row is full
    bool checkRows(int rowNumber);
    //draw board current status
    void draw_self();
};


#endif //TETRIS_BOARD_H
