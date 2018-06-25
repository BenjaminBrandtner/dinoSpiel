

struct tex_wolken 
{
	char textur[5][28];
};

struct tex_rest 
{
	char textur[18][21];
};

struct ueberschrift 
{
	char textur[7][82];
};


struct pos_wolken 
{
	int y;
	float x;
	int textur_id;
};

struct pos_dino 
{
	float y;
	float x;
};

struct pos_kaktus 
{
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

int verarbeiteSprung(int dinoY, float *timer);


int main(void)
{
	struct tex_wolken wolken[3];
	struct tex_rest dino[2];
	struct tex_rest kaktus[3];
	struct pos_dino Pdino;
	struct pos_kaktus Pkaktus[3];
	struct ueberschrift ueberschrift;
	struct pos_wolken poswolken[3];
	int i, fehler, j, index, ganzzahl;
	float sprungtimer=0;
	int wechsel = 100;
	char eingabe;
	char pfad[30];
	
	//texturen einlesen
	
	einlesenWolken(&wolken[0],"texturen/wolken/wolken1.txt");
	einlesenWolken(&wolken[1],"texturen/wolken/wolken2.txt");
	einlesenWolken(&wolken[2],"texturen/wolken/wolken3.txt");
	
	einlesenTexturen(&dino[0],"texturen/dino/dino1.txt");
	einlesenTexturen(&dino[1],"texturen/dino/dino2.txt");
	
	einlesenTexturen(&kaktus[0],"texturen/kaktus/kaktus1.txt");
	einlesenTexturen(&kaktus[1],"texturen/kaktus/kaktus2.txt");
	einlesenTexturen(&kaktus[2],"texturen/kaktus/kaktus3.txt");
	
	
	einlesenUeberschrift(&ueberschrift,"texturen/ueberschrift.txt");
	
	//standart were zuweisung
	
	Pdino.y = 32;
	
	initscr();
	cbreak();
	curs_set(0);
	nodelay(stdscr,true);
	keypad(stdscr,true);
	
	for(i=0;i<3;i++)
	{
		poswolken[i].x = -30;
		poswolken[i].textur_id = 0;
		
		Pkaktus[i].textur_id = 0;
		Pkaktus[i].x = COLS +18;
	}
	
	srand(time(NULL));
	
	sprungtimer = -1;
	
	do
	{
		eingabe=getch();
		
		if(eingabe=='w' && sprungtimer<=0)
		{
			sprungtimer=40;
		}
		
		erase();
		
		anzeigenUeberschrift(&ueberschrift,5,COLS/2-41);

		//rechne
		if(sprungtimer>=0)
		{
			ganzzahl = sprungtimer;
			if((sprungtimer-ganzzahl)==0)
			{
				Pdino.y = verarbeiteSprung(Pdino.y, &sprungtimer);
			}
			sprungtimer -= 0.25; 
		}
		else if(sprungtimer<0)
		{
			Pdino.y = 32;
		}
		
		
		
		if (wechsel <= 50)
		{
			anzeigenTexturen(&dino[0], Pdino.y,10);
		}
		else
		{
			anzeigenTexturen(&dino[1], Pdino.y,10);
		} //end if
		
		if(wechsel == 0)
		{
			wechsel = 100;
		} //ennd if
		
		wechsel --;
		
		//katkehen anzeigen
		
		
		
		for(i=0;i<3;i++)
		{
			
			poswolken[i].x -= 0.05;
			if(poswolken[i].x <= -30)
			{
				if(0 == rand()%95)
				{
					poswolken[i].x = COLS;
					poswolken[i].y = rand()%16-15+20;
					poswolken[i].textur_id = rand()%3;
				}
			} //end if
			index = poswolken[i].textur_id;
			if(index<3&&index>= 0)
			{
				anzeigenWolken(&wolken[index],poswolken[i].y,poswolken[i].x);
			}
			else
			{
				printf("ERROR\n");
			}
			
		} //end for
		
		attron(A_REVERSE);
		
		for(j=0;j<COLS;j++)
		{
			mvprintw(50,j," ");
		}
		attroff(A_REVERSE);
		
		refresh();
		
		fehler = usleep(1000);
		
		
	}while(eingabe!='q');
	
	
	endwin();
	
	return 0;
}


int verarbeiteSprung(int dinoY, float *timer)
{
	if(*timer<=40&&*timer>=22)
	{
		(dinoY)--;
	}
	else if(*timer<=18&&*timer>=0)
	{
		(dinoY)++;
	}
	
	return dinoY;
}
