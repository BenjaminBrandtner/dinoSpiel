/*Author: Benjamin Brandtner
 * pauseMenü ohne ncurses menu library */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h> //für exit()
#include <ncurses.h>

//Der von ncurses definierte Wert für Enter funktioniert nicht immer. Hier wird er auf ASCII 10 also '\n' gesetzt.
//Außerdem wird standardmäßig kein Makro für den Escape Knopf angelegt, da ncurses vom Benutzen des Escape Keys als Taste mit einer einzelnen Funktion abrät. 
#undef KEY_ENTER
#define KEY_ENTER 10
#define KEY_ESC 27

void zeigePause (void);

int main (void)
{
	int schritt=0;
	int eingabe;
	int geschwindigkeit=19; //ms verzögerung zwischen schritten
	
	initscr();
	cbreak();
	noecho();
	curs_set(0); //Set cursor invisible
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

	ESCDELAY=0; //0ms wird nach einem Druck auf Escape auf weitere Zeichen gewartet

	while(1)
	{
		if((eingabe=getch())==KEY_ESC)
		{
			zeigePause();
		}

		//zeichne debug infos
		mvprintw(0,0,"Schritt: %i", schritt++);
		refresh();
		
		usleep(geschwindigkeit*10000);
	}	

	endwin();
	return 0;
}

void zeigePause (void)
{
	WINDOW *pauseMenu;
	int height=5;
	int width=51;
	char menuPunkte[3][15]={"Fortsetzen","Menu","Beenden"}; 
	//Umlaute in den menüPunkten führen beim Zeichnen des Rahmens und ändern der Eigenschaften teilweise dazu, dass ein Zeichen zu wenig gezeichnet wird

	int eingabe=0;
	int auswahl=1;
	int auswahlVorher;

	//Erstelle Pause Fenster
	pauseMenu=newwin(height,width,20,10); //h,w,y,x
	
	//Eigenschaften und Rahmen wird festgelegt
	keypad(pauseMenu, TRUE);
	wborder(pauseMenu, '|','|','-','-','#','#','#','#'); //l,r,t,b,tl,tr,bl,br

	//Menüpunkte werden in der Mitte platziert
	mvwprintw(pauseMenu,1,((width-strlen(menuPunkte[0]))/2),menuPunkte[0]);
	mvwprintw(pauseMenu,2,((width-strlen(menuPunkte[1]))/2),menuPunkte[1]);
	mvwprintw(pauseMenu,3,((width-strlen(menuPunkte[2]))/2)-1,menuPunkte[2]);

	//Der erste Menüpunkt wird ausgewählt
	mvwchgat(pauseMenu, auswahl, 1, width-2, A_REVERSE, 0, NULL);

	//Fenster wird gezeichnet
	wrefresh(pauseMenu);

	while(eingabe!=KEY_ENTER && eingabe!=KEY_ESC)
	{
		auswahlVorher=auswahl;

		eingabe=wgetch(pauseMenu);

		//Durch die Pfeiltasten wird der Wert von auswahl verändert (zwischen 1 und 3)
		switch(eingabe)
		{
			case KEY_UP:
				if(auswahl==1)
				{
					auswahl=3;
				}
				else
				{
					auswahl--;
				}
			break;
			case KEY_DOWN:
				if(auswahl==3)
				{
					auswahl=1;
				}
				else
				{
					auswahl++;
				}
			break;
			case KEY_ESC:
				auswahl=1;
			break;
		}

		//Die Zeile die in auswahl steht wird auf reverse geschalten, die vorherige auf normal
		mvwchgat(pauseMenu, auswahlVorher, 1, width-2, A_NORMAL, 0, NULL);
		mvwchgat(pauseMenu, auswahl, 1, width-2, A_REVERSE, 0, NULL);

		wrefresh(pauseMenu);
	}

	wclear(pauseMenu);
	wrefresh(pauseMenu);
	delwin(pauseMenu);

	switch(auswahl)
	{
		case 1: //Fortsetzen
		break;
		case 2: //Menü
			//Mal schauen, wie wir das ohne ein Go-to lösen..
		break;
		case 3: //Beenden
			endwin();
			exit(0);
		break;
	}
}
