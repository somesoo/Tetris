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
void game::start_game() {
    srand((unsigned) time(NULL));
    board plansza;
    isOver = false;
    unsigned int thick = 100;
    tetromino piece(2,4, rand()%6,rand()%3);
    while(!is_over()){
        std::this_thread::sleep_for(std::chrono::milliseconds(thick));
        piece.set_possition_x(piece.get_poss().get_x()+1);      //default gravity
            if(piece.get_poss().get_x()>plansza.get_height()-4)     //testing gravity
                game_over();
        clear();
        piece.draw(piece.get_rotation(), 'X', piece.get_curr(), piece.get_poss());
        plansza.draw_self();

        //moving(piece);
//        move(21, 0);
//        printw("Score: %d", score);
        refresh();

    }
}
void game::moving(tetromino &piece)
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
            piece.set_possition_y(piece.get_poss().get_y()+1);
            break;
        case 97:
            //printw("left\n");
            piece.set_possition_y(piece.get_poss().get_y()-1);
            break;
        case 115:
            //printw("down\n");
            piece.set_possition_x(piece.get_poss().get_x()+1); // moving piece down is working fine
            break;
        case 120:
            //printw("rotate\n");
            //piece.set_rotation(getchar());
            piece.set_rotation(piece.get_rotation()+1);
            break;
        case 32:
            //printw("space\n");
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

bool game::check_collisions(int currentTetromino, int currentRotation, int posY, int posX, tetromino &piece, board &matrix){
    for (int px = 0; px < 4; px++)
        for (int py = 0; py < 4; py++)
        {
            // Get index into piece
            int pi = piece.rotate(py, px, currentRotation);

            // Get index into field
//            point fi = {(posY + py) * matrix.get_width(), (posX + px)};

            // Check that test is in bounds. Note out of bounds does
            // not necessarily mean a fail, as the long vertical piece
            // can have cells that lie outside the boundary, so we'll
            // just ignore them
            if (posX + px >= 0 && posX + px < matrix.get_width())
            {
                if (posY + py >= 0 && posY + py < matrix.get_height())
                {
                    // In Bounds so do collision check
                    if (piece.tetro[currentTetromino][pi] != L'.' && matrix.board_get((posY + py) * matrix.get_width(),(posX + px))!= 0)
                        return false; // fail on first hit
                }
            }
        }
    return true;
}