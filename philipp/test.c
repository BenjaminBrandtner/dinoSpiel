/*Autor: Philipp Hägerich 
Das eigentliche spiel für mehr bitte README.md lesen*/

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
#include<unistd.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include"texturenEinlesen.h"
#include"texturenAusgabe.h"
#include"pause.h"

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
	bool debuging_mode = false;
	ESCDELAY = 50;
	
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
	
	//standart Werte zuweisung
	
	Pdino.y = 32;
	
	//ncurses aktiviren und anpassen
	initscr();
	cbreak();
	curs_set(0);
	nodelay(stdscr,true);
	keypad(stdscr,true);
	
	//standart werte für struct
	for(i=0;i<3;i++)
	{
		poswolken[i].x = -30;
		poswolken[i].textur_id = 0;
		
		Pkaktus[i].textur_id = 0;
		Pkaktus[i].x = -20;
	}
	
	srand(time(NULL));
	
	sprungtimer = -1;
	
	do
	{
		eingabe=getch();
		
		if(eingabe==KEY_ESC)
		{
			zeigePause();
			refresh();
		}
		
		if(eingabe=='d')
		{
			if(!debuging_mode)
			{
				debuging_mode = true;
			}
			else
			{
				debuging_mode = false;
			}
		}
		
		if(eingabe==' ' && sprungtimer<=0)
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
		
		
		
		if (wechsel <= 50 && sprungtimer < 0)
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
			Pkaktus[i].x -= 0.3;
			
			if(debuging_mode)
			{
				mvprintw(0,0,"%f | %f | %f",Pkaktus[0].x,Pkaktus[1].x,Pkaktus[2].x);
			} //end if
			
			if(Pkaktus[i].x <= -30)
			{
				/*Diesee langne IFs sind nötig damit die kaktehen nicht zu nah beiernander erscheinen*/
				if(0 == rand()%95 && i == 0 && Pkaktus[2].x <= (COLS-40) && Pkaktus[1].x <= (COLS-40))
				{
					Pkaktus[i].x = COLS+18;
					Pkaktus[i].textur_id = rand()%3;
				}
				else if(0 == rand()%95 && Pkaktus[0].x <= (COLS-40) && Pkaktus[2].x <= (COLS-40) && i == 1)
				{
					Pkaktus[i].x = COLS+18;
					Pkaktus[i].textur_id = rand()%3;
				}
				else if(0 == rand()%95 && Pkaktus[1].x <= (COLS-40) && Pkaktus[0].x <= (COLS-40) && i == 2)
				{
					Pkaktus[i].x = COLS+18;
					Pkaktus[i].textur_id = rand()%3;
				}//end if
			}//end if
			
			index = Pkaktus[i].textur_id;
			if(index<3&&index>= 0)
			{
				if(Pkaktus[i].x > -30)
				{
					anzeigenTexturen(&kaktus[index],32,Pkaktus[i].x);
				} //end if
			}
			else
			{
				printf("ERROR\n");
			}
		} //end for
		
		
		//wolken anzeigen
		
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
		
		fehler = usleep(500);
		
		
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
