#include <ncurses.h>
#include "spheres.h"

void drawdebug(vect3 pos,int facing){
WINDOW *win =newwin(3,20,1,COLS-20-2);
box(win,0,0);
mvwprintw(win,1,2,"x=%i;y=%i;z=%i",pos.x,pos.y,pos.z);
wrefresh(win);
delwin(win);

win =newwin(3,17,4,COLS-17-2);
box(win,0,0);
mvwprintw(win,1,2,"facing: ");
switch(facing){
case FRONT:	wprintw(win,"FRONT");	break;
case BACK:	wprintw(win,"BACK");	break;
case LEFT:	wprintw(win,"LEFT");	break;
case RIGHT:	wprintw(win,"RIGHT");	break;
case UP:	wprintw(win,"UP");	break;
case DOWN:	wprintw(win,"DOWN");	break;
default:	break;}
wrefresh(win);
delwin(win);
return;}
