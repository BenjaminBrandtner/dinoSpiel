/*Author: Benjamin Brandtner
 * Scoreboard auslesen anzeigen und neue Werte reinschreiben */

#include <stdio.h>
#include <ncurses.h>

struct scoreEintrag
{
	int punkte;
	char name[15];
}

int main (void)
{
	scoreboardAnzeigen();

	scoreEintragen();

	return 0;
}

void scoreboardAnzeigen()
{
	struct scoreEintrag scoreEintrag[10];

	scoreboardEinlesen();

}

void scoreboardEinlesen()
{
}

