/*Author: Benjamin Brandtner
 * Erstellt und zeigt ein Pausemenü an, dass über dem Spielfeld liegt und das Spiel unterbricht. 
 * Mit den Pfeiltasten kann eine Auswahl getroffen, mit Enter ausgewählt werden. 
 * Mit ESC wird das Menü sofort geschlossen und das Spiel fortgesetzt. */

//Prototyp
void zeigePause (int pausemenuY);

//Präporzessor Anweisungen
//Der von ncurses definierte Wert für Enter funktioniert nicht immer. Hier wird er auf ASCII 10 also '\n' gesetzt.
//Standardmäßig wird von ncurses kein Makro für den Escape Knopf angelegt, da vom Benutzen des Escape Keys als Taste mit einer einzelnen Funktion abgeraten wird.
#undef KEY_ENTER
#define KEY_ENTER 10
#define KEY_ESC 27

void zeigePause (int pausemenuY)
{
	WINDOW *pauseMenu;
	int height=5;
	int width=51;
	char menuPunkte[3][15]={"Fortsetzen","Menu","Beenden"}; 
	//Vorsicht: Umlaute in den menüPunkten führen beim Zeichnen des Rahmens und ändern der Eigenschaften teilweise dazu, dass ein Zeichen zu wenig gezeichnet wird

	int eingabe=0;
	int auswahl=1;
	int auswahlVorher;

	//Erstelle Pause Fenster, x == COLS/2-25 für mittige Platzierung
	pauseMenu=newwin(height,width,pausemenuY,COLS/2-25); //h,w,y,x
	
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
