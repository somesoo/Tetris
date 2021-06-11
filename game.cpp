#include <ncurses.h>
#include <time.h>
#include <iostream>
#include <thread>
#include "game.h"
#include "tetromino.h"


game::game() {
    board plansza;
    start_game();
    while(is_over()){
    int mv = get_move();
        move(mv);
    refresh();}

}
int choose_random(int & current)
{
    srand((unsigned) time(NULL));
    int newpiece=0;
    newpiece=rand()%7+1;
    while(newpiece==current)
        newpiece=rand()%7+1;
    printw("%d", newpiece);
    current=newpiece;
    return newpiece;
}
void game::new_falling_tetromino(int current_tetromino){
    switch (choose_random(current_tetromino)) {
        case 1:{
            I_tetromino new_piece;
            break;}
        case 2:{
            J_tetromino new_piece;
            break;
        }
        case 3:{
            L_tetromino new_piece;
            break;
        }
        case 4:{
            O_tetromino new_piece;
            break;
        }
        case 5:{
            S_tetromino new_piece;
            break;
        }
        case 6:{
            Z_tetromino new_piece;
            break;
        }
        case 7:{
            T_tetromino new_piece;
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
