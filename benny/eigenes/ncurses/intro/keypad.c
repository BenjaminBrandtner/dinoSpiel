/*Author: Benjamin Brandtner
 * Getting special keys an printing the return value to the user */

#include <stdio.h>
#include <ncurses.h>

int main (void)
{
	int pressed;

	initscr();
	keypad(stdscr, TRUE);
	noecho();

	printw("You can press every key on the keyboard and see what getch() returns. The values correspond to all the KEY_ constants defined in curses.h\n");
	printw("For example these are the values for KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT: %i, %i, %i, %i\n\n", KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT);

	while((pressed=getch())!='q')
	{
		printw("%i, ", pressed);
	}


	endwin();
	return 0;
}
