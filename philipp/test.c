

struct tex_wolken 
{
	char textur[5][28];
};

struct tex_rest 
{
	char textur[5][28];
};

#include<stdio.h>
#include<ncurses.h>
#include <unistd.h>
#include<stdbool.h>
#include"texturenEinlesen.h"
#include"texturenAusgabe.h"


int main(void)
{
	struct tex_wolken wolo;
	int i, fehler;
	char eingabe;
	
	einlesenWolken(&wolo,"texturen/wolken1.txt");
	
	initscr();
	cbreak();
	nodelay(stdscr,true);
	
	i = -10;
	
	do
	{
		anzeigenWolken(&wolo,20,i);
		move(0,0);
		refresh();
		fehler = usleep(10);
		i++;
		if(i == 150)
		{
			i = -10;
		} //end if
	}while((eingabe=getch())!='q');
	
	
	endwin();
	
	return 0;
}