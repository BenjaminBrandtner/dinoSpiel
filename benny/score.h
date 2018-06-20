/*Author: Benjamin Brandtner
 * Header mit Funktionen zum: Scoreboard einlesen, anzeigen, neue Werte reinschreiben, und speichern */

#include "split.h"

struct scoreEintrag
{
	int punktzahl;
	char name[15];
};

//Globale Konstante
const int scoreboardY = 9;

//Prototypen
void scoreboardAnzeigen(struct scoreEintrag scores[]);
void scoreboardEinlesen(struct scoreEintrag scores[]);
bool neuerHighscore(int punktzahl, struct scoreEintrag scores[]);
void scoreEintragen(int punktzahl, struct scoreEintrag scores[]);
void scoreboardSpeichern(struct scoreEintrag scores[]);

void scoreboardEinlesen(struct scoreEintrag scores[])
{
	FILE *datei;
	char zeile[23]; //5 Ziffern + ';' + 15 Buchstaben + '\n' + '\0'
	char punkteString[6]; //5 Ziffern + '\0'
	int i;
	int verschiebung;

	datei=fopen("scores.csv", "r");

	for(i=0;i<10;i++)
	{
		fgets(zeile,22,datei);
		verschiebung=split(zeile, punkteString, ';');
		scores[i].punktzahl=atoi(punkteString);
		split(zeile+verschiebung, (scores[i].name), ';');
	}
	fclose(datei);
}

void scoreboardAnzeigen(struct scoreEintrag scores[])
{
	int i;

	clear();

	for(i=0;i<10;i++)
	{
		//Ein Eintrag ist maximal 23 Zeichen lang, die Hälfte davon ist ~11. Wenn jede Zeile an COLS/2-11 beginnt, führt das zur mittigen Platzierung
		mvprintw(scoreboardY+i,COLS/2-11,"%5i - %s\n", scores[i].punktzahl, scores[i].name);
	}

	refresh();
}

bool neuerHighscore(int punktzahl, struct scoreEintrag scores[])
{
	if(punktzahl>=scores[9].punktzahl)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void scoreEintragen(int punktzahl, struct scoreEintrag scores[])
{
	int i=10;
	struct scoreEintrag temp;

	//Trage die Punktzahl des Spielers auf 11ter Position des scores-arrays ein. Diese Position wird nie angezeigt oder gespeichert.
	scores[10].punktzahl=punktzahl;
	strcpy(scores[10].name,"");

	//sortiere: Verschiebe den neuen Eintrag so lange nach oben bis der nächste Eintrag größer ist
	while(i>0 && scores[i].punktzahl>=scores[i-1].punktzahl)
	{
		temp=scores[i-1];
		scores[i-1]=scores[i];
		scores[i]=temp;

		i--;
	}

	//Konsole für Eingabe vorbereiten
	curs_set(1);
	echo();
	nodelay(stdscr, FALSE);
	//TO-DO: nodelay des stdscr müsste garnicht berührt werden, wenn das Scoreboard in einem extra Fenster erstellt werden würde

	//Eingabe
	scoreboardAnzeigen(scores);
	mvgetstr(scoreboardY+i,COLS/2-11+8,scores[i].name);
	//TO-DO: eingabe auf 15 zeichen beschränken

	//Konsoleneigenschaften zurücksetzen
	curs_set(0);
	noecho();
	/* nodelay(stdscr, TRUE); */
}

void scoreboardSpeichern(struct scoreEintrag scores[])
{
	FILE *datei;
	int i;

	datei=fopen("scores.csv", "w+");
	for(i=0;i<10;i++)
	{
		fprintf(datei, "%i;%s\n", scores[i].punktzahl, scores[i].name);
	}
	fclose(datei);
}
