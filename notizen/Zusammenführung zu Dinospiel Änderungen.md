# Auflistung aller Änderungen die beim Erstellen des Ordners Dinospiel vorgenommen wurden.
Dieser Ordner vereinbart alle Funktionen die wir bisher einzeln programmiert haben in das, was am Ende zum kompletten Spiel werden soll.  
Von nun an sollten Änderungen und neue Features an den Dateien in diesem Ordner vorgenommen werden.

- Alle noetigen Dateien, Header, und C-Programme des Standes 26 Juni 14:40 (commit cdbc1110554f) in den Ordner Dinospiel kopiert
	- Keine Änderungen vernommen an den Dateien in benny/ und philipp/

- Dinogame.c und game.h in Dinospiel.c und spiel.h umbenannt

## Änderungen in Dinospiel.c
- Alle #includes von Standardbibliotheken aus den Headern in Dinospiel.c verschoben
- #includes eigener Header in sinnvolle Reihenfolge gebracht
- Alle #defines aus den Headern in Dinospiel.c verschoben
- Deklarieren der Textur-Strukturen aus Dinospiel.c in texturenEinlesen.h verschoben

## Änderungen in der Main Funktion
- scores-Array deklariert und Highscoreliste eingelesen
- Loop mit switch case angelegt, der zwischen allen Programmteilen springen kann
	- Die Auswahl erfolgt aufgrund der return Werte der Funktionen, bzw durch feste Zuweisung nach Funktionen die nur ein logisches Ziel haben
	- Beispiel: spiel() kann als Rückgabewert 4, 5, oder 6 haben. Aber das Ziel nach scoreboardAnzeigen() ist immer 5

## Änderungen in Headern
- In hauptmenu.h passende return Werte eingetragen
- In score.h der Funktion scoreboardAnzeigen einen weiteren Parameter hinzugefügt, ob die Anzeige permanent sein soll oder nach Eingabe von ESC oder ENTER verschwinden soll

## To-Do
Was ist noch zu tun in Hinsicht auf das reibungslose Springen zwischen unterschiedlichen Programmteilen:
- in pause() die korrekten return Werte eintragen. Wenn etwas anderes als weiterspielen ausgewählt wurde: in spiel() das Spiel beenden und den return Wert von pause() weiterleiten
- Der Funktion spiel() einen Pointer auf die aktuelle Punktzahl übergeben
- in spiel() nach einem Game Over den Wert 4 zurückgeben
- Die Überschrift zu Beginn der Main Funktion ausgeben und alle anderen Funktionen in eigenem Fenstern laufen lassen, sodass sie nicht überschrieben wird

