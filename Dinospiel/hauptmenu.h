/*Author: Benjamin Brandtner
 * Funktion für das Hauptmenu */
//Prototyp
int zeigeHauptmenu();

//Präprozessor-Anweisungen
//Der von ncurses definierte Wert für Enter funktioniert nicht immer. Hier wird er auf ASCII 10 also '\n' gesetzt.
#undef KEY_ENTER
#define KEY_ENTER 10

int zeigeHauptmenu()
{
	WINDOW *hauptmenu;
	int height=6;
	int width=51;
	int y=LINES/2-height/2; //mittig
	int x=COLS/2-width/2; //mittig

	char menuPunkte[4][21]={"Spielen","Highscores anzeigen","Hilfe","Beenden"}; 

	int eingabe=0;
	int auswahl=1;
	int auswahlVorher;

	hauptmenu=newwin(height,width,y,x);
	
	//Eigenschaften und Rahmen wird festgelegt
	keypad(hauptmenu, TRUE);
	wborder(hauptmenu, '|','|','-','-','#','#','#','#'); //l,r,t,b,tl,tr,bl,br

	//Menüpunkte werden in der Mitte platziert
	mvwprintw(hauptmenu,1,((width-strlen(menuPunkte[0]))/2),menuPunkte[0]);
	mvwprintw(hauptmenu,2,((width-strlen(menuPunkte[1]))/2),menuPunkte[1]);
	mvwprintw(hauptmenu,3,((width-strlen(menuPunkte[2]))/2),menuPunkte[2]);
	mvwprintw(hauptmenu,4,((width-strlen(menuPunkte[3]))/2),menuPunkte[3]);

	//Der erste Menüpunkt wird ausgewählt
	mvwchgat(hauptmenu, auswahl, 1, width-2, A_REVERSE, 0, NULL);

	//Fenster wird gezeichnet
	wrefresh(hauptmenu);

	while(eingabe!=KEY_ENTER)
	{
		auswahlVorher=auswahl;

		eingabe=wgetch(hauptmenu);

		//Durch die Pfeiltasten wird der Wert von auswahl verändert (zwischen 1 und 3)
		switch(eingabe)
		{
			case KEY_UP:
				if(auswahl==1)
				{
					auswahl=4;
				}
				else
				{
					auswahl--;
				}
			break;
			case KEY_DOWN:
				if(auswahl==4)
				{
					auswahl=1;
				}
				else
				{
					auswahl++;
				}
			break;
		}

		//Die Zeile die in auswahl steht wird auf reverse geschalten, die vorherige auf normal
		mvwchgat(hauptmenu, auswahlVorher, 1, width-2, A_NORMAL, 0, NULL);
		mvwchgat(hauptmenu, auswahl, 1, width-2, A_REVERSE, 0, NULL);

		wrefresh(hauptmenu);
	}//end while

	//Lösche das Hauptmenu
	wclear(hauptmenu);
	wrefresh(hauptmenu);
	delwin(hauptmenu);

	//Entscheide aufgrund der Auswahl, wie es weitergeht
	switch(auswahl)
	{
		case 1: //Spielen
			return 1;
		break;
		case 2: //Scoreboard
			return 3;
		break;
		case 3: //Hilfe
			return 2;
		break;
		case 4: //Beenden
			return 6;
		break;
	}

}

void zeigeHilfe()
{
	WINDOW *hilfe;
	int height=20;
	int width=100;
	int y=LINES/2-height/2; //mittig
	int x=COLS/2-width/2; //mittig
	int eingabe=0;

	hilfe=newwin(height,width,y,x);
	keypad(hilfe,TRUE);

		wprintw(hilfe,"Ein Meteorit wird bald in Dinoland einschlagen. Die Dinos müssen fliehen, aber der einzige Weg führt durch die lange und gefährliche Kakteenwüste.\n"  
	"Helfen Sie dem Dino zu entkommen! Springen Sie über die Kakteen und überleben Sie so lange wie möglich. Je länger Sie überleben, desto mehr Punkte erhalten Sie.\n"
	"Schaffen Sie es nicht, einem Kaktus auszuweichen, bedeutet das Game Over. Wenn Sie genug Punkte erreicht haben, erhalten Sie einen Platz in der Highscoreliste! Geben Sie Ihren Namen oder einen coolen Nicknamen ein und drücken Sie Enter.\n\n");
		wprintw(hilfe,"Steuerung:\n\nIn Menüs:\n- Pfeiltasten hoch und runter zum Verändern der Auswahl\n- Enter zum Auswählen des markierten Menüpunktes\n\nIm Spiel:\n- Pfeiltaste oben oder Leertaste zum Springen\n- ESC zum Pausieren");

	wrefresh(hilfe);

	while(eingabe!=KEY_ENTER && eingabe!=KEY_ESC)
	{
		eingabe=wgetch(hilfe);
	}

	wclear(hilfe);
	wrefresh(hilfe);
	delwin(hilfe);
}
