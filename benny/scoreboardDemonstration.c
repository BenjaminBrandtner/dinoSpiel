/*Author: Benjamin Brandtner
 * Dieses Programm dient zur Demonstration aller scoreboard Funktionen und ist ein grobes Konzept wie die Funktionen im Laufe des Programmes eingesetzt werden könnten. */

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h> //für sleep()
#include <stdlib.h> //für atoi() in score.h
#include <string.h> //for strcpy in score.h
#include "score.h"

int main (void)
{
	int punktzahl=4001; //Punktzahl des aktuellen Spiels, kann zu Testzwecken hier manuell eingegeben werden
	struct scoreEintrag scores[11]; 
	//Array von Strukturen des Types scoreEintrag wird angelegt als Variable mit dem Namen scores

	scoreboardEinlesen(scores);
	//scores beinhaltet jetzt alle 10 Einträge der Highscore Liste, und einen noch leeren Platz für einen neuen Eintrag

	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);

	scoreboardAnzeigen(scores);
	getch(); //Programm hält an bis Eingabe
	clear();

	/* Spielloop hier, punktzahl wird hochgezählt bis Game Over */

	if(neuerHighscore(punktzahl, scores))
	{
		printw("Neuer Highscore!");
		refresh();
		sleep(1);

		scoreEintragen(punktzahl, scores);
		sleep(1);

		scoreboardSpeichern(scores);
	}
	else
	{
		printw("Leider kein Highscore");
		sleep(1);
	}

	endwin();

	return 0;
}
