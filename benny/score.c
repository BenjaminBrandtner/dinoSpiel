/*Author: Benjamin Brandtner
 * Scoreboard einlesen, anzeigen und neue Werte reinschreiben */

#include <stdio.h>
#include "split.h"
#include <stdlib.h> //für atoi()

struct scoreEintrag
{
	int punktzahl;
	char name[15];
};

void scoreboardAnzeigen(struct scoreEintrag scores[]);
void scoreboardEinlesen(struct scoreEintrag scores[]);
bool neuerHighscore(int punktzahl);
void scoreEintragen(int punktzahl);

int main (void)
{
	int punktzahl=1001; //startet bei 0, zu test zwecken ist sie größer
	struct scoreEintrag scores[11];

	//Spielloop hier, punktzahl wird hochgezählt
	
	scoreboardEinlesen(scores);
	scoreboardAnzeigen(scores);

	if(neuerhighscore(punktzahl))
	{
		scoreEintragen(punktzahl);
	}
	else
	{
		printf("Leider kein Highscore");
	}

	return 0;
}

void scoreboardEinlesen(struct scoreEintrag scores[])
{
	FILE *datei;
	char zeile[22];
	char punkteString[6];
	int i;
	int verschiebung;

	datei=fopen("scores.csv", "r");

	for(i=0;i<10;i++)
	{
		fgets(zeile,21,datei);
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
		printf("%i - %s\n", scores[i].punktzahl, scores[i].name);
	}
}

bool neuerHighscore(int punktzahl)
{
}
void scoreEintragen(int punktzahl)
{
	//Eingabe soll innerhalb der Highscoreliste erfolgen
}
