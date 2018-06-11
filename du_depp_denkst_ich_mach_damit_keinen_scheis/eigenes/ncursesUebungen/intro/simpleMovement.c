/*Author: Benjamin Brandtner
 * Simple cursor movement */

#include <stdio.h>
#include <ncurses.h>

int main (void)
{
	int y,x;
	int maxrow,maxcol;
	int pressed;

	initscr();
	getmaxyx(stdscr,maxrow,maxcol);
	keypad(stdscr, TRUE);

	printw("Move the cursor around with the Arrow Keys and type anything. Exit with q.\nErmittelte Dimensionen: %i Zeilen, %i Spalten", maxrow,maxcol);
	move(maxrow/2,maxcol/2);
	getyx(stdscr,y,x);

	while((pressed=getch())!='q')
	{
		switch(pressed)
		{
			case KEY_UP:
				getyx(stdscr,y,x);
				move(--y,x);
				mvprintw(maxrow-1,maxcol-25,"Koordinaten: %i/%i", y,x);
				move(y,x);
			break;
			case KEY_DOWN:
				getyx(stdscr,y,x);
				move(++y,x);
				mvprintw(maxrow-1,maxcol-25,"Koordinaten: %i/%i", y,x);
				move(y,x);
			break;
			case KEY_LEFT:
				getyx(stdscr,y,x);
				move(y,--x);
				mvprintw(maxrow-1,maxcol-25,"Koordinaten: %i/%i", y,x);
				move(y,x);
			break;
			case KEY_RIGHT:
				getyx(stdscr,y,x);
				move(y,++x);
				mvprintw(maxrow-1,maxcol-25,"Koordinaten: %i/%i", y,x);
				move(y,x);
			break;
			default:
				getyx(stdscr,y,x);
				mvprintw(maxrow-1,maxcol-25,"Koordinaten: %02i/%02i", y,x);
				move(y,x);
			break;
		}
	}

	endwin();
	return 0;
}
