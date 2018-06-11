/*Author: Benjamin Brandtner
	Erstellt ein Baum-Sweet Sequenz von 0 bis gewünschte Zahl
	Der Baum-Sweet Wert einer Zahl ist 0, wenn die binäre Repräsentation der Zahl eine Sequenz an Nullern ungerader Länge hat, ansonsten 1
	4=bin100->1
	5=bin101->0
	*/

#include <stdio.h>

int main (void)
{
	int decimalNumber;
	int decimalNumberCopy;
	int binaryNumber[8];
	int i;

	int ende;
	int konsekutiveNullen[8]={0};
	int j=0;
	int baumSweetWert;

	printf("Gewünschte letzte Zahl eingeben: ");
	scanf("%i", &ende);
	printf("Baum-Sweet Werte von Null bis %i:\n", ende);

	for(decimalNumber=0;decimalNumber<=ende;decimalNumber++)
	{
		
		//Wandle in Binär-Array um
		decimalNumberCopy=decimalNumber;
		for(i=7;i>=0;i--)
		{
			binaryNumber[i]=decimalNumberCopy%2;
			decimalNumberCopy=decimalNumberCopy/2;
		}
		
		//überprüfe Baum-Sweet Ziffer
		baumSweetWert=1;
		j=0;
		for(i=0;i<8;i++)
		{
			if(binaryNumber[i]==0)
			{
				konsekutiveNullen[j]++;
			}
			else
			{
				j++;
			}
		}
		for(i=1;i<8;i++)
		{
			if(konsekutiveNullen[i]%2==1)
			{
				baumSweetWert=0;
			}
			konsekutiveNullen[i]=0; //reset Array für den nächsten Durchlauf
		}

		printf("%i, ", baumSweetWert);
	}

}//end main
