/*Author: Benjamin Brandtner
Gibt einen eingegeben String ohne Selbslaute aus*/

#include <stdio.h>

int main (void)
{
	char eingabe[200];
	char eingabeStripped[200];
	char selbstlaute[200];
	int i=0;
	int j=0;

	printf("Bitte geben Sie etwas ein: ");
	scanf("%s", eingabe);

	while(eingabe[i]!='\0')
	{
		if(eingabe[i]=='a' || eingabe[i]=='e' || eingabe[i]=='i' || eingabe[i]=='o' || eingabe[i]=='u')
		{
			selbstlaute[j]=eingabe[i];
			j++;
			eingabe[i]=0;
		}
		else
		{
			printf("%c", eingabe[i]);
		}

		i++;
	}
	selbstlaute[j]='\0';

	printf("\n%s\n", selbstlaute);
}
