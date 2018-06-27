/*Autor: Philipp Hägerich 
 * Beinhaltet die Main Funktion die alle Sachen einließt
 * und in einem Loop zwischen verschiedenen Programmteilen springt. */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ncurses.h>

//Der von ncurses definierte Wert für Enter funktioniert nicht immer. Hier wird er auf ASCII 10 also '\n' gesetzt.
//Standardmäßig wird von ncurses kein Makro für den Escape Knopf angelegt, da vom Benutzen von Escape als Taste mit einer einzelnen Funktion abgeraten wird.
#undef KEY_ENTER
#define KEY_ENTER 10
#define KEY_ESC 27

#include "texturenEinlesen.h"
#include "texturenAusgabe.h"

#include "hauptmenu.h"
#include "pause.h"
#include "score.h"
#include "spiel.h"

int main(void)
{
	struct tex_wolken wolken[3];
	struct tex_rest dino[2];
	struct tex_rest kaktus[3];
	struct ueberschrift ueberschrift;
	struct scoreEintrag scores[11];

	int punktzahl = 0;
	int auswahl = 5;
	
	//Aus Dateien einlesen
	einlesenWolken(&wolken[0],"texturen/wolken/wolken1.txt");
	einlesenWolken(&wolken[1],"texturen/wolken/wolken2.txt");
	einlesenWolken(&wolken[2],"texturen/wolken/wolken3.txt");
	
	einlesenTexturen(&dino[0],"texturen/dino/dino1.txt");
	einlesenTexturen(&dino[1],"texturen/dino/dino2.txt");
	
	einlesenTexturen(&kaktus[0],"texturen/kaktus/kaktus1.txt");
	einlesenTexturen(&kaktus[1],"texturen/kaktus/kaktus2.txt");
	einlesenTexturen(&kaktus[2],"texturen/kaktus/kaktus3.txt");
	
	einlesenUeberschrift(&ueberschrift,"texturen/ueberschrift.txt");

	scoreboardEinlesen(scores);

	//ncurses aktivieren und anpassen
	initscr();
	cbreak();
	noecho();
	curs_set(0);
	nodelay(stdscr,true);
	keypad(stdscr,true);
	ESCDELAY = 50;

	while(auswahl != 6)
	{
		erase();
		switch(auswahl)
		{
			case 1:
				auswahl = spiel(dino,kaktus,wolken);
			break;
			case 2:
				//optionenAnzeigen();
				auswahl=5;
			break;
			case 3:
				scoreboardAnzeigen(scores, FALSE);
				auswahl = 5;
			break;
			case 4:
				if(neuerHighscore(scores, punktzahl))
				{
					printw("Neuer Highscore!");
					refresh();

					scoreEintragen(scores, punktzahl);

					scoreboardSpeichern(scores);
				}
				else
				{
					printw("Leider kein Highscore");
					refresh();
					sleep(1);
				}
				auswahl = 1;
			break;
			case 5:
				auswahl = zeigeHauptmenu();
			break;
		}
	}

	scoreboardSpeichern(scores);

	endwin();
	
	return 0;
}
