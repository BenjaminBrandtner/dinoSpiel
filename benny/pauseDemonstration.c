/*Author: Benjamin Brandtner
 * Demonstration der Pause Funktion */

#include <stdio.h>
#include <string.h> //für strlen in pause.h
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

	ESCDELAY=50; //ms die nach einem Druck auf Escape auf weitere Zeichen gewartet wird

	while(1)
	{
		if((eingabe=getch())==KEY_ESC)
		{
			zeigePause();
		}

		//zeichne debug infos
		mvprintw(0,0,"Schritt: %i", schritt++);
		mvprintw(0,15,"Eingabe: %i   ", eingabe);
		refresh();
		
		usleep(geschwindigkeit*10000);
	}	

	endwin();
	return 0;
}
