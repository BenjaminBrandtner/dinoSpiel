/*Author: Benjamin Brandtner
 * dino der springt auf KEY_UP */

#include <stdio.h>
#include <ncurses.h>

void zeichneDino(int *dinoY);
void verarbeiteSprung(int *dinoY, int *timer);
void zeichneHindernis(int *hindernisX);

int main (void)
{
	int eingabe;
	int dinoY=15; //Der Boden des Spielfelds und die Wurzel des Dinos sind in diesem Beispiel bei 15
	int hindernisX; //einfaches einzelnes hindernis
	int schritt=0;
	int sprungtimer=0;
	int geschwindigkeit=3; //ms verzögerung zwischen schritten
	int fehler;

	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

	hindernisX=COLS; //hindernis beginnt am rechten Rand des fensters

	while(1)
	{
		//eingabe
		if((eingabe=getch())==KEY_UP && sprungtimer<0)
		{
			sprungtimer=10;
		}

		//rechne
		if(sprungtimer>0)
		{
			verarbeiteSprung(&dinoY, &sprungtimer);
		}
		sprungtimer--;

		if(hindernisX<0)
		{
			hindernisX=COLS;
		}
		else
		{	
			hindernisX--;
		}

		//zeichne
		//Debug-Infos
		mvprintw(0,0,"Schritt: %i", schritt++);
		mvprintw(0,13,"Letzte Taste: %i   ", eingabe);
		mvprintw(0,32,"Sprungtimer: %i  ", sprungtimer);
		//Spiel
		zeichneDino(&dinoY);
		zeichneHindernis(&hindernisX);
		mvchgat(15,0,-1, A_UNDERLINE, 0, NULL);
		move(0,0); //Bewege den Cursor aus dem Weg
		refresh();

		//Delay
		while(eingabe!=-1) //Leere den Input Buffer von allen Zeichen
		{
			eingabe=getch();
		}
		fehler=usleep(geschwindigkeit*10000);
	}

	endwin();
	return 0;
}

void verarbeiteSprung(int *dinoY, int *timer)
{
	if(*timer==10)
	{
		(*dinoY)--;
	}
	if(*timer==9)
	{
		(*dinoY)--;
	}
	if(*timer==8)
	{
		(*dinoY)--;
	}
	if(*timer==5)
	{
		(*dinoY)++;
	}
	if(*timer==2)
	{
		(*dinoY)++;
	}
	if(*timer==1)
	{
		(*dinoY)++;
	}

}

void zeichneDino(int *dinoY)
{
	mvaddch(*dinoY,3,' ');
	mvaddch((*dinoY)+1,3,' ');
	mvaddch((*dinoY)-2,3,' ');

	mvaddch(*dinoY,3,'#');
	mvaddch((*dinoY)-1,3,'#');
}

void zeichneHindernis(int *hindernisX)
{
	mvaddch(15,*hindernisX,'X');
	mvaddch(15,*hindernisX+1,' ');
}
