

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
	int textur_id;
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
	struct tex_wolken wolken[3];
	struct ueberschrift ueberschrift;
	struct pos_wolken poswolken[3];
	int i, fehler, j;
	char eingabe;
	char pfad[30];
	
	einlesenWolken(&wolken[0],"texturen/wolken/wolken1.txt");
	einlesenWolken(&wolken[1],"texturen/wolken/wolken2.txt");
	einlesenWolken(&wolken[2],"texturen/wolken/wolken3.txt");
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
		srand(time(NULL));
		for(i=0;i<3;i++)
		{
			
			poswolken[i].x -= 0.1;
			if(poswolken[i].x <= -30)
			{
				if(0 == rand()%2)
				{
					poswolken[i].x = COLS;
					poswolken[i].y = rand()%16-15+20;
					poswolken[i].textur_id = rand()%3;
				}
			} //end if
			anzeigenWolken(&wolken[poswolken[i].textur_id],poswolken[i].y,poswolken[i].x);
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