/*Author: Benjamin Brandtner
 * Ball in einem Fenster der hin und her springt und es dabei sehr hübsch füllt */

#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

void handleCollision(int *y, int *x, int *dx, int *dy, int *maxrow, int *maxcol);

int main (void)
{
	srand(time(NULL));
	WINDOW *win1;
	int y=0;
	int x=0;
	int prevx=0;
	int prevy=0;
	int dx=1;
	int dy=1;
	int maxrow=20;
	int maxcol=23;
	int speed=100; //delay in milliseconds between steps
	int step=0;

	initscr();
	start_color();
	init_pair(1,COLOR_RED,COLOR_BLACK);
	win1=newwin(maxrow,maxcol,8,10); //heigt, width, starty, startx
	box(win1,0,0); //wclear() clears this box


	maxrow--;
	maxcol--;
	
	while(true)
	{
		wclear(win1); //Uncomment theses for nonfilling (boring) bouncing
		box(win1,0,0); 
		wattrset(win1,COLOR_PAIR(1) | A_BOLD);
		mvwaddch(win1,y,x,'O');
		mvwchgat(win1, prevy, prevx, 1, NULL, 0, NULL);

		handleCollision(&y, &x, &dx, &dy, &maxrow, &maxcol);
		prevx=x;
		prevy=y;
		x=x+dx;
		y=y+dy;

		mvprintw(0,0,"Y: %i X: %i    \nStep: %i        ", x,y,step++);
		refresh();

		wmove(win1,0,0);
		wrefresh(win1);

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

