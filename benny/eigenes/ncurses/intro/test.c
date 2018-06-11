/*Author: Benjamin Brandtner
 * Testing accessing _win_st */

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

int main (void)
{

	initscr();
	attron(A_BOLD);
	printw("Flags: %i", stdscr->_attrs);
	refresh();



	sleep(2);
	endwin();
	return 0;
}
