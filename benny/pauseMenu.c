/*Author: Benjamin Brandtner
 * pauseMenü ohne ncurses menu library */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

void zeigePause (void);

int main (void)
{
	int schritt=0;
	char eingabe;
	int geschwindigkeit=7; //ms verzögerung zwischen schritten
	int fehler;

	
	initscr();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

	while(1)
	{
		if((eingabe=getch())=='p')
		{
			zeigePause();
		}

		//zeichne debug infos
		mvprintw(0,0,"Schritt: %i", schritt++);
		mvprintw(0,13,"Letzte Taste: %i   ", eingabe);
		refresh();
		
		fehler=usleep(geschwindigkeit*10000);
	}	

	endwin();

	return 0;
}

void zeigePause (void)
{
	WINDOW *pauseMenu;

	int eingabe;
	while((eingabe=getch())!='q')
	{
		char menuPunkte[3][15];
		strcpy(menuPunkte[0],"Fortsetzen");
		strcpy(menuPunkte[1],"Startmenü");
		strcpy(menuPunkte[2],"Beenden");

		pauseMenu=newwin(5,20,20,10);
		mvwprintw(pauseMenu,1,1,menuPunkte[0]);
		mvwprintw(pauseMenu,2,1,menuPunkte[1]);
		mvwprintw(pauseMenu,3,1,menuPunkte[2]);
		wborder(pauseMenu, '|','|','-','-','#','#','#','#'); //l,r,t,b,tl,tr,bl,br


		wrefresh(pauseMenu);
	}
}


