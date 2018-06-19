

struct tex_wolken 
{
	char textur[5][28];
};

struct tex_rest 
{
	char textur[18][22];
};

struct ueberschrift 
{
	char textur[7][82];
};


struct pos_wolken {
	int y;
	float x;
	struct tex_wolken *textur;
};

#include<stdio.h>
#include<ncurses.h>
#include <unistd.h>
#include<stdbool.h>
#include<time.h>
#include"texturenEinlesen.h"
#include"texturenAusgabe.h"


int main(void)
{
	struct tex_wolken wolken;
	struct ueberschrift ueberschrift;
	struct pos_wolken poswolken[3];
	int i, fehler, j;
	char eingabe;
	
	einlesenWolken(&wolken,"texturen/wolken1.txt");
	einlesenUeberschrift(&ueberschrift,"texturen/ueberschrift.txt");
	
	initscr();
	cbreak();
	curs_set(0);
	nodelay(stdscr,true);
	
	for(i=0;i<3;i++)
	{
		poswolken[i].x = -30;
	}
	
	
	do
	{
		clear();
		
		anzeigenUeberschrift(&ueberschrift,5,COLS/2-41);
		
		for(i=0;i<3;i++)
		{
			poswolken[i].x -= 0.5;
			if(poswolken[i].x <= -30)
			{
				srand(time(NULL));
				if(0 == rand()%3) //
				{
					poswolken[i].x = COLS;
					poswolken[i].y = rand()%10-5+20;
					poswolken[i].textur = &wolken;
				}
			} //end if
			anzeigenWolken(poswolken[i].textur,poswolken[i].y,poswolken[i].x);
		} //end for
		
		
		
		
		attron(A_REVERSE);
		for(j=0;j<COLS;j++)
		{
			mvprintw(50,j," ");
		}
		attroff(A_REVERSE);
		
		refresh();
		fehler = usleep(1000);
		
		
	}while((eingabe=getch())!='q');
	
	
	endwin();
	
	return 0;
}