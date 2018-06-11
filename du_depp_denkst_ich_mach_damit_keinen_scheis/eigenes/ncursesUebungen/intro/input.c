/*Author: Benjamin Brandtner
 * Input Functions */

#include <stdio.h>
#include <ncurses.h>

int main (void)
{
	char c1;
	char c2;
	int num1;
	int num2;
	char str[80];

	initscr();

	printw("In the following order, please input:\n- A single character, without pressing enter\n- Another one\n- Some text, confirm with Enter\n- A number, confirm with Enter\n- Another number.\nStart now: ");

	c1=getch(); //get a single character
	c2=mvgetch(9,15); //get a single character from anywhere on the screen
	mvgetstr(13,13,str); //Continously performs getch() until \r \n or EOF

	scanw("%i", &num1); //Like scanf, works by calling getstr and scanning the result
	mvscanw(15,15,"%i", &num2); //Can take input from anywhere on the screen

	printw("Well done! You entered %c, %c, %s, %i, %i", c1,c2,str,num1,num2);

	getch();
	endwin();
	return 0;
}
