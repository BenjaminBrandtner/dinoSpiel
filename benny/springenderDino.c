/*Author: Benjamin Brandtner
 * dino der springt auf KEY_UP */

#include <stdio.h>
#include <ncurses.h>

void zeichneDino(int *y);

int main (void)
{
	int eingabe;
	int y=15; 
	int dy=0;
	int schritt;
	int sprungstart;
	int geschwindigkeit=20; //ms verzögerung zwischen schritten

	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

	mvprintw(15,0,"_______________________________________________");


	while(1)
	{
		mvprintw(0,0,"Step: %i", schritt++);
		if((eingabe=getch())==KEY_UP)
		{
			springe(
		}

		zeichneDino(&y);

		refresh();


		usleep(geschwindigkeit*10000);
	}



	endwin();
	return 0;
}

void zeichneDino(int *y)
{
	mvaddch(*y,3,' ');
	mvaddch((*y)+1,3,' ');

	mvaddch(*y,3,'#');
	mvaddch((*y)-1,3,'#');
}

