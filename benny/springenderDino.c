/*Author: Benjamin Brandtner
 * dino der springt auf KEY_UP */

#include <stdio.h>

int main (void)
{
	int eingabe;
	int y; dy;
	int schritt;
	int sprungstart;
	int geschwindigkeit=60; //ms verzögerung zwischen schritten

	initscr();
	noecho();
	cbreak();

	mvprintw(15,0,"_______________________________________________");


	while(1)
	{
		mvprintw(0,0,"Step: %i", schritt++);





	endwin();
	return 0;
}
