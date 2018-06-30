/*Autor: Philipp Hägerich 
Gibt ales an bestimmten koordinaten aus*/

void anzeigenTexturen(struct tex_rest textur, int y, int x)
{
	int i;
	int j;
	attron(A_REVERSE);
	for (i = 0; i < 18; i++)
	{
		for (j = 0; j < 21; j++)
		{
			if(textur.textur[i][j]=='#')
			{
				mvprintw(y+i,x+j," ");
			}//end if
		} //end for
	} //end for
	attroff(A_REVERSE);
	return;
}

void anzeigenWolken(struct tex_wolken textur, int y, int x)
{
	int i;
	int j;
	attron(A_REVERSE);
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 18; j++)
		{
			if(textur.textur[i][j]=='#')
			{
				
				mvprintw(y+i,x+j," ");
				
			} //end if
		} //end for
	} //end for
	attroff(A_REVERSE);
	return;
}

void anzeigenUeberschrift(struct ueberschrift *textur, int y, int x)
{
	int i;
	int j;
	
	start_color();
	init_pair(1,COLOR_GREEN,COLOR_BLACK);
	
	attron(A_REVERSE);
	attron(COLOR_PAIR(1));
	
	for (i = 0; i < 7; i++)
	{
		for (j = 0; j < 81; j++)
		{
			if((*textur).textur[i][j]=='#')
			{
				
				mvprintw(y+i,x+j," ");
				
			} //end if
		} //end for
	} //end for
	
	attroff(A_REVERSE);
	attroff(COLOR_PAIR(1));
	
	return;
}