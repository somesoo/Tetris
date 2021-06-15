#include <ncurses.h>
#include <time.h>
#include <thread>
#include "game.h"

int Game::score = 0;
int Game::piece_count = 0;

Game::Game()
{
    srand((unsigned) time(NULL));
}

void Game::game_over() {
    isOver=true;
    move(0,0);
    printw("game over");
    getchar();
    clear();
    move(0,0);
    printw("game over\nYour score: %i", Game::score);
    refresh();
}

//function that chooses random piece and it rotation, as well as set it start coordinates
tetromino Game::new_falling_tetromino() {
    tetromino piece(4,0, rand()%6,rand()%3);
    return piece;
}
void Game::start_game() {
    noecho();
    cbreak();
    Board plansza;
    unsigned int tick = 500;
    while(!is_over()) {
        //default game wait time
        //std::this_thread::sleep_for(std::chrono::milliseconds(tick));
        //clearing screen for new possition
        clear();
        //creating new piece to be shown on board
        tetromino piece = new_falling_tetromino();



        //game over conndition
        if(!check_collisions(piece.get_current(), piece.get_rotation(), piece.get_poss().get_y(),piece.get_poss().get_x()+1, piece, plansza))
            game_over();
        //loop to check while piece can still move down, if so do it
        while(check_collisions(piece.get_current(), piece.get_rotation(), piece.get_poss().get_y(),piece.get_poss().get_x()+1, piece, plansza)) {
            std::this_thread::sleep_for(std::chrono::milliseconds(tick));


            //clearing screen for new possition with current piece
            clear();


            // default gravity
            if (check_collisions(piece.get_current(), piece.get_rotation(), piece.get_poss().get_y(),piece.get_poss().get_x() + 1, piece, plansza))
                //piece.set_possition_x(piece.get_poss().get_x() + 1);

                //get movement from player
                moving(piece, plansza);




            //updating score if piece get locked
            if(!check_collisions(piece.get_current(), piece.get_rotation(), piece.get_poss().get_y(),piece.get_poss().get_x()+1, piece, plansza)) {
                Game::score = Game::score + 10;
                Game::piece_count++;

                //locking piece into possition
                check_for_lock(piece, plansza, piece.get_current(), piece.get_rotation(), piece.get_poss().get_y(),
                               piece.get_poss().get_x());

                clear_lines(plansza, piece);

            }


            //drawing current piece
            piece.draw(piece.get_rotation(), 'X', piece.get_current(), piece.get_poss());


            //drawing board - boundary and already solid places
            plansza.draw_self();

            //drawing score and piece counter
            move(22, 0);
            printw("Score: %i\nPiece counter: %i", Game::score, Game::piece_count);


            //updating screen
            refresh();

        }
    }
}

int khirt()
{
    nodelay(stdscr, TRUE);
    int num = getch();
    if(num!=ERR)
        return num;
    else
        return 115;
}
void Game::moving(tetromino &piece, Board &matrix){

    int num = khirt();

//  right   279167 // 100
//  left    279168 // 97
//  down    279166 // 115
//  rotate X 120
//  space   32
    switch (num) {
        case 100:
            //printw("right\n");
            if(check_collisions(piece.get_current(), piece.get_rotation(), piece.get_poss().get_y()+1,piece.get_poss().get_x(), piece, matrix))
            piece.set_possition_y(piece.get_poss().get_y()+1);
            piece.set_possition_x(piece.get_poss().get_x()+1);
            move(8,20);
            printw("right");
            refresh();
            break;
        case 97:
            //printw("left\n");
            if(check_collisions(piece.get_current(), piece.get_rotation(), piece.get_poss().get_y()-1,piece.get_poss().get_x(), piece, matrix))
            piece.set_possition_y(piece.get_poss().get_y()-1);
            piece.set_possition_x(piece.get_poss().get_x()+1);
            move(8,20);
            printw("left");
            refresh();
            break;
        case 115:
            //printw("down\n");
            if(check_collisions(piece.get_current(), piece.get_rotation(), piece.get_poss().get_y(),piece.get_poss().get_x()+1, piece, matrix))
            piece.set_possition_x(piece.get_poss().get_x()+1); // moving piece down is working fine
            move(8,20);
            printw("down");
            refresh();
            break;
        case 120:
            //printw("rotate\n");
            //piece.set_rotation(getchar());
            if(check_collisions(piece.get_current(), piece.get_rotation()+1, piece.get_poss().get_y(),piece.get_poss().get_x(), piece, matrix))
            piece.set_rotation(piece.get_rotation()+1);
            piece.set_possition_x(piece.get_poss().get_x()+1);
            move(8,20);
            printw("rotate");
            refresh();
            break;
        case 32:
            //printw("space\n");
            if(check_collisions(piece.get_current(), piece.get_rotation()+1, piece.get_poss().get_y(),piece.get_poss().get_x(), piece, matrix))
            piece.set_rotation(piece.get_rotation()+1);
            piece.set_possition_x(piece.get_poss().get_x()+1);
            move(8,20);
            printw("rotate");
            refresh();
            break;
        case 113:
            game_over();
            break;
        default:
            move(8,20);
            printw("wrong input");
            refresh();
    }
}

bool Game::check_collisions(int currentTetromino, int currentRotation, int posY, int posX, tetromino &piece, Board &matrix) {
// creating loops for checking each character in array
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++) {
            //if(piece.tetro[currentTetromino][piece.rotate(py, px, currentRotation)]!='.')
            if (piece.tetro[currentTetromino][piece.rotate(py, px, currentRotation)]!='.' && matrix.board_get((posY+py),(posX+px))!=0)
                return false;
        }
    return true;
}

void Game::check_for_lock(tetromino &piece, Board &matrix, int currentTetromino, int currentRotation, int posY, int posX) {
    //if(!check_collisions(piece.get_current(), piece.get_rotation(), piece.get_poss().get_y(),piece.get_poss().get_x()+1, piece, matrix))
        for (int px = 0; px < 4; px++)
            for (int py = 0; py < 4; py++)
                if(piece.tetro[currentTetromino][piece.rotate(py, px, currentRotation)]!='.'){
                    matrix.board_set((posY+py),(posX+px),1);}
}

void Game::clear_lines(Board &matrix, tetromino &piece) {
int combopoints=0;
    for(int i=0; i<matrix.get_height()-1; i++) {
        if(matrix.checkRows(i)) {
            combopoints++;
            for (int j = 0; j < matrix.get_width() + 1; j++)
                matrix.board_set(j, i, 0);
            matrix.move_lines(i);
        }
    }
Game::score=Game::score+(combopoints*25);
}