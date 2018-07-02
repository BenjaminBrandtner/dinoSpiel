/*Autor: Philipp Hägerich 
List die passenden texturen ein und speichert sie in einen Struct*/

void einlesenTexturen(struct tex_rest *textur, char pfad[])
{
	FILE *in;
	char temp[25];
	int i,j;
	
	in = fopen(pfad,"r");
	
	if(in == NULL)
	{
		printf("\n\nERROR 404\n\n");
	} //end if

	for(i=0;i<18;i++)
	{
		fgets(temp,25,in);
		
		for(j=0;j<21;j++)
		{
			(*textur).textur[i][j] = temp [j];
		}
	}
	
	return;
}

void einlesenWolken(struct tex_wolken *wolo, char pfad[])
{
	FILE *in;
	char temp[30];
	int i,j;
	
	
	in = fopen(pfad,"r");
	
	if(in == NULL)
	{
		printf("\n\nERROR 404\n\n");
	} //end if

	for(i=0;i<5;i++)
	{
		fgets(temp,30,in);
		
		for(j=0;j<28;j++)
		{
			(*wolo).textur[i][j] = temp[j];
		}
	}
	return;
}

void einlesenUeberschrift(struct ueberschrift *textur, char pfad[])
{
	FILE *in;
	char temp[85];
	int i,j;
	
	
	in = fopen(pfad,"r");
	
	if(in == NULL)
	{
		printf("\n\nERROR 404\n\n");
	} //end if

	for(i=0;i<7;i++)
	{
		fgets(temp,85,in);
		
		for(j=0;j<82;j++)
		{
			(*textur).textur[i][j] = temp[j];
		}
	}
	return;
}
