#include <ncurses.h>
#include <stdlib.h>//rand
#include <time.h>
#include "spheres.h"

int main(int ac, char **av){
srand(time(NULL));
initscr();
noecho(); cbreak(); curs_set(0);
start_color();

make_colors();
int** scr =newscreen();

printw("\n\tDear darkmage,\n");getch();
test_colors(scr);dispscreen(scr);mvprintw(1,2,"colors test");getch();

char*** map =newmap();
drawmanyspheres(map,SPHERES_COUNT);

vect3 pos =(vect3){WIDTH/2,HEIGHT/2,DEPTH/2};
int facing =FRONT;

Flags f; f.debug =0;

char c=0; do{
switch(c){
case K_LEFT:
case K_RIGHT:
case K_UP:
case K_DOWN:
case K_UP_LEFT:
case K_UP_RIGHT:
case K_DOWN_LEFT:
case K_DOWN_RIGHT:
case K_FORWARD:
case K_BACKWARD:	movement(c,&pos);	break;
case K_FACE_FRONT:
case K_FACE_BACK:
case K_FACE_LEFT:
case K_FACE_RIGHT:	turn(c,&facing);	break;
case K_DEBUG:		f.debug =(f.debug?0:1);	break;
default:	break;}

drawscreen(scr,map,pos,facing);
dispscreen(scr); refresh();
if(f.debug) drawdebug(pos,facing);
}while((c=getch())!=K_QUIT);

freescreen(scr);
freemap(map);
endwin();	return 0;}
