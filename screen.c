#include <ncurses.h>//LINES/COLS,WINDOW
#include <stdlib.h>//malloc/free
#include <string.h>//memcpy
#include "spheres.h"

int** newscreen(void){
int** new =(int**)malloc(sizeof(int*)*LINES);
for(int y=0; y<LINES; y++)
	new[y] =(int*)calloc(COLS/2,sizeof(int));
return new;}

void freescreen(int** scr){
for(int y=0; y<LINES; y++) free(scr[y]);
free(scr);	return;}

void drawscreen(int** scr,int*** map,int x,int y,int z,int facing){
//FRONT
for(int yy=0; yy<LINES; yy++)
	for(int xx=0; xx<COLS/2; xx++){
		int zz; for(zz=z; zz<DEPTH-1 && !map[zz][y+yy][x+xx]; zz++);
		scr[yy][xx] =map[zz][y+yy][x+xx];}
return;}

void dispscreen(int** scr){
for(int y=0; y<LINES; y++){
	move(y,0);
	for(int x=0; x<COLS/2; x++){
		attron(COLOR_PAIR(scr[y][x]));
		addch(' ');addch(' ');
		attroff(COLOR_PAIR(scr[y][x]));}}
attron(COLOR_PAIR(0));	return;}
