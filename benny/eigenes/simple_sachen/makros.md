# Erklärung von Makros
## Symbolische Konstanten
Mit `#define BEZEICHNER Ersatz` kann man eine symbolische Konstante deklarieren. Während der Übersetzung des Source-Codes wird der Compiler jedes vorkommen von BEZEICHNER durch Ersatz ersetzen. (Außer in Strings)  
Aus
```C
#define PI 3.141592653
#define ANSPRACHE "Sehr geehrte Damen und Herren: "

int main (void)
{
	area=radius*PI;
	printf(ANSPRACHE"Der Flächeninhalt beträgt %f", area);
}
```
wird
```C
int main (void)
{
	area=radius*3.141592653;
	printf("Sehr geehrte Damen und Herren: ""Der Flächeninhalt beträgt %f", area);
}
```
Zwei nebeneinanderstehende Strings werden dann vom Compiler zusammengefügt.

Wenn numerische Konstanten benötigt werden, sollte man anstatt von #define besser eine normale konstante Variable im Programm deklarieren. Das hat den Vorteil, dass solche Konstanten einen Datentyp haben und dem Compiler ein besseres Optimieren des Codes erlauben.
```C
int main (void)
{
	const float PI = 3.141592653;
}
```

## Makrofuntkionen aka parametirisierte Makros
Ein `#define BEZEICHNER(x) Ersatz`-Makro dass im Programmcode mit `BEZEICHNER(foo)` steht, wird vom Compiler so ersetzt, wie Ersatz es festlegt. Am einfachsten lässt es sich an einem Beispiel nachvollziehen.  
Aus
```C
#define KLEINER_100(x) ((x) < 100)

int main (void)
{
	if(KLEINER_100(meineZahl))
	{
		//Anweisungen
	}
}
```
wird
```C
int main (void)
{
	if(foo<100)
	{
		//Anweisungen
	}
}
```
Makrofunktionen können recht komplex sein. Sie können mehrere Argumente annehmen und bei der Definierung über mehrere Zeilen erstrecken. Dazu muss jede Zeile mit einem \ abgeschlossen werden. Für weiterführende Beispiele am Besten in die Quellen schauen.  
Da sie keine echten Funktionsaufrufe sind, müssen Ihnen keine Pointer übergeben werden um Variablen zu ändern. Aus der curses-Bibliothek gibt es z.B die Makrofunktion getyx die so aufgerufen wird: `getyx(stdscr, col, row)`. Sie schreibt in col und row die aktuelle Position des Cursors.

# Quellen:
- http://openbook.rheinwerk-verlag.de/c_von_a_bis_z/010_c_praeprozessor_002.htm

- http://www.c-howto.de/tutorial/praeprozessor/makros/