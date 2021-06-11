#include<ncurses.h>
#include "game.h"



int main()
{
    initscr();
    game tetris;
    noecho();
    tetris.start_game();
    getch();
    endwin();
    return 0;
}