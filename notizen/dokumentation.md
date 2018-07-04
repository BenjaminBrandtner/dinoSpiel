# Dokumentation für Dinospiel
Dokumentation für das C Projekt von Benjamin Brandtner und Philipp Hägerich

## Installation
- Klonen Sie das Repository oder laden Sie den Ordner Dinospiel herunter.
- Installieren Sie die ncurses Bibliothek über ihren Packagemanager, auf Ubunutu: `apt-get install libncurses5-dev`
- Im Ordner Dinospiel kompilieren Sie Dinospiel.c und linken dabei ncurses: `gcc Dinospiel.c -lncurses`
- Führen Sie die erstellte Datei aus: `./a.out`

## Benutzerhandbuch
Zu Beginn wird Ihnen das Hauptmenü gezeigt. Von hier aus können Sie das Spiel starten, die gespeicherten Highscores ansehen, die Hilfe aufrufen oder das Spiel beenden.

### Steuerung
#### In Menüs:
- Pfeiltasten hoch und runter zum Ändern der Auswahl
- Enter zum Auswählen des markierten Menüpunktes

#### Im Spiel:
- Pfeiltaste oben oder Leertaste zum Springen
- ESC zum Pausieren

### Spielablauf
Ein Meteorit wird bald in Dinoland einschlagen. Die Dinos müssen fliehen, aber der einzige Weg führt durch die __lange und gefährliche Kakteenwüste__.  
Helfen Sie dem Dino zu entkommen! Springen Sie über die Kakteen und __überleben Sie so lange wie möglich__. Je länger Sie überleben, desto mehr __Punkte__ erhalten Sie.  
Schaffen Sie es nicht, einem Kaktus auszuweichen, bedeutet das Game Over. Wenn Sie genug Punkte erreicht haben, erhalten Sie einen Platz in der __Highscoreliste!__ Geben Sie Ihren Namen oder einen coolen Nicknamen ein und drücken Sie Enter. 

## Datendokumentation
Die Texturen sind als Folgen von '#' und ' ' (Leerzeichen) gespeichert. Um das Einlesen zu erleichtern haben sie festgelegte Maßen (Dino, Kaktus: 18x21; Wolken: 5x28; Überschrift: 7x82). So sieht z.B. der Dino aus:
```
           ########  
          ##### #####
          ###########
          ###########
          ######     
          #########  
#       #######      
##    ############   
###  ##########  #   
###############      
###############      
 #############       
  ###########        
    ########         
     ###  ##         
     ##    #         
     #     #         
     ##    ##         
```
Die Texturen wurden in ihre eigenen Unterordner gespeichert:
```
texturen
║
╠ dino
║    ╠ dino1.txt
║    ╚ dino2.txt
║
╠ kaktus
║    ╠ kaktus1.txt
║    ╠ kaktus2.txt
║    ╚ kaktus3.txt
║
╠ wolken
║    ╠ wolken1.txt
║    ╠ wolken2.txt
║    ╚ wolken3.txt
║
╚ ueberschrift.txt

```
Diese Art der Speicherung erlaubt es uns, die Texturen im vorgegebenem Rahmen einfach zu Manipulieren.

## Testdokumentation
Nach mehrfachem Testen des Programmes haben wir folgende Probleme festgestellt:
- Kakteen werden nicht dort angezeigt, wo sie ihren Koordinaten nach sein sollten. Festgestellt durch Ausgabe von Debug-Informationen ('d' drücken während des Spieles). Daher geht man einfach durch Kakteen durch und kollidiert mit scheinbar unsichtbaren Kakteen.
- Speicherzugriffsfehler beim Beenden des Programmes (nicht immer, Grund unbekannt)
- Speicherzugrifsfehler nach einigen Sekunden im Spiel (Grund unbekannt)

## Funktion mit Inline-Kommentaren
zeigePause() aus pause.h:

```C
/*Author: Benjamin Brandtner
 * Erstellt und zeigt ein Pausemenü an, dass über dem Spielfeld liegt und das Spiel unterbricht. 
 * Mit den Pfeiltasten kann eine Auswahl getroffen, mit Enter ausgewählt werden. 
 * Mit ESC wird das Menü sofort geschlossen und das Spiel fortgesetzt. */

int zeigePause()
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
			return 1;
		break;
		case 2: //Menü
			return 2;
		break;
		case 3: //Beenden
			endwin();
			exit(0);
		break;
	}
}
```

## Methodendokumentation
Struktogramm für scoreEintragen():
