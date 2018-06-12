/*Author: Benjamin Brandtner
 * Init functions */

#include <stdio.h>
#include <ncurses.h>

int main (void)
{
	//Initializes terminal in curses mode. Initialzes the curses system and allocates memory for current window (called stdscr) and other data structures
	initscr();
	
	//raw()
	//cbreak()
	//Turn on non-canonical(non-line-buffered) mode. Every keypress is immeadiately available to the program.
	//In raw mode, control characters (like CTRL-C) are sent to the program without generating a signal. In cbreak mode they are interpreted by the terminal driver as usual.
	//There's also noraw() and nocbreak() which puts it back into 'cooked' (line-buffered) mode.
	//Mixing raw/noraw and cbreak/nocbreak calls is not recommended
	//It seems that after invoking initscr() the mode is already set to cbreak;

	raw();
	printw("You're in Raw Mode. Try pressing some Control Characters like CTRL-C or CTRL-S, CTRL-Q. Press n to move on.\n");
	while(getch()!='n');

	cbreak();
	printw("Now that you're in cbreak mode Control Characters should work again. Press n to move on\n");
	while(getch()!='n');

	//echo()
	//noecho()
	//Controls whether the character the user types are immeadiately printed back to the screen

	noecho();
	printw("Ha! Try typing now. Can't see, huh? Press n to move on.\n");
	while(getch()!='n');

	echo();
	printw("Okay, you can see what you type again. Try pressing the function keys or the arrow keys. Press n to move on.\n");
	while(getch()!='n');

	//Enable Arrow keys, F keys, etc
	keypad(stdscr, TRUE);

	printw("Alright, try again. Press q to quit\n");
	while(getch()!='q');

	endwin();
	return 0;
}
