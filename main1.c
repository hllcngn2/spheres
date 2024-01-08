#include <ncurses.h>
#include <stdlib.h>//rand
#include <time.h>
#include "spheres.h"

int main(int ac, char **av){
initscr();
noecho(); cbreak(); curs_set(0);
start_color();
srand(time(NULL));

make_colors();
Flags f; f.debug =0;
int** scr =newscreen();
int*** map =newmap();

printw("\n\tDear darkmage,\n");getch();
test_colors(scr);dispscreen(scr);mvprintw(1,2,"colors test");getch();

vect3 pos =(vect3){WIDTH/2,HEIGHT/2,DEPTH/2};
int facing =FRONT;

//drawdotverticalcircle(map,10,20,x+35,y+14,z+10);
//vect3 maj={10,5,12}, min={10,10,10};
//drawdot3dellipse(map,10,(vect3){pos.x+35,pos.y+14,pos.z+10},maj,min);
//vect3 a={10,50,12}, b={10,10,80};
//drawdot3dcircle(map,10,(vect3){pos.x+35,pos.y+14,pos.z+10},10,a,b);
drawmanycircles(map,40,20);

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
case K_FACE_RIGHT:
case K_FACE_UP:
case K_FACE_DOWN:	turn(c,&facing);	break;
case K_DEBUG:		f.debug =(f.debug?0:1);	break;
default:	break;}

drawscreen(scr,map,pos,facing);
dispscreen(scr);
refresh();
if(f.debug) drawdebug(pos,facing);
}while((c=getch())!=K_QUIT);

freescreen(scr);
freemap(map);
endwin();	return 0;}
