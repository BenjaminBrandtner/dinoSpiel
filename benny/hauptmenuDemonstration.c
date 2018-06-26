/*Author: Benjamin Brandtner
 * Demonstration der Pause Funktion */

#include <stdio.h>
#include <string.h> //für strlen in pause.h
#include <unistd.h>
#include <stdlib.h> //für exit() in pause.h
#include <ncurses.h>

#include "score.h"
#include "hauptmenu.h"

int main (void)
{
	int schritt=0;
	int eingabe;
	int geschwindigkeit=19; //ms verzögerung zwischen schritten
	
	initscr();
	cbreak();
	noecho();
	curs_set(0); //Set cursor invisible
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

	while(1)
	{

		//zeichne debug infos
		mvprintw(0,0,"Schritt: %i", schritt++);
		mvprintw(0,15,"Eingabe: %i   ", eingabe);
		refresh();
		
		zeigeHauptmenu();

		usleep(geschwindigkeit*10000);
	}	

	endwin();
	return 0;
}
