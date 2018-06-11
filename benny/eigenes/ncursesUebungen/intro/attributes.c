/*Author: Benjamin Brandtner
 * Attributes */

#include <stdio.h>
#include <ncurses.h>

int main (void)
{
	initscr();
	start_color();
	init_pair(1,COLOR_BLACK, COLOR_YELLOW);
	init_pair(2,COLOR_YELLOW, COLOR_BLACK);
	init_pair(3,COLOR_MAGENTA, COLOR_BLACK);

	attron(A_UNDERLINE);
	mvprintw(12,12,"Hey there!");

	attrset(A_NORMAL);
	mvprintw(13,12,"Have you found Cheezus?");

	attrset(COLOR_PAIR(3));
	mvprintw(14,12,"He's a tasty man!");


	while(1)
	{
		mvchgat(13,12,25,NULL, 1,NULL );
		refresh();
		usleep(100*10000);
		mvchgat(13,12,25,A_BOLD, 2,NULL );
		refresh();
		usleep(100*10000);
	}

	
	getch();
	endwin();
	return 0;
}

/* Notes
 *
 * COLOR_YELLOW is brown, add A_BOLD for yellow.
 */
