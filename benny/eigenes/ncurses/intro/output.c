/*Author: Benjamin Brandtner
 * output functions */

#include <stdio.h>
#include <ncurses.h>

int main (void)
{
	initscr();

	//Add single characters (with attribute macro)
	addch('l' | A_UNDERLINE);
	addch('d');
	
	//Move the cursor, then add single characters, long version
	move(5,5);
	addch('l' | A_UNDERLINE);
	addch('d');

	//Move the cursor, then add single characters, short version
	mvaddch(0,10,'l' | A_UNDERLINE);
	addch('d');

	//move commands are in the format (y,x)
	mvaddch(30,3,'t');

	//add strings
	addstr("hat's great.");
	mvaddstr(30,30,"don't you agree?");

	//printf-like functions
	printw(" We are Number %i!", 1);
	mvprintw(10,30,"This %s is %i", "shit", 1337);

	//attributes
	attron(A_BOLD);
	attron(A_REVERSE);
	mvprintw(20, 4,"Look at me!");
	attroff(A_BOLD | A_REVERSE);

	printw(" Don't look at me!");

	//colors
	start_color();
	init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	attron(A_BOLD);
	printw(" Praise the sun!");

	refresh();

	getch();
	endwin();


	return 0;
}
