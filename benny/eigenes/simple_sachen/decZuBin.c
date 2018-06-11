/*Author: Benjamin Brandtner
	Programm wandelt eine Dezimalzahl zu einer Binärzahl*/

#include<stdio.h>

int main (void) 
{
	int decimalNumber;
	int decimalNumberCopy;
	int binaryNumber=0;
	int stelle=1;
	int i;
	
	printf("Dezimalzahl eingeben: ");
	scanf("%i", &decimalNumber);
	decimalNumberCopy=decimalNumber;

	for(i=0;i<8;i++)
	{
		binaryNumber+=decimalNumber%2*stelle;
		decimalNumber=decimalNumber/2;
		stelle*=10;
	}
	
	printf("%i in Binär ist %i\n", decimalNumberCopy, binaryNumber);

}//end main
