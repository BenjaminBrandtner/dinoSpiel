/*Author: Benjamin Brandtner
 * Erstellt und zeigt ein Pausemenü an, dass über dem Spielfeld liegt und das Spiel unterbricht. 
 * Mit den Pfeiltasten kann eine Auswahl getroffen, mit Enter ausgewählt werden. 
 * Mit ESC wird das Menü sofort geschlossen und das Spiel fortgesetzt. */

//Prototyp
void zeigePause();

//Präprozessor-Anweisungen
//Der von ncurses definierte Wert für Enter funktioniert nicht immer. Hier wird er auf ASCII 10 also '\n' gesetzt.
//Standardmäßig wird von ncurses kein Makro für den Escape Knopf angelegt, da vom Benutzen des Escape Keys als Taste mit einer einzelnen Funktion abgeraten wird.
#undef KEY_ENTER
#define KEY_ENTER 10
#define KEY_ESC 27

void zeigePause()
{
	WINDOW *pausemenu;
	int height=5; //Drei Menüpunkte, 2 Zeilen für Rahmen
	int width=51;
	int y=LINES/2-height/2; //mittig
	int x=COLS/2-width/2; //mittig

	char menuPunkte[3][15]={"Fortsetzen","Menu","Beenden"}; 
	//Vorsicht: Umlaute in den menüPunkten führen beim Zeichnen des Rahmens und ändern der Eigenschaften teilweise dazu, dass ein Zeichen zu wenig gezeichnet wird

	int eingabe=0;
	int auswahl=1;
	int auswahlVorher;

	pausemenu=newwin(height,width,y,x);
	
	//Eigenschaften und Rahmen wird festgelegt
	keypad(pausemenu, TRUE);
	wborder(pausemenu, '|','|','-','-','#','#','#','#'); //l,r,t,b,tl,tr,bl,br

	//Menüpunkte werden in der Mitte platziert
	mvwprintw(pausemenu,1,((width-strlen(menuPunkte[0]))/2),menuPunkte[0]);
	mvwprintw(pausemenu,2,((width-strlen(menuPunkte[1]))/2),menuPunkte[1]);
	mvwprintw(pausemenu,3,((width-strlen(menuPunkte[2]))/2)-1,menuPunkte[2]);

	//Der erste Menüpunkt wird ausgewählt
	mvwchgat(pausemenu, auswahl, 1, width-2, A_REVERSE, 0, NULL);

	//Fenster wird gezeichnet
	wrefresh(pausemenu);

	while(eingabe!=KEY_ENTER && eingabe!=KEY_ESC)
	{
		auswahlVorher=auswahl;

		eingabe=wgetch(pausemenu);

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
		mvwchgat(pausemenu, auswahlVorher, 1, width-2, A_NORMAL, 0, NULL);
		mvwchgat(pausemenu, auswahl, 1, width-2, A_REVERSE, 0, NULL);

		refresh();

		wrefresh(pausemenu);
	}//end while

	//Lösche das Pausemenü
	wclear(pausemenu);
	wrefresh(pausemenu);
	delwin(pausemenu);

	//Entscheide aufgrund der Auswahl, wie es weitergeht
	switch(auswahl)
	{
		case 1: //Fortsetzen
			//Nichts tun
		break;
		case 2: //Menü
			//titelmenuAnzeigen();
		break;
		case 3: //Beenden
			endwin();
			exit(0);
		break;
	}
}
