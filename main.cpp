#include<ncurses.h>
#include "game.h"



int main()
{
    initscr();
    noecho();
    game tetris;
    tetris.start_game();
    getch();
    endwin();
    return 0;
}