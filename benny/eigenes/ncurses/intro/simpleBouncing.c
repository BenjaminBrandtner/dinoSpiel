/*Author: Benjamin Brandtner
 * Simpler Ball der hin und her springt */

#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

void handleCollision(int *y, int *x, int *dx, int *dy, int *maxrow, int *maxcol);

int main (void)
{
	srand(time(NULL));
	int y=0;
	int x=0;
	int dx=1;
	int dy=1;
	int maxrow,maxcol;
	int speed=80; //delay in milliseconds between steps

	initscr();
	getmaxyx(stdscr,maxrow,maxcol);
	maxrow--;
	maxcol--;
	
	while(true)
	{
		clear();
		mvaddch(y,x,'O');
		handleCollision(&y, &x, &dx, &dy, &maxrow, &maxcol);
		x=x+dx;
		y=y+dy;
		move(0,0);
		//printw("x-Speed: %i, x: %i", dx, x);
		refresh();
		usleep(speed*1000);
	}

	return 0;
}

void handleCollision(int *y, int *x, int *dx, int *dy, int *maxrow, int *maxcol)
{
	if(*x+*dx<0 || *x+*dx>*maxcol)
	{
		*dx=*dx*-1;
	}
	if(*y+*dy<0 || *y+*dy>*maxrow)
	{
		*dy=*dy*-1;
	}

}

