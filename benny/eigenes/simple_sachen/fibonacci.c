/*Author: Benjamin Brandtner
	Gibt Fibonacci Sequenz bis 255 aus*/

#include <stdio.h>

int main (void)
{
	int x=0;
	int y=1;

	do
	{
		y=y+x;
		printf("%i\n", x);
		printf("%i\n", y);
		x=x+y;

	}while(x<255);

	return 0;
}//end main
