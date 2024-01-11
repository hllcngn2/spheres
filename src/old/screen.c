#include <ncurses.h>//LINES/COLS,WINDOW
#include <stdlib.h>//malloc/free
#include <string.h>//memcpy
#include "spheres.h"

screen newscreen(void){
screen new =(screen)malloc(sizeof(row)*LINES);
for(int l=0; l<LINES; l++)
	new[l] =(row)malloc(sizeof(pixel)*COLS);
for(int p=0; p<COLS; p++)
	new[0][p] =(pixel){(int)' ',0};
for(int l=1; l<LINES; l++)
	memcpy((void*)new[l],(void*)new[0], COLS*sizeof(pixel));
return new;}

void freescreen(screen s){
for(int r=0; r<LINES; r++) free(s[r]);
free(s);	return;}


void dispscreen(screen scr){
move(0,0);
for(int l=0; l<LINES; l++)
	for(int p=0; p<COLS; p++){
		attron(COLOR_PAIR(scr[l][p].color));
		addch(scr[l][p].c);
		attroff(COLOR_PAIR(scr[l][p].color));}
attron(COLOR_PAIR(0));	return;}
