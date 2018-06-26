/*Author: Benjamin Brandtner
 * Header mit Funktionen zum: Scoreboard einlesen, anzeigen, neue Werte reinschreiben, und speichern */

#include "split.h"

struct scoreEintrag
{
	int punktzahl;
	char name[15];
};

//Prototypen
void scoreboardEinlesen(struct scoreEintrag scores[]);
WINDOW * scoreboardAnzeigen(struct scoreEintrag scores[], bool permanent);
bool neuerHighscore(struct scoreEintrag scores[], int punktzahl);
void scoreEintragen(struct scoreEintrag scores[], int punktzahl);
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

WINDOW * scoreboardAnzeigen(struct scoreEintrag scores[], bool permanent)
{
	WINDOW *scoreboardFenster;
	int height=12;
	int width=27;
	int y=LINES/2-height/2;
	int x=COLS/2-width/2;
	int eingabe=0;
	int i;

	scoreboardFenster=newwin(height,width,y,x);
	wborder(scoreboardFenster, '|','|','-','-','#','#','#','#'); //l,r,t,b,tl,tr,bl,br
	keypad(scoreboardFenster,true);

	for(i=0;i<10;i++)
	{
		mvwprintw(scoreboardFenster,i+1,2,"%5i - %s", scores[i].punktzahl, scores[i].name);
	}

	if(permanent==TRUE)
	{
		return scoreboardFenster;
	}
	else
	{
		//Zeige Scoreboard an bis ESC oder Enter gedrückt wird
		while(eingabe!=KEY_ESC && eingabe!=KEY_ENTER)
		{
			eingabe=wgetch(scoreboardFenster);
			wrefresh(scoreboardFenster);
		}

		//Lösche Fenster
		wclear(scoreboardFenster);
		wrefresh(scoreboardFenster);
		delwin(scoreboardFenster);
	}
}

bool neuerHighscore(struct scoreEintrag scores[], int punktzahl)
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

void scoreEintragen(struct scoreEintrag scores[], int punktzahl)
{
	WINDOW *scoreboardFenster;
	int i=10;
	int eingabe=0;
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

	//Konsoleneigenschaften für Eingabe vorbereiten
	curs_set(1);
	echo();

	//Eingabe
	scoreboardFenster=scoreboardAnzeigen(scores, TRUE);
	mvwgetnstr(scoreboardFenster,i+1,10,scores[i].name, 15);

	//Konsoleneigenschaften zurücksetzen
	curs_set(0);
	noecho();

	//Zeige Scoreboard an bis ESC oder Enter gedrückt wird
	while(eingabe!=KEY_ESC && eingabe!=KEY_ENTER)
	{
		eingabe=wgetch(scoreboardFenster);
		wrefresh(scoreboardFenster);
	}

	//Lösche Fenster
	wclear(scoreboardFenster);
	wrefresh(scoreboardFenster);
	delwin(scoreboardFenster);
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
