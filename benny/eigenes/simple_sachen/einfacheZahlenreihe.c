/*Author: Benjamin Brandtner
Gibt aus 122333444455555 usw*/

#include <stdio.h>

int main (void)
{
	int i;
	int j;

	for(i=1;i<=20;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%i", i);
		}
		printf("\n");
	}

	return 0;
}//end main
