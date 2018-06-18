/*Autor: Philipp Hägerich 
Gibt ales an bestimmten koordinaten aus*/

void anzeigenTexturen(struct tex_rest *textur, int y, int x)
{
	int i;
	int j;
	
	for (i = 0; i < 18; i++)
	{
		for (j = 0; j < 21; j++)
		{
			if((*textur).textur[i][j]=='#')
			{
				attron(A_REVERSE);
				mvprintw(y+i,x+j," ");
				attroff(A_REVERSE);
			}
			else
			{
				mvprintw(y+i,x+j," ");
			} //end if
		} //end for
	} //end for
	return;
}

void anzeigenWolken(struct tex_wolken *textur, int y, int x)
{
	int i;
	int j;
	
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 28; j++)
		{
			if((*textur).textur[i][j]=='#')
			{
				attron(A_REVERSE);
				mvprintw(y+i,x+j," ");
				attroff(A_REVERSE);
			}
			else
			{
				mvprintw(y+i,x+j," ");
			} //end if
		} //end for
	} //end for
	return;
}