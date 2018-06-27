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

//Prototypen
int verarbeiteSprung(int dinoY, int timer);

int spiel(struct tex_rest dino[], struct tex_rest kaktus[],struct tex_wolken wolken[])
{
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
		
		if(eingabe==' ' && sprungtimer<=0)
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
		} //ennd if
		
		wechsel --;
		
		//katkehen anzeigen
		
		for(i=0;i<3;i++)
		{
			Pkaktus[i].x -= 1;
			
			if(debuging_mode)
			{
				mvprintw(0,0,"%i | %i | %i",Pkaktus[0].x,Pkaktus[1].x,Pkaktus[2].x);
			} //end if
			
			if(Pkaktus[i].x <= -300)
			{
				/*Diesee langne IFs sind nötig damit die kaktehen nicht zu nah beiernander erscheinen*/
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
		
		attron(A_REVERSE);
		
		for(j=0;j<COLS;j++)
		{
			mvprintw(50,j," ");
		}
		attroff(A_REVERSE);
		
		refresh();
		
		fehler = usleep(1000);
		
		
	}while(eingabe!='q'&&auswahl==1);
	
	
	endwin();
	if(auswahl==2)
	{
		clear();
		return 5;
	}
	else if(auswahl==3)
	{
		return 6;
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
