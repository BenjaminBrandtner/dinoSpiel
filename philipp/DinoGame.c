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

#include<stdio.h>
#include<ncurses.h>
#include<unistd.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include"texturenEinlesen.h"
#include"texturenAusgabe.h"
#include"game.h"


int main(void)
{
	struct tex_wolken wolken[3];
	struct tex_rest dino[2];
	struct tex_rest kaktus[3];
	struct ueberschrift ueberschrift;
	int auswahl;
	
	//texturen einlesen
	
	einlesenWolken(&wolken[0],"texturen/wolken/wolken1.txt");
	einlesenWolken(&wolken[1],"texturen/wolken/wolken2.txt");
	einlesenWolken(&wolken[2],"texturen/wolken/wolken3.txt");
	
	einlesenTexturen(&dino[0],"texturen/dino/dino1.txt");
	einlesenTexturen(&dino[1],"texturen/dino/dino2.txt");
	
	einlesenTexturen(&kaktus[0],"texturen/kaktus/kaktus1.txt");
	einlesenTexturen(&kaktus[1],"texturen/kaktus/kaktus2.txt");
	einlesenTexturen(&kaktus[2],"texturen/kaktus/kaktus3.txt");
	
	
	//einlesenUeberschrift(&ueberschrift,"texturen/ueberschrift.txt");
	
	//ncurses aktiviren und anpassen
	initscr();
	cbreak();
	curs_set(0);
	nodelay(stdscr,true);
	keypad(stdscr,true);
	
	auswahl = game(dino,kaktus,wolken);
	
	endwin();
	
	return 0;
}