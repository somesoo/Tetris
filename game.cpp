#include <ncurses.h>
#include <time.h>
#include <thread>
#include "game.h"


game::game() {

}
//int choose_random()
//{
//    srand((unsigned) time(NULL));
//    int newpiece=rand()%7+1;
//    return newpiece;
//}
tetromino game::new_falling_tetromino() {
    tetromino piece(4,0, rand()%6,rand()%3);
    return piece;
}
void game::start_game() {
    srand((unsigned) time(NULL));
    board plansza;
    isOver = false;
    unsigned int tick = 100;
    tetromino piece = new_falling_tetromino();
    while(!is_over()){
        std::this_thread::sleep_for(std::chrono::milliseconds(tick));
        clear();
        //if(check_collisions(piece.get_current(), piece.get_rotation(), piece.get_poss().get_y(),piece.get_poss().get_x()+1, piece, plansza));
            //if(piece.get_poss().get_x()<plansza.get_height()-4)                   //testing gravity
                //piece.set_possition_x(piece.get_poss().get_x()+1);             //default gravity
        piece.draw(piece.get_rotation(), 'X', piece.get_current(), piece.get_poss());
        plansza.draw_self();
        move(22, 6);
        printw("Score: %d", score);
        refresh();
        moving(piece, plansza);
    }
}
void game::moving(tetromino &piece, board &matrix)
{
    int num = getchar();
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
            break;
        case 97:
            //printw("left\n");
            if(check_collisions(piece.get_current(), piece.get_rotation(), piece.get_poss().get_y()-1,piece.get_poss().get_x(), piece, matrix))
            piece.set_possition_y(piece.get_poss().get_y()-1);
            break;
        case 115:
            //printw("down\n");
            if(check_collisions(piece.get_current(), piece.get_rotation(), piece.get_poss().get_y(),piece.get_poss().get_x()+1, piece, matrix))
            piece.set_possition_x(piece.get_poss().get_x()+1); // moving piece down is working fine
            break;
        case 120:
            //printw("rotate\n");
            //piece.set_rotation(getchar());
            if(check_collisions(piece.get_current(), piece.get_rotation()+1, piece.get_poss().get_y(),piece.get_poss().get_x(), piece, matrix))
            piece.set_rotation(piece.get_rotation()+1);
            break;
        case 32:
            //printw("space\n");
            if(check_collisions(piece.get_current(), piece.get_rotation()+1, piece.get_poss().get_y(),piece.get_poss().get_x(), piece, matrix))
            piece.set_rotation(piece.get_rotation()+1);
            break;
        case 113:
            game_over();
            break;
        default:
            move(8,20);
            printw("wrong input");
    }

}

bool game::check_collisions(int currentTetromino, int currentRotation, int posY, int posX, tetromino &piece, board &matrix) {
// creating loops for checking each character in array
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++) {

            //if(piece.tetro[currentTetromino][piece.rotate(py, px, currentRotation)]!='.')

            if (piece.tetro[currentTetromino][piece.rotate(py, px, currentRotation)]!='.' && matrix.board_get((posY+py),(posX+px))!=0)
                return false;

        }

    return true;
}


//bool game::check_collisions(int currentTetromino, int currentRotation, int posY, int posX, tetromino &piece, board &matrix){
//    for (int px = 0; px < 4; px++)
//        for (int py = 0; py < 4; py++)
//        {
//            // Get index into piece
//            int pi = piece.rotate(py, px, currentRotation);
//
//            // Get index into field
//            //int fi[(posY + py) * matrix.get_width()][(posX + px)];//(posY + py) * matrix.get_width() + (posX + px);
//
//            // Check that test is in bounds. Note out of bounds does
//            // not necessarily mean a fail, as the long vertical piece
//            // can have cells that lie outside the boundary, so we'll
//            // just ignore them
//            if (posY + py >= 0 && posY + py < matrix.get_width())
//            {
//                if (posX + px >= 0 && posX + px < matrix.get_height())
//                {
//                    // In Bounds so do collision check
//                    //if (piece.tetro[currentTetromino][pi] != L'.' && matrix.board_get((posY + py) * matrix.get_width(),(posX + px))!= 0)
//                    if (piece.tetro[currentTetromino][pi]!='.' && (matrix.board_get(posX+px,(posY+py)*matrix.get_width())!= 0))
//                            return false; // fail on first hit
//                }
//            }
//        }
//    return true;
//}