#include <ncurses.h>//LINES/COLS,WINDOW
#include <stdlib.h>//malloc/free
#include "spheres.h"

char*** newmap(void){
char*** new =(char***)malloc(sizeof(char**)*DEPTH+1);
for(int z=0; z<=DEPTH; z++){
	new[z] =(char**)malloc(sizeof(char*)*HEIGHT+1);
	for(int y=0; y<=HEIGHT; y++)
		new[z][y] =(char*)calloc(WIDTH+1,sizeof(char));}
return new;}

void freemap(char*** map){
for(int z=0; z<DEPTH; z++){
	for(int y=0; y<HEIGHT; y++)
		free(map[z][y]);
	free(map[z]);}
free(map);	return;}
