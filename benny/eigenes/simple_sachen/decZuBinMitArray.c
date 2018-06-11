/*Author: Benjamin Brandtner
	Programm wandelt eine Dezimalzahl zu einer Binärzahl in einem 8-bit Array */

#include<stdio.h>

int main (void) 
{
	int decimalNumber;
	int decimalNumberCopy;
	int binaryNumber[8];
	int i;
	
	printf("Dezimalzahl eingeben: ");
	scanf("%i", &decimalNumber);
	decimalNumberCopy=decimalNumber;

	for(i=7;i>=0;i--)
	{
		binaryNumber[i]=decimalNumber%2;
		decimalNumber=decimalNumber/2;
	}
	
	printf("%i ist folgendes in Binär: ", decimalNumberCopy);
	for(i=0;i<8;i++)
	{
		printf("%i", binaryNumber[i]);
	}
	printf("\n");

}//end main
