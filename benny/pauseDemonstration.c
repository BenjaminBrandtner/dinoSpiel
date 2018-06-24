/*Author: Benjamin Brandtner
 * Demonstration der Pause Funktion */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> //für exit() in pause.h
#include <ncurses.h>

#include "pause.h"

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

	ESCDELAY=0; //0ms wird nach einem Druck auf Escape auf weitere Zeichen gewartet

	while(1)
	{
		if((eingabe=getch())==KEY_ESC)
		{
			zeigePause(10);
		}

		//zeichne debug infos
		mvprintw(0,0,"Schritt: %i", schritt++);
		refresh();
		
		usleep(geschwindigkeit*10000);
	}	

	endwin();
	return 0;
}
