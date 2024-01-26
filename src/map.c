#include <ncurses.h>//LINES/COLS,WINDOW
#include <stdlib.h>//malloc/free
#include "spheres.h"

int*** newmap(void){
int*** new =(int***)malloc(sizeof(int**)*DEPTH+1);
for(int z=0; z<=DEPTH; z++){
	new[z] =(int**)malloc(sizeof(int*)*HEIGHT+1);
	for(int y=0; y<=HEIGHT; y++)
		new[z][y] =(int*)calloc(WIDTH+1,sizeof(int));}
return new;}

void freemap(int*** map){
for(int z=0; z<DEPTH; z++){
	for(int y=0; y<HEIGHT; y++)
		free(map[z][y]);
	free(map[z]);}
free(map);	return;}
