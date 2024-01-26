#include <ncurses.h>//LINES/COLS,WINDOW
#include <stdlib.h>//malloc/free
#include "spheres.h"

int** newscreen(void){
int** new =(int**)malloc(sizeof(int*)*LINES);
for(int y=0; y<LINES; y++)
	new[y] =(int*)calloc(COLS/2,sizeof(int));
return new;}

void freescreen(int** scr){
for(int y=0; y<LINES; y++)
	free(scr[y]);
free(scr);	return;}

void dispscreen(int** scr){
for(int y=0; y<LINES; y++){
	move(y,0);
	for(int x=0; x<COLS/2; x++){
		attron(COLOR_PAIR(scr[y][x]));
		addch(' ');addch(' ');
		attroff(COLOR_PAIR(scr[y][x]));}}
attron(COLOR_PAIR(0));	return;}


void drawscreen(int** scr,int*** map,vect3 pos,int facing){
switch(facing){
case FRONT:
/*
	for(int yy=-LINES/2; yy<(LINES+1)/2-1; yy++)
	for(int xx=-COLS/4; xx<(COLS+2)/4-1; xx++){
		int zz; for(zz=0;
			zz <HORIZON && zz <DEPTH-pos.z
			&&!map[pos.z+zz][pos.y+yy][pos.x+xx];
				zz++);
		scr[yy+LINES/2][xx+COLS/4] =map[pos.z+zz][pos.y+yy][pos.x+xx];}
*/
	//TODO: account for lines outside of the map?
	int yy=-LINES/2;
	for (yy; pos.y+yy<0; yy++) 
		for (int x=-COLS/4; x<(COLS+2)/4-1; x++)
			scr[yy+LINES/2][x+COLS/4] =0;
	for (yy; pos.y+yy<HEIGHT &&yy<(LINES+1)/2-1; yy++){
		int xx=-COLS/4;
		for (xx; pos.x+xx<0; xx++)
			scr[yy+LINES/2][xx+COLS/4] =0;
		for (xx; pos.x+xx<WIDTH &&xx<(COLS+2)/4-1; xx++){
			int zz; for(zz=0;
				zz <HORIZON && zz <DEPTH-pos.z
				&&!map[pos.z+zz][pos.y+yy][pos.x+xx];
					zz++);
			scr[yy+LINES/2][xx+COLS/4]
				=map[pos.z+zz][pos.y+yy][pos.x+xx];}
		for (xx; xx<(COLS+2)/4-1; xx++)
			scr[yy+LINES/2][xx+COLS/4] =0;}
	for (yy; yy<(LINES+1)/2-1; yy++)
		for (int x=-COLS/4; x<(COLS+2)/4-1; x++)
			scr[yy+LINES/2][x+COLS/4] =0;
/*
	for(int xx=-COLS/4; xx<(COLS+2)/4-1; xx++){
		if (pos.y+yy<0)
			if (pos.x+xx<0)
			else if (pos.x+xx>WIDTH)
		else if (pos.y+yy>HEIGHT)
			if (pos.x+xx<0)
			else if (pos.x+xx>WIDTH)
*/
	break;
case BACK:
	for(int yy=-LINES/2; yy<(LINES+1)/2-1; yy++)
	for(int xx=-COLS/4; xx<(COLS+2)/4-1; xx++){
		int zz; for(zz=0;
			zz <HORIZON && zz <pos.z
			&&!map[pos.z-zz][pos.y+yy][pos.x+xx];
				zz++);
		scr[yy+LINES/2][xx+COLS/4] =map[pos.z-zz][pos.y+yy][pos.x+xx];}
	break;
case LEFT:
	for(int yy=-LINES/2; yy<(LINES+1)/2-1; yy++)
	for(int zz=-COLS/4; zz<(COLS+2)/4-1; zz++){
		int xx; for(xx=0;
			xx <HORIZON && xx <pos.x
			&&!map[pos.z+zz][pos.y+yy][pos.x-xx];
				xx++);
		scr[yy+LINES/2][zz+COLS/4] =map[pos.z+zz][pos.y+yy][pos.x-xx];}
	break;
case RIGHT:
	for(int yy=-LINES/2; yy<(LINES+1)/2-1; yy++)
	for(int zz=-COLS/4; zz<(COLS+2)/4-1; zz++){
		int xx; for(xx=0;
			xx <HORIZON && xx <WIDTH-pos.x
			&&!map[pos.z+zz][pos.y+yy][pos.x+xx];
				xx++);
		scr[yy+LINES/2][zz+COLS/4] =map[pos.z+zz][pos.y+yy][pos.x+xx];}
	break;
case UP:
case DOWN:
default:	break;}
return;}
