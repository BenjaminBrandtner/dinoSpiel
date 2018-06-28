//Nimmt die Zeile aus quelle, liest bis zum Zeichen definiert in trenner, schreibt das Ergebnis in ziel. 
//Rückgabewert ist die Anzahl an ausgelesenen Zeichen +1.
//Diese kann auf die Speicheradresse von quelle dazugerechnet werden, um mehrere Werte aus eine Zeile zu lesen
int split(char quelle[], char ziel[], char trenner)
{
	int i=0;
	while (quelle[i] != trenner && quelle[i] != '\0' && quelle[i] != '\n' && quelle[i] != '\r')
	{
		ziel[i] = quelle[i];
		i++;
	}
	ziel[i] = '\0';

	return ++i;
}

/*So würde ein Funktionsaufruf aussehen:
fopen()
while (fgets(eingeleseneZeile, 100, datei) != NULL)
{
	verschiebung = split (eingeleseneZeile, wert1, ';');
	verschiebung += split (eingeleseneZeile + verschiebung, wert2, ';'); //Hier wird einfach zu einer Speicheradresse addiert
//	... wert3
//	... wert4
//	je nachdem wie viele Werte in einer Zeile stehen
}
fclose();
*/
