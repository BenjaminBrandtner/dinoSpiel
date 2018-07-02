/*Autor: Philipp Hägerich 
 * Das eigentliche Spiel */

struct pos_wolken 
{
	int y;
	int x;
	int textur_id;
};

struct pos_dino 
{
	int y;
};

struct pos_kaktus 
{
	int x;
	int textur_id;
};

#include"kollision.h"

//Prototypen
int verarbeiteSprung(int dinoY, int timer);
void zeigeGameover(int *punktzahl);

int spiel(int *punktzahl)
{
	struct tex_wolken wolken[3];
	struct tex_rest dino[2];
	struct tex_rest kaktus[3];
	struct pos_dino Pdino;
	struct pos_kaktus Pkaktus[3];
	struct pos_wolken poswolken[3];
	int i, fehler, j, index, sprungrytmus;
	int auswahl = 1;
	int sprungtimer=0;
	int wechsel = 100;
	char eingabe;
	char pfad[30];
	bool debuging_mode = false;
	bool kol = false;
	ESCDELAY = 50;
	
	einlesenWolken(&wolken[0],"texturen/wolken/wolken1.txt");
	einlesenWolken(&wolken[1],"texturen/wolken/wolken2.txt");
	einlesenWolken(&wolken[2],"texturen/wolken/wolken3.txt");
	
	einlesenTexturen(&dino[0],"texturen/dino/dino1.txt");
	einlesenTexturen(&dino[1],"texturen/dino/dino2.txt");
	
	einlesenTexturen(&kaktus[0],"texturen/kaktus/kaktus1.txt");
	einlesenTexturen(&kaktus[1],"texturen/kaktus/kaktus2.txt");
	einlesenTexturen(&kaktus[2],"texturen/kaktus/kaktus3.txt");
	
	
	*punktzahl = 0;
	Pdino.y = 320;
	
	//standart werte für struct
	for(i=0;i<3;i++)
	{
		poswolken[i].x = -3000;
		poswolken[i].textur_id = 0;
		
		Pkaktus[i].textur_id = 0;
		Pkaktus[i].x = -200;
	}
	
	srand(time(NULL));
	
	sprungtimer = -1;
	
	//Spielloop
	do
	{
		eingabe=getch();
		
		if(eingabe==KEY_ESC)
		{
			auswahl = zeigePause();
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
		
		if(sprungtimer<=0 && eingabe==' ' || eingabe==KEY_UP )
		{
			sprungtimer=600;
			sprungrytmus = 0;
		}
		
		erase();
		
		//rechne
		if(sprungtimer>=0)
		{
			if(sprungrytmus==2)
			{
				Pdino.y = verarbeiteSprung(Pdino.y/10, sprungtimer/10)*10;
				sprungrytmus = 0;
			}

			sprungtimer -= 7;
			sprungrytmus ++;
			}
		else if(sprungtimer<0)
		{
			Pdino.y = 320;
		}
		(*punktzahl)++;
		
		//Dino anzeigen
		if (wechsel <= 50 && sprungtimer < 0)
		{
			anzeigenTexturen(&dino[0], Pdino.y/10,10);
		}
		else
		{
			anzeigenTexturen(&dino[1], Pdino.y/10,10);
		} //end if
		
		if(wechsel == 0)
		{
			wechsel = 100;
		} //end if
		
		wechsel --;
		
		//katkeen anzeigen
		for(i=0;i<3;i++)
		{
			Pkaktus[i].x -= 1;
			
			if(debuging_mode)
			{
				mvprintw(0,0,"%i | %i | %i",Pkaktus[0].x,Pkaktus[1].x,Pkaktus[2].x);
			} //end if
			
			if(Pkaktus[i].x <= -300)
			{
				/*Diesee langen IFs sind nötig damit die kakteen nicht zu nah beieinander erscheinen*/
				if(0 == rand()%95 && i == 0 && (Pkaktus[2].x*10) <= ((COLS-60)*10) && (Pkaktus[1].x*10) <= ((COLS-60)*10))
				{
					Pkaktus[i].x = COLS+18;
					Pkaktus[i].textur_id = rand()%3;
				}
				else if(0 == rand()%95 && (Pkaktus[0].x*10) <= ((COLS-60)*10) && (Pkaktus[2].x*10) <= ((COLS-60)*10) && i == 1)
				{
					Pkaktus[i].x = COLS+18;
					Pkaktus[i].textur_id = rand()%3;
				}
				else if(0 == rand()%95 && (Pkaktus[1].x*10) <= ((COLS-60)*10) && (Pkaktus[0].x*10) <= ((COLS-60)*10) && i == 2)
				{
					Pkaktus[i].x = (COLS+18)*10;
					Pkaktus[i].textur_id = rand()%3;
				}//end if
			}//end if
			
			index = Pkaktus[i].textur_id;
			if(index<3&&index>= 0)
			{
				if(Pkaktus[i].x > -300)
				{
					anzeigenTexturen(&kaktus[index],32,Pkaktus[i].x);
				} //end if
			}
			else
			{
				printf("ERROR\n");
			}
			
			if((Pkaktus[i].x/10)<=40)
			{
				kol = kollision(Pdino.y/10, Pkaktus[i].x, dino[0],kaktus[Pkaktus[i].textur_id]);
			} //end if
			
		} //end for
		
		
		//wolken anzeigen
		for(i=0;i<3;i++)
		{
			
			poswolken[i].x -= 5; //enspricht einen -= 0.05
			if(poswolken[i].x <= -300)
			{
				if(0 == rand()%95)
				{
					poswolken[i].x = COLS*100;
					poswolken[i].y = rand()%16-15+20;
					poswolken[i].textur_id = rand()%3;
				}
			} //end if
			index = poswolken[i].textur_id;
			if(index<3&&index>= 0)
			{
				anzeigenWolken(&wolken[index],poswolken[i].y,poswolken[i].x/100);
			}
			else
			{
				printf("ERROR\n");
			}
			
		} //end for
		
		//Boden
		attron(A_REVERSE);
		for(j=0;j<COLS;j++)
		{
			mvprintw(50,j," ");
		}
		attroff(A_REVERSE);

		//Punktzahl
		mvprintw(0,COLS-14,"Score: %i", *punktzahl);
		
		refresh();
		
		fehler = usleep(1000);
		
		
	}while(auswahl==1&&!kol);
	
	clear();
	refresh();

	if(kol)
	{
		zeigeGameover(punktzahl);
		sleep(2);
		erase();
		refresh();
		return 4;
	}
	else
	{
		switch(auswahl)
		{
			case 2:
				return 5;
			break;
			case 3:
				return 6;
			break;
		}
	}
}


int verarbeiteSprung(int dinoY, int timer)
{
	if(timer<=60&&timer>=32)
	{
		(dinoY)--;
	}
	else if(timer<=28&&timer>=0)
	{
		(dinoY)++;
	}
	
	return dinoY;
}

void zeigeGameover(int *punktzahl)
{
	mvprintw(LINES/2,COLS/2-17,"Game Over! Erreichte Punktzahl: %i", *punktzahl);
	refresh();
}
