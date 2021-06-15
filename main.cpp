#include <ncurses.h>
#include "game.h"

int main()
{
    initscr();
    cbreak();
    noecho();
    Game tetris;
    tetris.start_game();
    getchar();
    endwin();
    return 0;
}
//  Wlasnie zdałem u stawskiej i pytała o:
//- czy są wszystkie konstruktory kopiujące
//- operatory przypisania
//      - czy jest dziedziczenie i polimorfizm
//      - jak zrobiliśmy ten polimorfizm
//      - funkcja zaprzyjaźnioną lub o klasę
//- składniki statyczne
//- ogolnie patrzyła ile mam plików tzn (u mnie 5 różnych klas)
//- odpalasz program na koniec szybko wpisujesz co tam leci i tyle ona średnio chyba patrzyła xD
//- głównie patrzy na ocenę z kartkówki
//- polecam robić dużo komentarzy do projektu wtedy mówi że ładnie