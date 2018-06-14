/*Autor: Philipp Hägerich 
List die passenden texturen ein und speichert sie in einen Struct*/

#include<stdlib.h>


void einlesenTexturen(struct *tex_rest[], char pfad[], int index)
{
	FILE *in;
	char temp[20];
	int i,j;
	
	in = fopen(pfad,"r");

	for(i=0;i<21;i++)
	{
		fgets(temp,19,in);
		
		for(j=0;j<18;j++)
		{
			(*tex_rest)[index].textur[i][j] = temp [j];
		}
	}
}
