#include <ncurses.h>
#include "spheres.h"

void drawdebug(vect3 pos,int facing){
WINDOW *win =newwin(4,21,0,COLS-21-1);
box(win,0,0);
mvwprintw(win,1,2,"x:%i y:%i z:%i",pos.x,pos.y,pos.z);
mvwprintw(win,2,2,"facing: ");
switch(facing){
case FRONT:	wprintw(win,"FRONT");	break;
case BACK:	wprintw(win,"BACK");	break;
case LEFT:	wprintw(win,"LEFT");	break;
case RIGHT:	wprintw(win,"RIGHT");	break;
default:	break;}
wrefresh(win);
delwin(win);
return;}
