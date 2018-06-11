/*Author: Benjamin Brandtner
 * Weird Syntax	 */

#include <stdio.h>
#include <ncurses.h>

int main (void)
{
	int i = 5;
	int eingabe=0;
		
	//Dekrementierender While Loop
	//Wird ausgeführt bis i=0, aber i wird danach noch einmal dekrementiert
	while(i--) 
	{
		printf("%i\n", i);
	}

	//Folgt nach einer Kontrollabfrage nur eine Anweisung, sind Klammern nicht nötig. Einrückung ist trotzdem möglich.
	if(i==-1) printf("i ist -1\n");
	if(i!=3)
		printf("i ist nicht 3\n");

	//Dies geht auch mit while, for, vielleicht anderem?
	for(i=0;i<3;i++) printf("%i. Schleifendurchlauf\n", i+1);
	while(i--) printf("Und wieder zurück\n");

	//Conditional Operator aka Ternary Operator aka ?: Operator
	//Das erste Argument ist ein Vergleich der mit TRUE oder FALSE beantwortet wird. Bei TRUE wird der erste Block ausgeführt, bei FALSE der zweite. 
	//expression ? Block1 : Block2
	
	i==-1 ? printf("i ist -1") : printf("i ist nicht -1");

	//Unerwartetes Verhalten: Manchmal ist es nötig den zweiten Block in Klammern zu schreiben:
	//i<0 ? i=1 : (i=5);
	//Erklärung: Letzte Antwort in: http://www.cplusplus.com/forum/beginner/134943/

	//Infinite Loops
	//while(1), while(true), for(;;)
	//Weiterführende Infos: https://stackoverflow.com/questions/20186809/endless-loop-in-c-c#20188551


	return 0;
}
