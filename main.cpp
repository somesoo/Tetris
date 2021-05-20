#include<iostream>
#include<ncurses.h>

int main()
{
    initscr(); //start
    keypad( stdscr, TRUE ); //1
    printw( "Znak w grubej czcionce:\n\n" ); //tekst
    noecho(); // 2
    int litera = getch(); //pobieranie znaku do zmiennej
    printw( "Wcisniety znak to:" ); //wyswietlanie tekstu
    attron( A_BOLD ); //3
    printw( "%d", litera ); //4
    getch(); //czekanie na naciśnięcie
    endwin(); //kończenie

    return 0;
}