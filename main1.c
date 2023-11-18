#include <ncurses.h>
#include "spheres.h"

int main(int ac, char **av){
initscr();
noecho(); cbreak(); curs_set(0);
start_color();

make_colors();
Flags f; f.debug =0;
int** scr =newscreen();
int*** map =newmap();

printw("\n\tDear darkmage,\n");getch();
test_colors(scr);dispscreen(scr);mvprintw(1,2,"colors test");getch();

drawdotellipse(map,10,20,35,14,10);

int x =0;
int y =0;
int z =0;
int facing =FRONT;

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
case K_BACKWARD:	movement(c,&x,&y,&z);	break;
case K_DEBUG:		f.debug =(f.debug?0:1);	break;
default:	break;}

drawscreen(scr,map,x,y,z,facing);
dispscreen(scr);
refresh();
if(f.debug) drawdebug(x,y,z);
}while((c=getch())!=K_QUIT);

freescreen(scr);
freemap(map);
endwin();	return 0;}
