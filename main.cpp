#include <ncurses.h>
#include "game.h"

int main()
{
    initscr();
    cbreak();
    noecho();
    game tetris;
    tetris.start_game();
    getchar();
    endwin();
    return 0;
}