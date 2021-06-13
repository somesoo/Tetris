#include <ncurses.h>
#include <time.h>
#include <iostream>
#include <thread>
#include "game.h"
#include "tetromino.h"


game::game() {
    board plansza;
}

void game::start_game() {
    isOver = false;
    unsigned int thick = 500;
    while(!is_over()){
        std::this_thread::sleep_for(std::chrono::milliseconds(thick));
        new_falling_tetromino();
//    int mv = get_move();
//        move(mv);
        refresh();
    }
}
int choose_random()
{
    srand((unsigned) time(NULL));
    int newpiece=rand()%7+1;
    //printw("%d", newpiece);
    return newpiece;
}
void game::new_falling_tetromino(){
    switch (choose_random()) {
    //switch (4) {
            case 1:{
            I_tetromino new_pieceI;
            new_pieceI.draw(0, 'I');
            break;}
        case 2:{
            J_tetromino new_pieceJ;
            new_pieceJ.draw(0, 'J');
            break;
        }
        case 3:{
            L_tetromino new_pieceL;
            new_pieceL.draw(0, 'L');
            break;
        }
        case 4:{
            O_tetromino new_pieceO;
            new_pieceO.draw(0, 'O');
            break;
        }
        case 5:{
            S_tetromino new_pieceS;
            new_pieceS.draw(0, 'S');
            break;
        }
        case 6:{
            Z_tetromino new_pieceZ;
            new_pieceZ.draw(0, 'Z');
            break;
        }
        case 7:{
            T_tetromino new_pieceT;
            new_pieceT.draw(0, 'T');
            break;
        }
    }

}

int game::get_move()
{
    int key = getchar();
    return key;
}

void game::move(int num)
{
//  right   279167 // 100
//  left    279168 // 97
//  down    279166 // 115
//  rotate X 120
//  space   32
    switch (num) {
        case 100:
            printw("right\n");
            break;
        case 97:
            printw("left\n");
            break;
        case 115:
            printw("down\n");
            break;
        case 120:
            printw("rotate\n");
            break;
        case 32:
            printw("space\n");
            break;
        case 113:
            game_over();
            break;
        default:
            printw("wrong input");
    }

}
