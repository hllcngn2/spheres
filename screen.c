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

void drawscreen(int** scr,int*** map,vect3 pos,int facing){
switch(facing){
case FRONT:
	for(int yy=0; yy<LINES; yy++)
	for(int xx=0; xx<COLS/2; xx++){
		int zz;
		for(zz=pos.z;zz<DEPTH-1&&!map[zz][pos.y+yy][pos.x+xx];zz++);
		scr[yy][xx] =map[zz][pos.y+yy][pos.x+xx];}	break;
case BACK:
	for(int yy=0; yy<LINES; yy++)
	for(int xx=0; xx<COLS/2; xx++){
		int zz;
		for(zz=pos.z;zz>1&&!map[zz][pos.y+yy][pos.x+xx];zz--);
		scr[yy][xx] =map[zz][pos.y+yy][pos.x+xx];}	break;
case LEFT:
	/*
todo: change coordinates to exact ship location
			adjust displaying
			make temp variables coherent to what they actually represent
	for(int yy=0; yy<LINES; yy++)
	for(int xx=0; xx<COLS/2; xx++){
		int zz;
		for(zz=pos.x;zz>1&&!map[pos.z+][pos.y+yy][pos.x+xx];zz--);
		scr[yy][xx] =map[zz][pos.y+yy][pos.x+xx];}	break;
	*/
case RIGHT:
case UP:
case DOWN:
default:	break;}
return;}

void dispscreen(int** scr){
for(int y=0; y<LINES; y++){
	move(y,0);
	for(int x=0; x<COLS/2; x++){
		attron(COLOR_PAIR(scr[y][x]));
		addch(' ');addch(' ');
		attroff(COLOR_PAIR(scr[y][x]));}}
attron(COLOR_PAIR(0));	return;}
