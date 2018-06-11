/*Author: Benjamin Brandtner
 * Windows */

#include <stdio.h>
#include <ncurses.h>

int main (void)
{
	WINDOW *win1;

	initscr();
	//Variables LINES and COLS are initialized to the screen size after this
	refresh();
	

	win1=newwin(8,12,20,5); //heigt, width, starty, startx
	box(win1,0,0); //2nd and 3rd argument: characters for vertical and horizontal lines, 0 = default
	//wborder() to finetune the border symbols.
	//Takes 8 arguments. 1: the window on which to operate
	//2-8: l,r,t,b,tl,tr,bl,br
	wprintw(win1,"I'm a cool window");
	wrefresh(win1);
	delwin(win1); //Deallocates the memory of the window structure


	getch();
	endwin();
	return 0;
}
